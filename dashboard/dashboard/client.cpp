#include "client.h"
#include "jsonObject.h"
#include <QtCore/QDebug>

QT_USE_NAMESPACE

Client::Client(const QUrl &url, jsonData *model) :
    model(model),
    m_url(url)
{
    connect(&m_webSocket, &QWebSocket::connected, this, &Client::onConnected);
    connect(&m_webSocket, &QWebSocket::disconnected, this, &Client::closed);
    m_webSocket.open(QUrl(url));
}

void Client::onConnected()
{
    connect(&m_webSocket, &QWebSocket::textMessageReceived,
            this, &Client::onTextMessageReceived);
    //m_webSocket.sendTextMessage(QStringLiteral("Hello, world!"));
}

void Client::onTextMessageReceived(QString message)
{
    model->updateModel(message);
    //m_webSocket.close();
}
