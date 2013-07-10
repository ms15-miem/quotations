#include "application.h"

#include <QxtApplication>
#include <QxtGlobalShortcut>
#include <QApplication>
#include <QClipboard>

int main(int argc, char *argv[])
{
    Application a(argc, argv);
    a.setQuitOnLastWindowClosed(false);

    QxtGlobalShortcut shortcut;
    QObject::connect(&shortcut, SIGNAL(activated()), &a, SLOT(hotkeyPressed()));
    shortcut.setShortcut(QKeySequence("Alt+Q"));

    return a.exec();
}
