#include "colorpickertitlebar.h"

ColorPickerTitlebar::ColorPickerTitlebar(QWidget *parent) : QWidget(parent)
{

}

void ColorPickerTitlebar::paintEvent(QPaintEvent *)
{
    QStyleOption opt;
    opt.init(this);
    QPainter p(this);
    style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);
}

void ColorPickerTitlebar::mousePressEvent(QMouseEvent *event)
{
    Q_UNUSED(event);
    pressPos = QCursor::pos();
    originalWindowPos = window()->pos();
    draggingWindow = true;
}

void ColorPickerTitlebar::mouseReleaseEvent(QMouseEvent *)
{
    draggingWindow = false;
}

void ColorPickerTitlebar::mouseMoveEvent(QMouseEvent *event)
{
    Q_UNUSED(event);
    if(draggingWindow)
    {
        QList<QScreen*> screens = QGuiApplication::screens();
        QPoint mousePos = QCursor::pos();

        int sIndex = PointerToScreen(mousePos);

        QPoint diff= mousePos - pressPos;
        QPoint windowPosition = originalWindowPos + diff;
        QRect availableGeometry = screens.at(sIndex)->availableGeometry();

        int wx = windowPosition.x(); // Window x position
        int wy = windowPosition.y(); // Window y position
        int ww = window()->width();
        int wh = window()->height();

        int minX = availableGeometry.x();
        int minY = availableGeometry.y();
        int maxX = minX + availableGeometry.width();
        int maxY = minY + availableGeometry.height();

        wx = wx < minX ? minX : wx;
        wx = wx + ww > maxX ? maxX - ww : wx;
        wy = wy < minY ? minY : wy;
        wy = wy + wh > maxY ? maxY - wh : wy;

        windowPosition.setX(wx);
        windowPosition.setY(wy);
        window()->move(windowPosition);

		emit OnWindowMove();
    }
}

int ColorPickerTitlebar::PointerToScreen(QPoint pointer)
{
    QList<QScreen*> screens = QGuiApplication::screens();
    for (int sIndex = 0; sIndex < screens.count(); sIndex++) {
        QScreen *screen = screens.at(sIndex);
        QRect space = screen->geometry();
        if(
            pointer.x() >= space.x() &&
            pointer.x() <= space.x() + space.width() &&
            pointer.y() >= space.y() &&
            pointer.y() <= space.y() + space.height()
        )
        {
            return sIndex;
        }
    }
    return 0;
}
