#include "splash.h"
#include "ui_splash.h"
#include <QGridLayout>
#include <QSplashScreen>
#include <QPixmap>
#include <QTimer>
#include <QtWidgets>

Splash::Splash(QWidget *parent) :
    QDialog(parent)/*,
    ui(new Ui::Splash)*/
{
    // ui->setupUi(this);
    QGridLayout* mainLayout = new QGridLayout;

    createSplashScreen();
    createProgressBar();


    mainLayout->addWidget(splash,0,0);

    // Set a fixed size for the splashscreen. Probably not the best way to do it
    mainLayout->setColumnMinimumWidth(0,325); // Size in pixels
    mainLayout->setRowMinimumHeight(0,325);


    mainLayout->addWidget(progressBar,1,0);
    this->setLayout(mainLayout);
}

/*
Splash::~Splash()
{
    delete ui;
}
*/

void Splash::createProgressBar()
{
    progressBar = new QProgressBar;
    //progressBar->setRange(0, 10000);
    progressBar->setRange(0, 100);
    progressBar->setValue(0);

    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(advanceProgressBar()));
    timer->start(100);
}

void Splash::advanceProgressBar()
{
    int curVal = progressBar->value();
    //int maxVal = progressBar->maximum();
    //progressBar->setValue(curVal + (maxVal - curVal) / 100);
    progressBar->setValue(curVal + 1);
}


void Splash::createSplashScreen()
{
    QPixmap pixmap(":/Images/XBody.JPG");   // Load Image Resource
    splash = new QSplashScreen(pixmap);     // Create splash screen with the image
}
