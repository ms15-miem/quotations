#ifndef EXAMPLEPLUGIN_H
#define EXAMPLEPLUGIN_H

#include "IExamplePlugin.h"

#include <QObject>

class ExamplePlugin : public QObject, public IExamplePlugin
{
    Q_OBJECT
    Q_INTERFACES(IExamplePlugin)

public:
    ExamplePlugin();

    QString doSomething(int value);
};

#endif // EXAMPLEPLUGIN_H
