#include "mytcp.h"

MyTCP::MyTCP (QObject *parent) : QObject(parent)
{
    QByteArray data;

    tcpsocket = new QTcpSocket(this);
    connect(tcpsocket, SIGNAL(readyRead()), SLOT(readTCPData()));

    tcpsocket->connectToHost(tcpaddress, 15000);
    if (tcpsocket->waitForConnected()) {
        tcpsocket->write(data);
    }
}

void MyTCP::readyRead() {
    QByteArray response;
    response.resize(10);
    response = tcpsocket->readAll();
}

void MyTCP::sendCommand() {

}
