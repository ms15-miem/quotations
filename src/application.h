#ifndef APPLICATION_H
#define APPLICATION_H

#include <QxtApplication>

class Application : public QxtApplication
{
    Q_OBJECT
public:
    explicit Application(int argc, char *argv[]);
    
signals:
    
public slots:
    void hotkeyPressed();
    void copyExecuted();
};

#endif // APPLICATION_H
