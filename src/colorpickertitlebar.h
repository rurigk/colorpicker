#ifndef COLORPICKERTITLEBAR_H
#define COLORPICKERTITLEBAR_H

#include <QWidget>
#include <QStyle>
#include <QStyleOption>
#include <QPainter>
#include <QMouseEvent>
#include <QPoint>
#include <QRect>
#include <QApplication>
#include <QDesktopWidget>
#include <QScreen>
#include <QDebug>

class ColorPickerTitlebar : public QWidget
{
    Q_OBJECT
public:
    explicit ColorPickerTitlebar(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent *event);

signals:
	void OnWindowMove();

private:
    bool draggingWindow = false;
    QPoint pressPos;
    QPoint originalWindowPos;
    int snapDistance = 50;

    void mousePressEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    int PointerToScreen(QPoint pointer);

};

#endif // COLORPICKERTITLEBAR_H
