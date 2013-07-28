TEMPLATE = lib

QT       -= gui

TARGET = $$qtLibraryTarget(p_diaryposter)

HEADERS += \
    diaryposter.h

SOURCES += \
    diaryposter.cpp

DESTDIR       = ../../plugins

CONFIG       += plugin

INCLUDEPATH  += ../../app


