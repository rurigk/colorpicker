#ifndef COLORBUTTON_H
#define COLORBUTTON_H

#include <QPushButton>
#include <QMouseEvent>

class ColorButton : public QPushButton
{
    Q_OBJECT
public:
    ColorButton(QWidget* parent = 0 );
    ColorButton( const QString& text, QWidget* parent = 0 );
signals:
    void hovered();
    void unhovered();

protected:
    virtual void enterEvent( QEvent* e );
    virtual void leaveEvent( QEvent* e );
};

#endif // COLORBUTTON_H
