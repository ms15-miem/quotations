#include "application.h"

#include <QLibrary>
#include <QDebug>

#include <QxtGlobalShortcut>

int main(int argc, char *argv[])
{
    Application a(argc, argv);
    a.setQuitOnLastWindowClosed(false);

    QxtGlobalShortcut shortcut;
    QObject::connect(&shortcut, SIGNAL(activated()), &a, SLOT(hotkeyPressed()));
    shortcut.setShortcut(QKeySequence("Ctrl+C+Q"));

    QLibrary library("/home/narcjkeee/Projects/quotations/src/plugins/build-ExamplePlugin-Qt_4_8_4_qt4_2-Debug/libExamplePlugin.so.1.0.0");
    if (!library.load())
        qDebug() << library.errorString();
    if (library.load())
        qDebug() << "library loaded";

    typedef QString(*ExampleFunction)(void);
    ExampleFunction ef = (ExampleFunction)library.resolve("exampleFunction");
    if (ef) {
        QString msg = ef();
        if (!msg.isEmpty())
            qDebug() << msg;
    }
    else {
        qDebug() << "Could not show message from the loaded library";
    }

    return a.exec();
}
