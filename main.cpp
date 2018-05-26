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
//    QUrl url = QUrl("wss://wloop2.localtunnel.me");
//    jsonData json("");
//    Client client(url, &json);

    wloop::MainWindow w;
    w.show();

//    QObject::connect(&client, &Client::closed, &a, &QApplication::quit);

    return a.exec();
}
