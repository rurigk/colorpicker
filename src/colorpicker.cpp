#include "colorpicker.h"
#include "ui_colorpicker.h"
#include "colorpanel.h"

ColorPicker::ColorPicker(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ColorPicker)
{
    ui->setupUi(this);
    setCursor(Qt::BlankCursor);
    setWindowFlags(Qt::FramelessWindowHint | Qt::WindowSystemMenuHint | Qt::WindowStaysOnTopHint);
    setMouseTracking(true);
    mousePos = new QPoint(-1, -1);
    shortcut = new QShortcut(QKeySequence(Qt::Key_Escape), this);
    connect(shortcut, &QShortcut::activated, this, &ColorPicker::EscapeKeyPressed);

	translucentDark = QColor(0, 0, 0, 180);

	penDefault = QPen (Qt::black, 1);
	penTranslucentDark = QPen (translucentDark, 1);
}

ColorPicker::~ColorPicker()
{
    delete ui;
}

void ColorPicker::paintEvent(QPaintEvent *)
{
    QPainter painter;
    painter.begin(this);

	QFont defaultFont = painter.font();
	float fontSize = defaultFont.pointSize() * (96 / screen()->logicalDotsPerInchX());
	QFont scaledFont = QFont(defaultFont.family(), fontSize);
	painter.setFont(scaledFont);

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
		QString colorString = colorPanel->GetColorString(color);
		//QPen penColor(color, 1);
		//painter.setPen(penColor);

		// Draw the middle pixel selector box
		painter.drawRect(mousePos->x(), mousePos->y(), 7, 7);

		// Set the pen color to translucent black
		painter.setPen(penDefault);

		// Draw info box
		if(infoBoxPosition == 1)
		{
			int startPositionX = mousePos->x() - (rectSize / 2);
			int startPositionY = mousePos->y() - (rectSize / 2) - infoBoxHeight;
			painter.fillRect(startPositionX, startPositionY, infoBoxWidth, infoBoxHeight, translucentDark);

			painter.fillRect(startPositionX + 4, startPositionY + 4, 16, 16, color);

			painter.setPen(QPen (Qt::white));
			painter.drawText(startPositionX + 24, startPositionY + 16, colorString);
		}
		else if(infoBoxPosition == 2)
		{
			int startPositionX = mousePos->x() - (rectSize / 2);
			int startPositionY = mousePos->y() + (rectSize / 2);
			painter.fillRect(startPositionX, startPositionY, infoBoxWidth, infoBoxHeight, translucentDark);

			painter.fillRect(startPositionX + 4, startPositionY + 4, 16, 16, color);

			painter.setPen(QPen (Qt::white));
			painter.drawText(startPositionX + 24, startPositionY + 16, colorString);
		}


		// Reset the pen color to black
		painter.setPen(penDefault);
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
        update((mousePos->x() - (rectSize / 2)) - 50,
               (mousePos->y() - (rectSize / 2)) - 50,
               rectSize + 100, rectSize + 100);
    }

	infoBoxPosition = (mousePos->y() >= height() - infoBoxHeight - (rectSize / 2))?  1 : 2;

	repaint();
}

void ColorPicker::mousePressEvent(QMouseEvent *event)
{
    if(event->button() == Qt::LeftButton)
    {
        QImage image = backgroundPixmap.toImage();
        QColor color = image.pixel(event->pos().x(), event->pos().y());
        ColorPicked(color);
        backgroundPixmap = emptyPixmap;
        mousePos = new QPoint(-1, -1);
    }
    else
    {
        backgroundPixmap = emptyPixmap;
        mousePos = new QPoint(-1, -1);
        PickerCancelled();
    }
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

void ColorPicker::EscapeKeyPressed()
{
    backgroundPixmap = emptyPixmap;
    mousePos = new QPoint(-1, -1);
    PickerCancelled();
}
