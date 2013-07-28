#include "application.h"
#include "ISecureQuotePoster.h"

#include <QMessageBox>
#include <QClipboard>
#include <QPluginLoader>
#include <QDebug>

#include "quote.h"

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

    ISecureQuotePoster *examplePlugin = qobject_cast<ISecureQuotePoster *>(plugin);
    if (examplePlugin) {
       examplePlugin->test();
    }
}

void Application::hotkeyPressed()
{
    Quote q(QApplication::clipboard()->text());

    QMessageBox::information(0, "Quotations", q.getText());
}
