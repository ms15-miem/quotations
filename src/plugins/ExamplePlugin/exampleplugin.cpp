#include "exampleplugin.h"

ExamplePlugin::ExamplePlugin()
{
}

QString ExamplePlugin::doSomething(int value)
{
    return QString::number(value);
}

Q_EXPORT_PLUGIN2(example, ExamplePlugin)
