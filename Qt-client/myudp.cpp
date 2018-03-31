#include "myudp.h"

MyUDP::MyUDP (QObject *parent) : QObject(parent)
{
    //create socket
    udpsocket = new QUdpSocket(this);
    udpaddress.setAddress("127.0.0.1");

    //bind socket to an address and port using bind()
    //udpsocket->bind(QHostAddress::LocalHost, 5007, QUdpSocket::ShareAddress);

    //Q_ASSERT(udpsocket->joinMulticastGroup(QHostAddress::LocalHost));

    connect (udpsocket, SIGNAL(readyRead()), this, SLOT(readyRead()));
    Q_ASSERT(udpsocket->bind(QHostAddress::LocalHost, 65000));
}

void MyUDP::readyRead()
{
    QByteArray buffer;
    //qDebug() << buffer.size();
    QHostAddress sender;
    quint16 senderPort;

    while (udpsocket->hasPendingDatagrams()) {
        buffer.resize(udpsocket->pendingDatagramSize());
        udpsocket->readDatagram(buffer.data(), buffer.size(), &sender, &senderPort);

        qDebug() << "Message from: " << sender.toString();
        qDebug() << "Message port: " << senderPort;
        qDebug() << "Message: " << buffer;
    }
}
