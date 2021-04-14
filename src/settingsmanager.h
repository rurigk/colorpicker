#ifndef SETTINGSMANAGER_H
#define SETTINGSMANAGER_H

#include <QString>

class SettingsManager
{
	public:
		SettingsManager();

	private:
		bool initAtStartup = false;
		bool standaloneMode = false;
		QString * theme = new QString();
};

#endif // SETTINGSMANAGER_H
