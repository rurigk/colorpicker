#include "colorpanel.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QApplication::setQuitOnLastWindowClosed(false);

    ColorPanel w;
    if(w.exitApp)
    {
        w.close();
        return 0;
    }
    //w.show();
    return a.exec();
}
