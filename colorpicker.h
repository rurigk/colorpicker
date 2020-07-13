#ifndef COLORPICKER_H
#define COLORPICKER_H

#include <QWidget>
#include <QPainter>
#include <QMouseEvent>
#include <QDebug>
#include <QColor>

namespace Ui {
    class ColorPicker;
}

class ColorPicker : public QWidget
{
    Q_OBJECT

public:
    explicit ColorPicker(QWidget *parent = nullptr);
    ~ColorPicker();
    void paintEvent(QPaintEvent *);
    QPixmap emptyPixmap = *new QPixmap();
    QPixmap backgroundPixmap;

signals:
    void ColorPicked(QColor color);

private:
    Ui::ColorPicker *ui;
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void enterEvent(QEvent *event);
    void leaveEvent(QEvent *event);
    QPoint *mousePos;
    bool drawLens = false;
    int rectSize = 100;
    int lensRectSize = 20;
};

#endif // COLORPICKER_H
