/*****************************************************
 * This file is part of Waterloop                    *
 * Copyright 2018 Mohammed Nafees <hello@mnafees.me> *
 *                                                   *
 * main.cpp                                          *
 *****************************************************/

// Project
#include "src/websockets/Data.h"
#include "src/websockets/WSSClient.h"

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
    QGuiApplication::setOrganizationDomain("teamwaterloop.ca");
    QGuiApplication::setWindowIcon(QIcon(":/res/icon.png"));

    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:///qml/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;

    // initalizing socket connection
    QUrl url("ws://localhost:6500");
    wloop::Data data;
    wloop::WSSClient wssClient(url, data);

    return app.exec();
}
