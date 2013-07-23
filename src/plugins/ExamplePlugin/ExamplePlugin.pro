#-------------------------------------------------
#
# Project created by QtCreator 2013-07-20T13:00:09
#
#-------------------------------------------------

TEMPLATE = lib

QT       -= gui

TARGET = $$qtLibraryTarget(example)

SOURCES += exampleplugin.cpp

HEADERS += exampleplugin.h

DESTDIR       = ../../plugins

CONFIG       += plugin

INCLUDEPATH  += ../../app
