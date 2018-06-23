/*****************************************************
 * This file is part of Waterloop                    *
 * Copyright 2018 Mohammed Nafees <hello@mnafees.me> *
 *                                                   *
 * main.cpp                                          *
 *****************************************************/

// Project
#include "src/websockets/Data.h"
#include "src/websockets/WSSClient.h"
#include "src/websockets/Commands.h"
#include "src/websockets/logger.h"

// Qt
#include <QUrl>
#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QIcon>

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_DisableShaderDiskCache);
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);
    QGuiApplication::setApplicationName("Goose Dashboard");
    QGuiApplication::setOrganizationName("Waterloop");
    QGuiApplication::setOrganizationDomain("waterloop.ca");
    QGuiApplication::setWindowIcon(QIcon(":/res/icon.png"));

    wloop::Logger log("test", "csv");

    QObject::connect(&app, SIGNAL(aboutToQuit()), &log, SLOT(destruct()));

    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:///qml/main.qml")));
    QList <QObject *> qmlRoot = engine.rootObjects();
    if (qmlRoot.isEmpty())
        return -1;

    QObject *rootObject = qmlRoot.first();
    QObject *qmlObject = rootObject->findChild<QObject *>("levSwitch");

    // initalizing websocket connection
    QUrl url("ws://localhost:6500/v1/ws");
    wloop::Data data;
    wloop::WSSClient wssClient(url, data, log);
    wloop::Commands cmd(wssClient, log);

    QObject::connect(qmlObject, SIGNAL(levitationChanged(QVariant)), &cmd, SLOT(levChanged(QVariant)));

    return app.exec();
}
