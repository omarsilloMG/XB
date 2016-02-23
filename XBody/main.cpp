#include "dialog.h"
#include <QApplication>
#include <QSplashScreen>
#include <QThread>
#include "splash.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    // Dialog w;
    Splash splash;

    /*  SPLASH SCREEN CODE with messages */
    Q_INIT_RESOURCE(resources);     // Ensure that the resources are initialized at startup (.JPG)
/*
    a.processEvents();              // Where should we use process events now that main changed?
    w.show();
    splash->finish(&w);
*/
    //delete splash;
    splash.show();
    // FIND A WAY TO FINISH IT CREATING A FINISH FUNC FOR SPLASH
    //w.show();
    return a.exec();
}
