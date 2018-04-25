#ifndef MYTCP_H
#define MYTCP_H

#include <QObject>
#include <QHostAddress>
#include <QTcpSocket>
#include <QTcpServer>

class MyTCP : public QObject
{
    Q_OBJECT
public:
    explicit MyTCP(QObject *parent = 0);
    void sendCommand();

signals:

public slots:
    void readyRead();
    void readTCPData();


private:
    QHostAddress tcpaddress;
    QTcpSocket *tcpsocket;


};

#endif // MYTCP_H
