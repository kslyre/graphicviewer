#include "window.h"

#include <QApplication>
#include <QSurfaceFormat>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QSurfaceFormat fmt;
    fmt.setSamples(2);
    QSurfaceFormat::setDefaultFormat(fmt);

    Window window;
    window.show();
    return a.exec();
}
