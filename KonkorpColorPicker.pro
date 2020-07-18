QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

VERSION = 0.5.0.0
QMAKE_TARGET_COMPANY = Konkorp
QMAKE_TARGET_PRODUCT = ColorPicker
QMAKE_TARGET_DESCRIPTION = Desktop color picker
QMAKE_TARGET_COPYRIGHT = LGPLv3

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    src/colorbutton.cpp \
    src/colorpicker.cpp \
    src/colorpickerhistory.cpp \
    src/colorpickertitlebar.cpp \
    src/main.cpp \
    src/colorpanel.cpp \
    src/popupnotification.cpp \
    src/stylesheethelper.cpp

HEADERS += \
    src/colorbutton.h \
    src/colorpanel.h \
    src/colorpicker.h \
    src/colorpickerhistory.h \
    src/colorpickertitlebar.h \
    src/popupnotification.h \
    src/stylesheethelper.h

FORMS += \
    src/colorpanel.ui \
    src/colorpicker.ui

TRANSLATIONS += \
    src/KonkorpColorPicker_en_US.ts

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    colorpicker.qrc
