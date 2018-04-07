#include <iostream>
#include <QTextStream>
#include <QTcpServer>
#include <QDateTime>
#include "mytcp.h"

MyTCP::MyTCP (QObject *parent) : QObject(parent)
{
    tcpsocket = new QTcpSocket(this);
    tcpsocket->connectToHost(QHostAddress::LocalHost, 42002);
}

void MyTCP::connectTCP() {
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
