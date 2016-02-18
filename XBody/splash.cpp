#include "splash.h"
#include "ui_splash.h"
#include <QVBoxLayout>

Splash::Splash(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Splash)
{
    ui->setupUi(this);
    QVBoxLayout* vLayout = new QVBoxLayout;
    vLayout->addItem();


}

Splash::~Splash()
{
    delete ui;
}
