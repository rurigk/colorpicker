#include "colorpicker.h"
#include "ui_colorpicker.h"

ColorPicker::ColorPicker(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ColorPicker)
{
    ui->setupUi(this);
    setCursor(Qt::BlankCursor);
    setWindowFlags(Qt::FramelessWindowHint| Qt::WindowSystemMenuHint);
    //setWindowFlags(Qt::FramelessWindowHint| Qt::WindowSystemMenuHint | Qt::WindowStaysOnTopHint | Qt::ToolTip);
    setMouseTracking(true);
    mousePos = new QPoint(-1, -1);
}

ColorPicker::~ColorPicker()
{
    delete ui;
}

void ColorPicker::paintEvent(QPaintEvent *)
{
    QPainter painter;
    painter.begin(this);

    painter.drawPixmap(0, 0,
                       backgroundPixmap.width(),
                       backgroundPixmap.height(),
                       backgroundPixmap);

    if(drawLens && mousePos->x() >= 0 && mousePos->y() >= 0)
    {
        painter.drawPixmap(
                           mousePos->x() - (rectSize / 2),
                           mousePos->y() - (rectSize / 2),
                           rectSize,
                           rectSize,
                           backgroundPixmap,
                           mousePos->x() - (lensRectSize / 2),
                           mousePos->y() - (lensRectSize / 2),
                           lensRectSize,
                           lensRectSize);
        painter.drawRect(mousePos->x() - (rectSize / 2),
                        mousePos->y() - (rectSize / 2),
                        rectSize, rectSize);
        QImage image = backgroundPixmap.toImage();
        QColor color = image.pixel(mousePos->x(), mousePos->y());
        QPen penColor(color, 1);
        //painter.setPen(penColor);
        painter.drawRect(mousePos->x(),
                        mousePos->y(),
                        4, 4);
        QPen penDefault(Qt::black, 1);
        //painter.setPen(penDefault);
    }

    painter.end();
}

void ColorPicker::mouseMoveEvent(QMouseEvent * event)
{
    QPoint *mousePoint = new QPoint(event->pos().x(), event->pos().y());
    int xDiff = mousePos->x() - mousePoint->x() < 0? (mousePos->x() - mousePoint->x())*-1 : mousePos->x() - mousePoint->x();
    int yDiff = mousePos->y() - mousePoint->y() < 0? (mousePos->y() - mousePoint->y())*-1 : mousePos->y() - mousePoint->y();
    if(xDiff > rectSize / 2 || yDiff > rectSize / 2)
    {
        mousePos = mousePoint;
        update((mousePos->x() - (rectSize / 2)) - 300,
               (mousePos->y() - (rectSize / 2)) - 300,
               rectSize + 600, rectSize + 600);
    }
    else
    {
        mousePos = mousePoint;
        update((mousePos->x() - (rectSize / 2)) - 30,
               (mousePos->y() - (rectSize / 2)) - 30,
               rectSize + 60, rectSize + 60);
    }
}

void ColorPicker::mousePressEvent(QMouseEvent *event)
{
    QImage image = backgroundPixmap.toImage();
    QColor color = image.pixel(event->pos().x(), event->pos().y());
    ColorPicked(color);
    backgroundPixmap = emptyPixmap;
    mousePos = new QPoint(-1, -1);
}

void ColorPicker::enterEvent(QEvent *)
{
    drawLens = true;
    repaint();
}

void ColorPicker::leaveEvent(QEvent *)
{
    drawLens = false;
    repaint();
}
