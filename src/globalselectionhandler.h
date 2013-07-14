#ifndef GLOBALSELECTIONHANDLER_H
#define GLOBALSELECTIONHANDLER_H

#include <QApplication>
#include <QClipboard>
#include <QString>
#include <QMimeData>

#ifdef Q_WS_WIN
#include <qt_windows.h>
#endif

class globalSelectionHandler
{
public:
    static QString getGlobalMouseSelection();
private:
    enum keyActionType
    {
        Up,
        Down
    };
#ifdef Q_WS_WIN
    static void winapiGenerateKey(int key, keyActionType actionType, bool extended = false);
#endif
};

#endif // GLOBALSELECTIONHANDLER_H