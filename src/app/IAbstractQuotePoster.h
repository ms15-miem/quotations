#ifndef IABSTRACTQUOTEPOSTER_H
#define IABSTRACTQUOTEPOSTER_H

#include <QtPlugin>
#include <QString>
#include "quote.h"

class IAbstractQuotePoster
{
public:
    virtual ~IAbstractQuotePoster(){}

    virtual void post(Quote &quote)=0;
};

#endif // IABSTRACTQUOTEPOSTER_H
