#ifndef SPLASH_H
#define SPLASH_H

// Possibly remove the include headers with forward declarations
// of the classes.

#include <QDialog>
#include <QProgressBar>
#include <QSplashScreen>
#include <QGroupBox>
#include <QRadioButton>
#include <QCheckBox>

/*namespace Ui {
class Splash;
}*/

class Splash : public QDialog
{
    Q_OBJECT

public:
    Splash(QWidget *parent = 0);
    //explicit Splash(QWidget *parent = 0);
    //~Splash();

private slots:
    void advanceProgressBar();

private:
    //Ui::Splash *ui;
    void createProgressBar();
    void createTopLeftGroupBox();
    void createSplashScreen();
    QProgressBar* progressBar;
    QSplashScreen* splash;

};

#endif // SPLASH_H
