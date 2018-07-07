/*****************************************************
 * This file is part of Waterloop                    *
 * Copyright 2018 Mohammed Nafees <hello@mnafees.me> *
 *                                                   *
 * src/websockets/WSSClient.h                        *
 *****************************************************/

#ifndef WLOOP_WSSCLIENT_H
#define WLOOP_WSSCLIENT_H

// Project
#include "Data.h"
#include "logger.h"

// Qt
#include <QObject>
#include <QtWebSockets/QtWebSockets>

// std
#include <memory>

namespace wloop {

class WSSClient : public QObject
{
    Q_OBJECT

public:
    explicit WSSClient(const QUrl &url, Data &data, Logger &log);
    bool sendMessage(QByteArray message);

signals:
    void closed();

private slots:
    void onConnected();
    void onTextMessageReceived(QString message);
    void close();

private:
    QWebSocket* _socket;
    Logger &_log;
    QUrl _url;
    Data& _data;
};

} // namespace wloop

#endif // WLOOP_WSSCLIENT_H
