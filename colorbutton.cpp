#include "colorbutton.h"

ColorButton::ColorButton( QWidget* parent ) : QPushButton( parent )
{

}

ColorButton::ColorButton( const QString& text, QWidget* parent ) : QPushButton( text, parent )
{

}

void ColorButton::enterEvent( QEvent* e )
{
    emit hovered();
    // don't forget to forward the event
    QWidget::enterEvent( e );
}

void ColorButton::leaveEvent( QEvent* e )
{
    emit unhovered();
    // don't forget to forward the event
    QWidget::enterEvent( e );
}
