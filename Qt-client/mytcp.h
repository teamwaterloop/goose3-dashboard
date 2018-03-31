#ifndef MYTCP_H
#define MYTCP_H

#include <QObject>
#include <QHostAddress>
#include <QTcpSocket>

class MyTCP : public QObject
{
    Q_OBJECT
public:
    explicit MyTCP(QObject *parent = 0);

signals:

public slots:
    void readyRead();



private:
    QHostAddress tcpaddress;
    QTcpSocket *tcpsocket;
    void sendCommand();
};

#endif // MYTCP_H
