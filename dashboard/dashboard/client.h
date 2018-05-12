#ifndef CLIENT_H
#define CLIENT_H

#include <QtCore/QObject>
#include <QtWebSockets/QWebSocket>
#include "jsonObject.h"

class Client : public QObject
{
    Q_OBJECT
public:
    explicit Client(const QUrl &url, jsonObject *model = Q_NULLPTR);

Q_SIGNALS:
    void closed();

private Q_SLOTS:
    void onConnected();
    void onTextMessageReceived(QString message);

private:
    QWebSocket m_webSocket;
    QUrl m_url;
    jsonObject *model;
};

#endif // CLIENT_H
