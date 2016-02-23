#include <QtWidgets>
#include "widgetgallery.h"
#include "ui_widgetgallery.h"
#include "norwegianwoodstyle.h"

WidgetGallery::WidgetGallery(QWidget *parent) :
    QDialog(parent)/*,
    ui(new Ui::WidgetGallery)*/
{
    //ui->setupUi(this);
    originalPalette = QApplication::palette();  // Returns the default application palette, contains color groups for each widget(Active, Disabled, Inactive)

    styleComboBox = new QComboBox; // Combined button and popup list Widget
    styleComboBox->addItem("NorwegianWood"); // Add to the popup list
    styleComboBox->addItems(QStyleFactory::keys()); // QStyle class is an abstract base class that encapsulates the look and feel of the GUI, QStyleFactory creates a QStyle object using create() and a key identifying the style
                                                    // Styles are either built-in or dynamically loaded from a style plugin, the valid keys are retreived using keys(), they include "windows", "macintosh", etc

    styleLabel = new QLabel(tr("&Style:")); // It is just a text label I believe
    styleLabel->setBuddy(styleComboBox); // When the user presses the shortcut for the label the focus goes to the styleComboBox

    useStylePaletteCheckBox = new QCheckBox(tr("&Use style's standard palette"));
    useStylePaletteCheckBox->setChecked(true);

    disableWidgetsCheckBox = new QCheckBox(tr("&Disable widgets"));

    // create all the other elements by calling their methods
    createTopLeftGroupBox();
    createTopRightGroupBox();
    createBottomLeftTabWidget();
    createBottomRightGroupBox();
    createProgressBar();


    // Connect the Widgets signals with a desired action on another Widget
    connect(styleComboBox, SIGNAL(activated(QString)),
            this, SLOT(changeStyle(QString)));
    connect(useStylePaletteCheckBox, SIGNAL(toggled(bool)),
            this, SLOT(changePalette()));
    connect(disableWidgetsCheckBox, SIGNAL(toggled(bool)),
            topLeftGroupBox, SLOT(setDisabled(bool)));
    connect(disableWidgetsCheckBox, SIGNAL(toggled(bool)),
            topRightGroupBox, SLOT(setDisabled(bool)));
    connect(disableWidgetsCheckBox, SIGNAL(toggled(bool)),
            bottomLeftTabWidget, SLOT(setDisabled(bool)));
    connect(disableWidgetsCheckBox, SIGNAL(toggled(bool)),
            bottomRightGroupBox, SLOT(setDisabled(bool)));

    // Set the Widgets in a layout
    QHBoxLayout* topLayout = new QHBoxLayout;
    topLayout->addWidget(styleLabel);
    topLayout->addWidget(styleComboBox);
    topLayout->addStretch(1);   // Adds a strechable space with zero minimum size and stretch fcator 1 to the end of this box Layout
    topLayout->addWidget(useStylePaletteCheckBox);
    topLayout->addWidget(disableWidgetsCheckBox);


    QGridLayout* mainLayout = new QGridLayout;
    mainLayout->addLayout(topLayout, 0, 0, 1, 2);
    mainLayout->addWidget(topLeftGroupBox, 1, 0);
    mainLayout->addWidget(topRightGroupBox, 1, 1);
    mainLayout->addWidget(bottomLeftTabWidget, 2, 0);
    mainLayout->addWidget(bottomRightGroupBox, 2, 1);
    mainLayout->addWidget(progressBar, 3, 0, 1, 2);     // We have a function where the progress bar is created, then we add it to the layout
    mainLayout->setRowStretch(1, 1);
    mainLayout->setRowStretch(2, 1);
    mainLayout->setColumnStretch(0, 1);
    mainLayout->setColumnStretch(1, 1);
    //setLayout(mainLayout);  // Confirm wether or not this.setLayout(mainLayout); is the same
    this->setLayout(mainLayout);        // INDEED

    setWindowTitle(tr("Styles"));       // Same here
    changeStyle("NorwegianWood");       // Not until implemented
}
/*
WidgetGallery::~WidgetGallery()
{
    delete ui;
}
*/

void WidgetGallery::changeStyle(const QString &styleName)
{
    if (styleName == "NorwegianWood") {
        QApplication::setStyle(new NorwegianWoodStyle);
    } else {
        QApplication::setStyle(QStyleFactory::create(styleName));
    }
    changePalette();
}

void WidgetGallery::changePalette()
{
    if (useStylePaletteCheckBox->isChecked())
        QApplication::setPalette(QApplication::style()->standardPalette());
    else
        QApplication::setPalette(originalPalette);
}

void WidgetGallery::advanceProgressBar()
{
    int curVal = progressBar->value();
    int maxVal = progressBar->maximum();
    progressBar->setValue(curVal + (maxVal - curVal) / 100);
}


// CREATE THE WIDGETS THAT ARE PART OF THE SCREEN



void WidgetGallery::createTopLeftGroupBox()
{
    topLeftGroupBox = new QGroupBox(tr("Group 1"));

    radioButton1 = new QRadioButton(tr("Radio button 1"));
    radioButton2 = new QRadioButton(tr("Radio button 2"));
    radioButton3 = new QRadioButton(tr("Radio button 3"));
    radioButton1->setChecked(true);

    checkBox = new QCheckBox(tr("Tri-state check box"));
    checkBox->setTristate(true);
    checkBox->setCheckState(Qt::PartiallyChecked);

    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(radioButton1);
    layout->addWidget(radioButton2);
    layout->addWidget(radioButton3);
    layout->addWidget(checkBox);
    layout->addStretch(1);
    topLeftGroupBox->setLayout(layout);
}

void WidgetGallery::createTopRightGroupBox()
{
    topRightGroupBox = new QGroupBox(tr("Group 2"));

    defaultPushButton = new QPushButton(tr("Default Push Button"));
    defaultPushButton->setDefault(true);

    togglePushButton = new QPushButton(tr("Toggle Push Button"));
    togglePushButton->setCheckable(true);
    togglePushButton->setChecked(true);

    flatPushButton = new QPushButton(tr("Flat Push Button"));
    flatPushButton->setFlat(true);

    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(defaultPushButton);
    layout->addWidget(togglePushButton);
    layout->addWidget(flatPushButton);
    layout->addStretch(1);
    topRightGroupBox->setLayout(layout);
}

void WidgetGallery::createBottomLeftTabWidget()
{
    bottomLeftTabWidget = new QTabWidget;
    bottomLeftTabWidget->setSizePolicy(QSizePolicy::Preferred,
                                       QSizePolicy::Ignored);   // Horizontal/Vertical,
                                                                // Preferred/Preferred means that the widget can be freely resized

    QWidget *tab1 = new QWidget;
    tableWidget = new QTableWidget(10, 10);                     // Table 10 by 10

    QHBoxLayout *tab1hbox = new QHBoxLayout;
    tab1hbox->setMargin(5);
    tab1hbox->addWidget(tableWidget);
    tab1->setLayout(tab1hbox);

    QWidget *tab2 = new QWidget;
    textEdit = new QTextEdit;

    textEdit->setPlainText(tr("Twinkle, twinkle, little star,\n"
                              "How I wonder what you are.\n"
                              "Up above the world so high,\n"
                              "Like a diamond in the sky.\n"
                              "Twinkle, twinkle, little star,\n"
                              "How I wonder what you are!\n"));

    QHBoxLayout *tab2hbox = new QHBoxLayout;
    tab2hbox->setMargin(5);
    tab2hbox->addWidget(textEdit);
    tab2->setLayout(tab2hbox);

    bottomLeftTabWidget->addTab(tab1, tr("&Table"));
    bottomLeftTabWidget->addTab(tab2, tr("Text &Edit"));
}

void WidgetGallery::createBottomRightGroupBox()
{
    bottomRightGroupBox = new QGroupBox(tr("Group 3"));
    bottomRightGroupBox->setCheckable(true);
    bottomRightGroupBox->setChecked(true);

    lineEdit = new QLineEdit("s3cRe7");
    lineEdit->setEchoMode(QLineEdit::Password);

    spinBox = new QSpinBox(bottomRightGroupBox);
    spinBox->setValue(50);

    dateTimeEdit = new QDateTimeEdit(bottomRightGroupBox);
    dateTimeEdit->setDateTime(QDateTime::currentDateTime());

    slider = new QSlider(Qt::Horizontal, bottomRightGroupBox);  // Orientation, parent
    slider->setValue(40);

    scrollBar = new QScrollBar(Qt::Horizontal, bottomRightGroupBox);
    scrollBar->setValue(60);

    dial = new QDial(bottomRightGroupBox);
    dial->setValue(30);
    dial->setNotchesVisible(true);

    QGridLayout *layout = new QGridLayout;
    layout->addWidget(lineEdit, 0, 0, 1, 2);
    layout->addWidget(spinBox, 1, 0, 1, 2);
    layout->addWidget(dateTimeEdit, 2, 0, 1, 2);
    layout->addWidget(slider, 3, 0);
    layout->addWidget(scrollBar, 4, 0);
    layout->addWidget(dial, 3, 1, 2, 1);
    layout->setRowStretch(5, 1);
    bottomRightGroupBox->setLayout(layout);
}

void WidgetGallery::createProgressBar()
{
    progressBar = new QProgressBar;
    progressBar->setRange(0, 10000);
    progressBar->setValue(0);

    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(advanceProgressBar()));
    timer->start(1000);
}
