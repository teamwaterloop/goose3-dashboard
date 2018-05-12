#include "client.h"
#include "jsonObject.h"
#include <QtCore/QDebug>
#include <QDebug>

QT_USE_NAMESPACE

Client::Client(const QUrl &url, jsonData *model) :
    m_url(url),
    m_model(model)
{
    connect(&m_webSocket, &QWebSocket::connected, this, &Client::onConnected);
    //if (!m_webSocket.isValid()) qDebug() << m_webSocket.error();
    //connect(&m_webSocket, QOverload<QAbstractSocket::SocketError>::of(&QWebSocket::error),
      //  [=](QAbstractSocket::SocketError error){ qDebug() << "error connecting"; });
    connect(&m_webSocket, &QWebSocket::disconnected, this, &Client::close);
    connect(this, &Client::close, this, &Client::closed);
    m_webSocket.open(QUrl(url));
    qDebug() << url.toString();
    qDebug() << "constructor";
}

void Client::onConnected()
{
    //qDebug() << "connected";
    connect(&m_webSocket, &QWebSocket::textMessageReceived,
            this, &Client::onTextMessageReceived);
    //qDebug() << "connected";
    //m_webSocket.sendTextMessage(QStringLiteral("Hello, world!"));
}

void Client::onTextMessageReceived(QString message)
{
    qDebug() << message;
    //model->updateModel(message);
}

void Client::close(){ m_webSocket.close(); }
