#ifndef CLIENT_H
#define CLIENT_H

#include <QtCore/QObject>
#include <QtWebSockets/QtWebSockets>
#include "jsonObject.h"


class Client : public QObject
{
    Q_OBJECT
public:
    explicit Client(const QUrl &url, jsonData *model = Q_NULLPTR);

Q_SIGNALS:
    void closed();

private Q_SLOTS:
    void onConnected();
    void onTextMessageReceived(QString message);
    void close();

private:
    QWebSocket m_webSocket;
    QUrl m_url;
    jsonData *m_model;
};

#endif // CLIENT_H
