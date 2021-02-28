#include "stylesheethelper.h"

StylesheetHelper::StylesheetHelper()
{
	selector = new QString();
    rules = new QMap<QString, QString>();
}

void StylesheetHelper::SetSelector(QString * _selector)
{
	selector = _selector;
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
		stylesheet->append(key + ":"+ rules->value(key) +";\n");
    }

	if(selector->length() > 0)
	{
		QString * stylesheetWithSelector = new QString();
		//stylesheetWithSelector->reserve(selector->length() + selectorOpeningBrace->length() + stylesheet->length() + selectorCloseBrace->length());

		stylesheetWithSelector->append(selector);
		stylesheetWithSelector->append(selectorOpeningBrace);
		stylesheetWithSelector->append(stylesheet);
		stylesheetWithSelector->append(selectorCloseBrace);

		return *stylesheetWithSelector;
	}

	return *stylesheet;
}
