TEMPLATE = lib

QT       -= gui

QT += network

TARGET = $$qtLibraryTarget(p_diaryposter)

HEADERS += \
    diaryposter.h

SOURCES += \
    diaryposter.cpp

DESTDIR       = ../../plugins

CONFIG       += plugin

INCLUDEPATH  += ../../app



win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../InternetPoster/release/ -lInternetPoster
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../InternetPoster/debug/ -lInternetPoster
else:symbian: LIBS += -lInternetPoster
else:unix: LIBS += -L$$OUT_PWD/../InternetPoster/ -lInternetPoster

INCLUDEPATH += $$PWD/../InternetPoster
DEPENDPATH += $$PWD/../InternetPoster

win32:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../InternetPoster/release/InternetPoster.lib
else:win32:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../InternetPoster/debug/InternetPoster.lib
else:unix:!symbian: PRE_TARGETDEPS += $$OUT_PWD/../InternetPoster/libInternetPoster.a
