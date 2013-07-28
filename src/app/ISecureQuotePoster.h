#ifndef IQUOTEPOSTER_H
#define IQUOTEPOSTER_H

#include <QtPlugin>
#include <QString>
#include "IAbstractQuotePoster.h"
#include "quote.h"

class ISecureQuotePoster : public IAbstractQuotePoster
{
public:
    virtual ~ISecureQuotePoster(){}

    virtual void test()=0;
    virtual void authenticate()=0;
    virtual void post(Quote &quote)=0;
protected:
    QString user;
    QString password;
};

Q_DECLARE_INTERFACE(ISecureQuotePoster, "ms15-miem.Quotations.ISecureQuotePoster/1.0")

#endif // IQUOTEPOSTER_H
