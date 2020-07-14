#ifndef COLORPANEL_H
#define COLORPANEL_H

#include <QMainWindow>
#include <QSystemTrayIcon>
#include <QScreen>
#include <QApplication>
#include <QDesktopWidget>
#include <QDebug>
#include <QColor>
#include <QClipboard>
#include <QAction>
#include <QMenu>
#include <QStyle>
#include <QGraphicsDropShadowEffect>
#include <QGridLayout>
#include <QPushButton>
#include <QSizePolicy>
#include <QSpacerItem>
#include "colorpicker.h"
#include "stylesheethelper.h"
#include "colorpickerhistory.h"
#include "colorbutton.h"

QT_BEGIN_NAMESPACE
namespace Ui { class ColorPanel; }
QT_END_NAMESPACE

class ColorPanel : public QMainWindow
{
    Q_OBJECT

public:
    ColorPanel(QWidget *parent = nullptr);
    ~ColorPanel();

private slots:
    void trayActivated(QSystemTrayIcon::ActivationReason reason);
    void ColorPicked(QColor color);
    void on_closeWidgetButton_clicked();
    void on_toggleWindowMode_clicked();
    void on_pickColorButton_clicked();
    void ColorPickedFromHistory(QColor color);
    void ColorHoveredFromHistory(QColor color);
    void ColorUnhoveredFromHistory();
    void ColorPickedFromToolbar(int index);
    void PickerCancelled();

private:
    Ui::ColorPanel *ui;
    
    QSystemTrayIcon *sysTray;
    QAction *openAction;
    QAction *quitAction;
    QMenu *trayMenu;

    QList<ColorPicker*> *pickerWindows;
    QList<QImage*> *desktopsImages;
    ColorPickerHistory * colorPickerHistory;

    StylesheetHelper* toolbarStyle;
    StylesheetHelper* contentStyle;

    bool toolbarMode = true;
    bool restoreAfterPick = false;

    int historyColumns;

    void CreateTrayIcon();
    void CreateTrayActions();
    void ShowPickerWindows();
    void UpdateWindowMode();
    void FillHistory();
    void FillToolbarHistory();
    void ShowNotification(QString title, QString message);
};
#endif // COLORPANEL_H
