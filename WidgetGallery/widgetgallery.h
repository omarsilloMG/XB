#ifndef WIDGETGALLERY_H
#define WIDGETGALLERY_H

#include <QDialog>

// Forward declarations
class QCheckBox;
class QComboBox;
class QDateTimeEdit;
class QDial;
class QGroupBox;
class QLabel;
class QLineEdit;
class QProgressBar;
class QPushButton;
class QRadioButton;
class QScrollBar;
class QSlider;
class QSpinBox;
class QTabWidget;
class QTableWidget;
class QTextEdit;

/*namespace Ui {
class WidgetGallery;
}*/

class WidgetGallery : public QDialog
{
    Q_OBJECT

public:
    WidgetGallery(QWidget* parent = 0);
    //explicit WidgetGallery(QWidget *parent = 0);
    //~WidgetGallery();

private slots:
    void changeStyle(const QString &styleName);
    void changePalette();
    void advanceProgressBar();

private:
    void createTopLeftGroupBox();
    void createTopRightGroupBox();
    void createBottomLeftTabWidget();
    void createBottomRightGroupBox();
    void createProgressBar();

    QPalette originalPalette;

    QLabel* styleLabel;
    QComboBox* styleComboBox;
    QCheckBox* useStylePaletteCheckBox;
    QCheckBox* disableWidgetsCheckBox;

    QGroupBox* topLeftGroupBox;
    QRadioButton* radioButton1;
    QRadioButton* radioButton2;
    QRadioButton* radioButton3;
    QCheckBox* checkBox;

    QGroupBox *topRightGroupBox;
    QPushButton *defaultPushButton;
    QPushButton *togglePushButton;
    QPushButton *flatPushButton;

    QTabWidget *bottomLeftTabWidget;
    QTableWidget *tableWidget;
    QTextEdit *textEdit;

    QGroupBox *bottomRightGroupBox;
    QLineEdit *lineEdit;
    QSpinBox *spinBox;
    QDateTimeEdit *dateTimeEdit;
    QSlider *slider;
    QScrollBar *scrollBar;
    QDial *dial;

    QProgressBar *progressBar;

    //Ui::WidgetGallery *ui;
};

#endif // WIDGETGALLERY_H
