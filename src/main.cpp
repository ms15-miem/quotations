#include "application.h"

#include <QxtApplication>
#include <QxtGlobalShortcut>

int main(int argc, char *argv[])
{
    Application a(argc, argv);
    a.setQuitOnLastWindowClosed(false);

    QxtGlobalShortcut shortcut;
    QObject::connect(&shortcut, SIGNAL(activated()), &a, SLOT(hotkeyPressed()));
    shortcut.setShortcut(QKeySequence("Ctrl+Shift+F12"));

    return a.exec();
}
