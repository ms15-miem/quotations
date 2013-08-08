#ifndef NETCLIENT_H
#define NETCLIENT_H

#include <QtNetwork/QTcpSocket>

//TODO: Here should be interaction with some server

class NetClient : public QObject
{
    Q_OBJECT
public:

    enum HostIdentifierType
    {
        HostName,
        IpAddress
    };

    NetClient();
    virtual ~NetClient();
    void connectToServer(const QString &hostName, qint16 port,
                         HostIdentifierType identType = HostName);
    void send(QString &msg);
    void disconnectFromServer();

protected:
    virtual void processResponse(QString &response)=0;

signals:
    void signalConnected();

protected slots:
    void getResponse();
    void netError(QAbstractSocket::SocketError err);
    void slotConnected();

private:
    QTcpSocket *tcpSocket;
    qint16 blockSize;
};

#endif // NETCLIENT_H
