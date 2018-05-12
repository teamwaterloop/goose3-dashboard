// Project
#include "MainWindow.h"

// Qt
#include <QUrl>
#include <QApplication>
#include "jsonObject.h"
#include "client.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // initalizing socket connection
    QUrl url = QUrl("wss://wloop2.localtunnel.me");
    jsonData json("");
    Client client(url, &json);

    wloop::MainWindow w;
    w.show();

    QObject::connect(&client, &Client::closed, &a, &QApplication::quit);

    return a.exec();
}
