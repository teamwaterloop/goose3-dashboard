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

WSSClient::WSSClient(const QUrl &url, Data &data) :
    _url(url),
    _data(data)
{
    _socket = new QWebSocket;

    connect(_socket, &QWebSocket::connected, this, &WSSClient::onConnected);
    connect(_socket, &QWebSocket::disconnected, this, &WSSClient::close);

    _socket->open(url);
}

void WSSClient::onConnected()
{
    qDebug() << Q_FUNC_INFO;
    connect(_socket, &QWebSocket::textMessageReceived, this, &WSSClient::onTextMessageReceived);
}

void WSSClient::onTextMessageReceived(QString message)
{
    qDebug() << Q_FUNC_INFO;
    _data.update(message);
}

void WSSClient::close()
{
    _socket->close();
    emit closed();
}

} // namespace wloop
