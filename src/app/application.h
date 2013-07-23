#ifndef APPLICATION_H
#define APPLICATION_H

#include <QApplication>
#include <QDir>

class Application : public QApplication
{
    Q_OBJECT
public:
    explicit Application(int argc, char *argv[]);
    void loadPlugins();

private:
    void processPlugin(QObject *plugin);
    QDir pluginsDir;

signals:
    
public slots:
    void hotkeyPressed();
};

#endif // APPLICATION_H
