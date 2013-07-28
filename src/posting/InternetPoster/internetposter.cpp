#include "internetposter.h"


//Later there will be settings, and they will be initialized in special func
InternetPoster::InternetPoster(QString &srv, qint16 prt, NetClient::HostIdentifierType identType)
    : NetClient(), server(srv), port(prt), ident_type(identType), state(StateIdle)
{}

void InternetPoster::setLoginData(QString &usr, QString &pass)
{
    user = usr;
    password = pass;
}

InternetPoster::State InternetPoster::getState()
{
    return state;
}

bool InternetPoster::isAuthenticated()
{
    return authenticated;
}

void InternetPoster::setAuthenticated(bool auth)
{
    authenticated = auth;
}

void InternetPoster::authenticate()
{
    QString authRequest = getAuthRequestString();
    if (authRequest != "")
    {
        state = StateAuthenticating;
        connectToServer(server, port, ident_type);
        send(authRequest);
    }
}

void InternetPoster::post(Quote &quote)
{
    QString postRequest = getPostRequestString(quote);
    if (postRequest != "")
    {
        state = StateAuthenticating;
        connectToServer(server, port, ident_type);
        send(postRequest);
    }
}

void InternetPoster::processResponse(QString &response)
{
    if (state == InternetPoster::StateAuthenticating)
    {
        processAuthResponse(response);
    }
    else if (state == InternetPoster::StatePosting)
    {
        processPostResponse(response);
    }
    else
    {
        qDebug() << "Response to unknown request" << endl;
    }

    disconnectFromServer();
    state = InternetPoster::StateIdle;
}

Q_EXPORT_PLUGIN2(ap_internetposter, InternetPoster)
