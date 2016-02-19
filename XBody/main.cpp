#include "dialog.h"
#include <QApplication>
#include <QSplashScreen>
#include <QThread>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Dialog w;

    /*  SPLASH SCREEN CODE with messages */
    Q_INIT_RESOURCE(resources);                                 // Ensure that the resources are initialized at startup (.JPG)
    QPixmap pixmap(":/Images/XBody.JPG");                       // Load Image Resource
    QSplashScreen* splash = new QSplashScreen(pixmap);          // Create splash screen with the image
    splash->show();                                             // Show it!

    // Declare the desired alignment
    Qt::Alignment topRight = Qt::AlignRight | Qt::AlignTop;

    // Load some items (and display a message). Process events
    splash->showMessage(QObject::tr("Loaded modules"),          // We use tr because it returns a trasnlated version of the Text
                        topRight,Qt::red);
    a.processEvents();                                          // It is necessary to call this periodically to receive mouse clicks

    // Unnecesary delay (to display the splash screen longer)
    //for(int i= 0; i < 1000000000; i++);
    QThread::msleep(1000);

    // Do some other stuff and display a different message
    splash->showMessage(QObject::tr("Established connections"));
    a.processEvents();                                          // It is necessary to call this periodically to receive mouse clicks


    // Unnecesary delay (to display the splash screen longer)
    //for(int i= 0; i < 1000000000; i++);
    QThread::msleep(1000);

    w.show();
    splash->finish(&w);

    delete splash;
    return a.exec();
}
