/*****************************************************
 * This file is part of Waterloop                    *
 * Copyright 2018 Mohammed Nafees <hello@mnafees.me> *
 *                                                   *
 * src/websockets/WSSClient.cpp                      *
 *****************************************************/

// Self
#include "WSSClient.h"

// Project
#include "Data.h"

// Qt
#include <QDebug>

namespace wloop {

WSSClient::WSSClient(const QUrl &url) :
    _url(url)
{
    _socket = new QWebSocket; // FIXME

    connect(_socket, &QWebSocket::connected, this, &WSSClient::onConnected);
    //if (!m_webSocket.isValid()) qDebug() << m_webSocket.error();
    //connect(&m_webSocket, QOverload<QAbstractSocket::SocketError>::of(&QWebSocket::error),
      //  [=](QAbstractSocket::SocketError error){ qDebug() << "error connecting"; });
    connect(_socket, &QWebSocket::disconnected, this, &WSSClient::close);
    connect(this, &WSSClient::close, this, &WSSClient::closed);
    _socket->open(QUrl(url));
    qDebug() << url.toString();
    qDebug() << "constructor";
}

void WSSClient::onConnected()
{
    //qDebug() << "connected";
    connect(_socket, &QWebSocket::textMessageReceived,
            this, &WSSClient::onTextMessageReceived);
    //qDebug() << "connected";
    //m_webSocket.sendTextMessage(QStringLiteral("Hello, world!"));
}

void WSSClient::onTextMessageReceived(QString message)
{
    qDebug() << message;
    //model->updateModel(message);
}

void WSSClient::close()
{
    _socket->close();
}

} // namespace wloop
