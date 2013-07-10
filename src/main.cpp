#include "application.h"
#include "mainwindow.h"

#include <QxtApplication>
#include <QxtGlobalShortcut>

int main(int argc, char *argv[])
{
    Application a(argc, argv);
    a.setQuitOnLastWindowClosed(false);

    QxtGlobalShortcut shortcut;
    QObject::connect(&shortcut, SIGNAL(activated()), &a, SLOT(hotkeyPressed()));
    shortcut.setShortcut(QKeySequence("Ctrl+C+Q"));

    return a.exec();
}
