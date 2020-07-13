#include "colorpickerhistory.h"

ColorPickerHistory::ColorPickerHistory()
{
    history = new QList<QColor>();
}

void ColorPickerHistory::LoadHistory()
{
    QFile file("history.json");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        return;
    }
    QByteArray historyJson = file.readAll();
    QJsonDocument document = QJsonDocument::fromJson(historyJson);
    QJsonObject jsonObject = document.object();

    QJsonArray historyList = jsonObject["history"].toArray();

    QList<QColor> * newColors = new QList<QColor>();
    for (int hIndex = 0; hIndex < historyList.count(); hIndex++) {

        QColor * newColor = new QColor();
        newColor->setNamedColor(historyList.at(hIndex).toString());
        newColors->append(*newColor);
    }
    history = newColors;
}

void ColorPickerHistory::SaveHistory()
{

    QJsonDocument * document = new QJsonDocument();
    QJsonObject * jsonObject = new QJsonObject();
    QJsonArray * historyColorsArray = new QJsonArray();

    for (int hIndex = 0; hIndex < history->count(); hIndex++) {
        historyColorsArray->append(history->at(hIndex).name(QColor::HexRgb));
    }

    jsonObject->insert("history", *historyColorsArray);
    document->setObject(*jsonObject);
    QByteArray jsonString = document->toJson();
    QFile file("history.json");
    file.open(QIODevice::WriteOnly);
    if(file.isOpen())
    {
        file.write(jsonString);
        file.close();
    }
}

void ColorPickerHistory::PushToHistory(QColor color)
{
    history->append(color);
    if(history->count() > historyMaxLenght)
    {
        history->removeFirst();
    }
    SaveHistory();
}
