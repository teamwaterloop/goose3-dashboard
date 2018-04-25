#include <QCoreApplication>
#include <QJsonObject>
#include <QtNetwork>
#include <QUdpSocket>
#include <QTcpSocket>
#include "myudp.h"
#include "mytcp.h"

int main(int argc, char *argv[])
{
//    QCoreApplication a(argc, argv);
//    QUdpSocket udpSocket4;
//    //QString ANY = "0.0.0.0";
//    QHostAddress UDP_IP = "224.1.1.1";
//    int UDP_PORT = 5007;

//    udpSocket4.bind(QHostAddress::AnyIPv4, UDP_PORT, QUdpSocket::ShareAddress);
//    udpSocket4.joinMulticastGroup(UDP_IP);





//    int x=343;
//    QString str = "Hello World";
//    qDebug()<< str << x<<"lalalaa";

    QCoreApplication a(argc, argv);
    MyUDP udpclient;
    MyTCP tcpclient;
    udpclient.readyRead();
    tcpclient.sendCommand();
    tcpclient.readTCPData();

    return a.exec();
}
