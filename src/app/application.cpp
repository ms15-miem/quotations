#include "application.h"
#include "IExamplePlugin.h"

#include <QMessageBox>
#include <QClipboard>
#include <QPluginLoader>
#include <QDebug>

Application::Application(int argc, char *argv[]) :
    QApplication(argc, argv)
{
    pluginsDir = QDir(qApp->applicationDirPath());

#if defined(Q_OS_WIN)
    if (pluginsDir.dirName().toLower() == "debug" || pluginsDir.dirName().toLower() == "release")
        pluginsDir.cdUp();
#elif defined(Q_OS_MAC)
    if (pluginsDir.dirName() == "MacOS") {
        pluginsDir.cdUp();
        pluginsDir.cdUp();
        pluginsDir.cdUp();
    }
#endif

    pluginsDir.cdUp();
    pluginsDir.cd("plugins");
}

void Application::loadPlugins()
{
    foreach (QObject *plugin, QPluginLoader::staticInstances()) {
        processPlugin(plugin);
    }

    foreach (QString fileName, pluginsDir.entryList(QDir::Files)) {
        QPluginLoader loader(pluginsDir.absoluteFilePath(fileName));
        QObject *plugin = loader.instance();
        if (plugin) {
            processPlugin(plugin);
        }
        else {
            qDebug() << loader.errorString();
        }
    }
}

void Application::processPlugin(QObject *plugin)
{
    Q_ASSERT(plugin);

    IExamplePlugin *examplePlugin = qobject_cast<IExamplePlugin *>(plugin);
    if (examplePlugin) {
        QString text = examplePlugin->doSomething(123); // text = "123"
        qDebug() << text;
    }
}

void Application::hotkeyPressed()
{
    //unfortunately, this does not work
    //QString selection = globalSelectionHandler::getGlobalMouseSelection();

    //so not preserving clipboard
    QString selection = QApplication::clipboard()->text();

    QMessageBox::information(0, "Quotations", selection);
}
