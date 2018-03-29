#ifndef CLIENT_H
#define CLIENT_H

#include <QHostAddress>
#include <QUdpSocket>

class QLabel;

class Client : public QDialog
{
    Q_OBJECT

public:
    explicit Client(QWidget *parent = nullptr);

private slots:
    void processPendingDatagrams();

private:
    QLabel *statusLabel = nullptr;
    QUdpSocket udpSocket4;
    QHostAddress UDP_IP;
};

#endif // CLIENT_H
