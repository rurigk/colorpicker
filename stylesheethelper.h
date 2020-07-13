#ifndef STYLESHEETHELPER_H
#define STYLESHEETHELPER_H

#include <QString>
#include <QMap>

class StylesheetHelper
{
public:
    StylesheetHelper();
    QString BuildStylesheet();
    void SetRule(QString* rule, QString* value);
    void RemoveRule(QString* rule);
    QString GetValue(QString* rule);
private:
    QMap<QString, QString> *rules;
};

#endif // STYLESHEETHELPER_H
