#include <QCoreApplication>
#include <QJsonObject>
#include <QtNetwork>
#include <QUdpSocket>
#include <QTcpSocket>
#include "myudp.h"
#include "mytcp.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    MyUDP udpclient;
    MyTCP tcpclient;
    tcpclient.sendCommand();
    tcpclient.readTCPData();
  
    return a.exec();
}
