#-------------------------------------------------
#
# Project created by QtCreator 2013-08-07T18:14:34
#
#-------------------------------------------------

QT       += network

QT       -= gui

TARGET = InternetPoster
TEMPLATE = lib
CONFIG += staticlib

INCLUDEPATH  += ../../app

SOURCES += internetposter.cpp \
    NetClient/netclient.cpp

HEADERS += internetposter.h \
    NetClient/netclient.h
unix:!symbian {
    maemo5 {
        target.path = /opt/usr/lib
    } else {
        target.path = /usr/lib
    }
    INSTALLS += target
}
