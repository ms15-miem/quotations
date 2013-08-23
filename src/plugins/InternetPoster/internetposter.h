#ifndef INTERNETPOSTER_H
#define INTERNETPOSTER_H

#include "ISecureQuotePoster.h"
#include "NetClient/netclient.h"

class InternetPoster :public NetClient, public ISecureQuotePoster
{
    Q_OBJECT
    Q_INTERFACES(ISecureQuotePoster)

public:

    enum State
    {
        StateIdle,
        StateAuthenticating,
        StatePosting
    };

    InternetPoster(const QString &srv, qint16 prt, NetClient::HostIdentifierType identType = NetClient::HostName);

    void setLoginData(QString &usr, QString &pass);
    State getState();
    bool isAuthenticated();

    void authenticate();
    void post(const Quote &quote);
    void processResponse(const QString &response);

protected:
    void setAuthenticated(bool auth);

    virtual QString getAuthRequestString()=0;
    virtual QString getPostRequestString(const Quote &quote)=0;

    virtual void parseResponse(const QString &response)=0;

    virtual bool requestSuccessful(QString &errortext)=0;
    virtual void processAuthResponse()=0;
    virtual void processPostResponse()=0;

private:
    const QString&                  server;
    qint16                          port;
    NetClient::HostIdentifierType   ident_type;
    State                           state;
    bool                            authenticated;
};

#endif // INTERNETPOSTER_H
