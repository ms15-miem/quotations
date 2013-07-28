#include "netclient.h"
#include <QDebug>
#include <QtNetwork/QHostAddress>
#include <QtNetwork/QHostInfo>

NetClient::NetClient() : blockSize(0)
{
    tcpSocket = new QTcpSocket(this);
    connect(tcpSocket, SIGNAL(connected()), SLOT(slotConnected()));
    connect(tcpSocket, SIGNAL(readyRead()), SLOT(getResponse()));
    connect(tcpSocket, SIGNAL(error(QAbstractSocket::SocketError)),
            SLOT(netError(QAbstractSocket::SocketError)));
}

void NetClient::~NetClient()
{
    delete tcpSocket;
}

void NetClient::slotConnected()
{
    emit signalConnected();
}

void NetClient::connectToServer(const QString &host, qint16 port,
                                HostIdentifierType identType)
{
    QHostAddress address;
    if (identType == HostName)
    {
        QHostInfo host = QHostInfo::fromName(hostName);
        if (host.error() != QHostInfo::NoError)
        {
            qDebug() << host.errorString();
            return;
        }
        else
        {
            address = host.addresses().first();
        }
    }
    else
    {
        if (!address.setAddress(host))
        {
            qDebug() << "Setting address failed" << endl;
            return;
        }
    }

    tcpSocket->connectToHost(address, port);
}
void NetClient::getResponse()
{
    QDataStream server(tcpSocket);

    if (blockSize == 0)
    {
       if (tcpSocket->bytesAvailable() < (qint16)sizeof(qint16))
           return;
       server >> blockSize;
    }

    if (tcpSocket->bytesAvailable() < blockSize)
        return;

    QString response;
    server >> response;

    processResponse(response);
}

void NetClient::send(QString &msg)
{
    if (tcpSocket->state() == QAbstractSocket::ConnectedState)
    {
        QTextStream server(tcpSocket);
        server << msg;
    }
    else
    {
        qDebug() << "Cannot send message: not connected" << endl;
    }
}

void NetClient::netError(QAbstractSocket::SocketError err)
{
    qDebug() << "Net error occured" << endl;
}

void NetClient::disconnectFromServer()
{
    tcpSocket->disconnectFromHost();
}
