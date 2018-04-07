#include "myudp.h"
#include <QJsonObject>
#include <QJsonParseError>
#include <QJsonArray>
#include <QJsonObject>
#include <QJsonDocument>

MyUDP::MyUDP (QObject *parent) : QObject(parent)
{
    //create socket
    udpsocket = new QUdpSocket(this);
    udpaddress.setAddress("255.255.255.255");

    connect (udpsocket, SIGNAL(readyRead()), this, SLOT(readyRead()));
    Q_ASSERT(udpsocket->bind(QHostAddress::Any, 65000));
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
        //qDebug() << "Message: " << buffer;
        Q_ASSERT (!jsonParse(buffer));
        //qWarning()<<"JSON parse failed. Skipping.";
    }
}

bool MyUDP::jsonParse(QByteArray buffer) {
    QJsonParseError jerror;
    QJsonDocument jsonResponse = QJsonDocument::fromJson(buffer);
    if(!jsonResponse.isNull()) {
        QJsonObject jObj = jsonResponse.object();
        qDebug() << "Size: " << jObj["size"].toString();
        qDebug() << "Name: " << jObj["name"].toString();
        qDebug() << "Time: " << jObj["time"].toString()<<endl;
    }

    if (jerror.error != QJsonParseError::NoError) {
        return false;
    } else {
        return true;
    }
}
