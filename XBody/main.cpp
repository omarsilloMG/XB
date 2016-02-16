#include "dialog.h"
#include <QApplication>
#include <QSplashScreen>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Dialog w;

    //Q_INIT_RESOURCE(resources);   // Ensure that the resources are initialized at startup

    /*  SPLASH SCREEN CODE */
    QSplashScreen* splash = new QSplashScreen;
    splash->setPixmap(QPixmap(":/Images/XBody.JPG"));
    splash->show();

    /*  // I would like to use all this options but right now they don't seem to have any effect
     *
     *
    Qt::Alignment topRight = Qt::AlignRight | Qt::AlignTop;
    splash->showMessage(QObject::tr("Setting up the main window..."),
                        topRight, Qt::white);

    splash->showMessage(QObject::tr("Loading modules..."),
                        topRight, Qt::white);

    //loadModules();

    splash->showMessage(QObject::tr("Establishing connections..."),
                        topRight, Qt::white);
    //establishConnections();
    */


    // Unnecesary delay (to display the splash screen longer)
    for(int i= 0; i < 1000000000; i++);

    w.show();
    splash->finish(&w);

    delete splash;
    return a.exec();
}
