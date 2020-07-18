#ifndef COLORPICKERHISTORY_H
#define COLORPICKERHISTORY_H

#include <QList>
#include <QColor>
#include <QFile>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QJsonParseError>
#include <QJsonValue>
#include <QJsonValue>
#include <QDebug>

class ColorPickerHistory
{
public:
    ColorPickerHistory();

    QList<QColor> * history;
    void LoadHistory();
    void PushToHistory(QColor color);
    void SaveHistory();
    void Clear();
private:
    int historyMaxLenght = 100;
};

#endif // COLORPICKERHISTORY_H
