// Project
#include "MainWindow.h"

// Qt
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    wloop::MainWindow w;
    w.show();

    return a.exec();
}
