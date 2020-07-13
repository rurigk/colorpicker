#include "colorpanel.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QApplication::setQuitOnLastWindowClosed(false);

    ColorPanel w;
    w.show();
    return a.exec();
}
