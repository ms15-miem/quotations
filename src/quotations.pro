#-------------------------------------------------
#
# Project created by QtCreator 2013-07-09T08:22:41
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = quotations
TEMPLATE = app


SOURCES += main.cpp \
    application.cpp \
    globalselectionhandler.cpp

HEADERS  += \
    application.h \
    globalselectionhandler.h

FORMS    +=


 CONFIG  += qxt
 QXT     += core gui

LIBS += -luser32
