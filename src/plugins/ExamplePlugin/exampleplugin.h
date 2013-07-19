#ifndef EXAMPLEPLUGIN_H
#define EXAMPLEPLUGIN_H

#include "exampleplugin_global.h"

#include <QString>

class EXAMPLEPLUGINSHARED_EXPORT ExamplePlugin
{
public:
    ExamplePlugin();
};

extern "C" EXAMPLEPLUGINSHARED_EXPORT QString exampleFunction();

#endif // EXAMPLEPLUGIN_H
