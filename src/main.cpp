#include "colorpanel.h"

#include <QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);

	QFile defaultTheme(":/themes/default.qss");

	if (!defaultTheme.exists())   {
		printf("Unable to set stylesheet, file not found\n");
	}
	else   {
		defaultTheme.open(QFile::ReadOnly | QFile::Text);
		QTextStream ts(&defaultTheme);
		a.setStyleSheet(ts.readAll());
	}

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
