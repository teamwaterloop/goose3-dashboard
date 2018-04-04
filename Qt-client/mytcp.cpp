#include <iostream>
#include <QTextStream>
#include <QTcpServer>
#include "mytcp.h"

MyTCP::MyTCP (QObject *parent) : QObject(parent)
{
    tcpsocket = new QTcpSocket(this);
    connect(tcpsocket, SIGNAL(readyRead()), SLOT(sendCommand()));

//    tcpsocket->connectToHost(tcpaddress, 15000);
//    if (tcpsocket->waitForConnected()) {
//        tcpsocket->write(data);
//    }
}

void MyTCP::readyRead() {
   QTcpServer server;

   if(!server.listen(tcpaddress, 15000)) return;

   QTcpSocket *sock = server.nextPendingConnection();
   if(!sock)  return;

   qDebug("Client connected");
   sock->waitForReadyRead(10000);

   QByteArray response;
   response.resize(10);
   response = sock->readAll();
   qDebug() << "Message from Client: " << response;
}

void MyTCP::sendCommand() {

}
