#-------------------------------------------------
#
# Project created by QtCreator 2013-07-27T00:58:04
#
#-------------------------------------------------

TEMPLATE = lib

QT       -= gui

TARGET = $$qtLibraryTarget(ap_internetposter)

SOURCES += \
    internetposter.cpp

HEADERS += \
    internetposter.h

DESTDIR       = ../../posting

CONFIG       += plugin

INCLUDEPATH  += ../../app
