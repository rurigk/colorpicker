#ifndef STYLESHEETHELPER_H
#define STYLESHEETHELPER_H

#include <QString>
#include <QMap>

class StylesheetHelper
{
public:
    StylesheetHelper();
    QString BuildStylesheet();
	void SetSelector(QString* selector);
    void SetRule(QString* rule, QString* value);
    void RemoveRule(QString* rule);
    QString GetValue(QString* rule);
private:
	QString * selector;
	QString * selectorOpeningBrace = new QString("{\n");
	QString * selectorCloseBrace = new QString("\n}");
    QMap<QString, QString> *rules;
};

#endif // STYLESHEETHELPER_H
