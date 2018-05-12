#include "client.h"
#include "jsonObject.h"
#include <QtCore/QDebug>

QT_USE_NAMESPACE

Client::Client(const QUrl &url, jsonObject *model) :
    jsonObject(model),
    m_url(url),
{
    connect(&m_webSocket, &QWebSocket::connected, this, &EchoClient::onConnected);
    connect(&m_webSocket, &QWebSocket::disconnected, this, &EchoClient::closed);
    m_webSocket.open(QUrl(url));
}

void Client::onConnected()
{
    connect(&m_webSocket, &QWebSocket::textMessageReceived,
            this, &EchoClient::onTextMessageReceived);
    //m_webSocket.sendTextMessage(QStringLiteral("Hello, world!"));
}

void Client::onTextMessageReceived(QString message)
{
    model.updateModel(message);
    //m_webSocket.close();
}
