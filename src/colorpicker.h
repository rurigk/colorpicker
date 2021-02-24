#ifndef COLORPICKER_H
#define COLORPICKER_H

#include <QWidget>
#include <QPainter>
#include <QMouseEvent>
#include <QDebug>
#include <QColor>
#include <QShortcut>

namespace Ui {
    class ColorPicker;
}

class ColorPanel;

class ColorPicker : public QWidget
{
    Q_OBJECT

public:
    explicit ColorPicker(QWidget *parent = nullptr);
    ~ColorPicker();
    void paintEvent(QPaintEvent *);
    QPixmap emptyPixmap = *new QPixmap();
    QPixmap backgroundPixmap;
	ColorPanel * colorPanel;

signals:
    void ColorPicked(QColor color);
    void PickerCancelled();

private:
    Ui::ColorPicker *ui;
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void enterEvent(QEvent *event);
    void leaveEvent(QEvent *event);
    void EscapeKeyPressed();
    QPoint *mousePos;
    QShortcut *shortcut;
    bool drawLens = false;
	int rectSize = 150;
    int lensRectSize = 20;

	int infoBoxWidth = rectSize + 1;
	int infoBoxHeight = 25;

	int infoBoxPosition = -1;
	QPen penDefault;
	QPen penTranslucentDark;

	QColor translucentDark;
};

#endif // COLORPICKER_H
