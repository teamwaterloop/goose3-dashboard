#ifndef MYUDP_H
#define MYUDP_H

#include <QObject>
#include <QUdpSocket>
#include <QHostAddress>

class MyUDP : public QObject
{
    Q_OBJECT
public:
    explicit MyUDP(QObject *parent = 0);

signals:

public slots:
    void readyRead();

private:
    QHostAddress udpaddress;
    QUdpSocket *udpsocket;
};

#endif // MYUDP_H
