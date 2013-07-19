#-------------------------------------------------
#
# Project created by QtCreator 2013-07-19T19:43:33
#
#-------------------------------------------------

QT       -= gui

TARGET = ExamplePlugin
TEMPLATE = lib

DEFINES += EXAMPLEPLUGIN_LIBRARY

SOURCES += exampleplugin.cpp

HEADERS += exampleplugin.h\
        exampleplugin_global.h

unix:!symbian {
    maemo5 {
        target.path = /opt/usr/lib
    } else {
        target.path = /usr/lib
    }
    INSTALLS += target
}
