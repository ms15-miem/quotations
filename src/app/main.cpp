#include "application.h"

#include <QxtGlobalShortcut>

int main(int argc, char *argv[])
{
    Application a(argc, argv);
    a.loadPlugins();
    a.setQuitOnLastWindowClosed(false);

    QxtGlobalShortcut shortcut;
    QObject::connect(&shortcut, SIGNAL(activated()), &a, SLOT(hotkeyPressed()));
    shortcut.setShortcut(QKeySequence("Ctrl+C+Q"));

    return a.exec();
}
