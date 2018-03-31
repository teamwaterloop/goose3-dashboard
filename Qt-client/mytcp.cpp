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

MyTCP::readyRead() {

}

MyTCP::sendCommand() {

}
