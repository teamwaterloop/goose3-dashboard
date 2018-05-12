// Project
#include "MainWindow.h"

// Qt
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // initalizing socket connection
    QUrl url("ws://localhost:8020/pod-data");
    jsonObject json("");
    Client(url, json);

    wloop::MainWindow w;
    w.show();

    return a.exec();
}
