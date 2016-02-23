#include "widgetgallery.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    Q_INIT_RESOURCE(styles);

    QApplication a(argc, argv);
    WidgetGallery gallery;
    gallery.show();

    return a.exec();
}
