#include "colorpanel.h"

#include <QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);


	qputenv("QT_AUTO_SCREEN_SCALE_FACTOR", QByteArray("0"));

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
