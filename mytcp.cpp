#include <iostream>
#include <QTextStream>
#include <QTcpServer>
#include "mytcp.h"

MyTCP::MyTCP (QObject *parent) : QObject(parent)
{
    tcpsocket = new QTcpSocket(this);
    connect( tcpsocket, SIGNAL(readyRead()), SLOT(readTCPData()) );
    tcpsocket->connectToHost(QHostAddress::LocalHost, 42002);
    if (tcpsocket->waitForConnected()) {
        qDebug("Connected to Host");
    }
}

void MyTCP::readyRead() {
}

void MyTCP::readTCPData() {
    QByteArray data = tcpsocket->readAll();
    if (!data.isNull()){
        qDebug()<<data;
    }
}

void MyTCP::sendCommand() {
    QByteArray command;
    //QDateTime time = QDateTime::currentDateTime();
    command.resize(10);
    command = "test";
    tcpsocket->write(command);

    qDebug() << "Message to Client: " << command;
}
