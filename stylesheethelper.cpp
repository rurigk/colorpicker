#include "stylesheethelper.h"

StylesheetHelper::StylesheetHelper()
{
    rules = new QMap<QString, QString>();
}

void StylesheetHelper::SetRule(QString* rule, QString* value)
{
    rules->insert(*rule, *value);
}

void StylesheetHelper::RemoveRule(QString *rule)
{
    rules->remove(*rule);
}

QString StylesheetHelper::GetValue(QString *rule)
{
    if(!rules->contains(*rule)) return NULL;
    return rules->value(*rule);
}

QString StylesheetHelper::BuildStylesheet()
{
    QString *stylesheet = new QString();
    foreach (QString key, rules->keys()) {
        stylesheet->append(key + ":"+ rules->value(key) +";");
    }
    return *stylesheet;
}
