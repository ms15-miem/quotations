#ifndef IEXAMPLEPLUGIN_H
#define IEXAMPLEPLUGIN_H

#include <QtPlugin>

class IExamplePlugin
{
public:
    virtual ~IExamplePlugin()=0;
    virtual QString doSomething(int value)=0;
};

Q_DECLARE_INTERFACE(IExamplePlugin,
                    "ms15-miem.Quotations.IExamplePlugin/1.0")

#endif // IEXAMPLEPLUGIN_H
