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
    QUrl url("ws://localhost:8020/pod-data");
    jsonData json("");
    Client(url, &json);

    wloop::MainWindow w;
    w.show();

    return a.exec();
}
