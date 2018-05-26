/*****************************************************
 * This file is part of Waterloop                    *
 * Copyright 2018 Mohammed Nafees <hello@mnafees.me> *
 *                                                   *
 * main.cpp                                          *
 *****************************************************/

// Project
#include "src/MainWindow.h"
#include "src/websockets/Data.h"
#include "src/websockets/WSSClient.h"

// Qt
#include <QUrl>
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // initalizing socket connection
    QUrl url("ws://localhost:6500");
    wloop::Data data;
    wloop::WSSClient wssClient(url, data);

    wloop::MainWindow w(data);
    w.show();

    // QObject::connect(&wssClient, &wloop::WSSClient::closed, &a, &QApplication::quit);

    return a.exec();
}
