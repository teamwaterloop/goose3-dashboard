#ifndef MAINWINDOW_H
#define MAINWINDOW_H

// Self
#include "ui_MainWindow.h"

// Qt
#include <QWidget>

namespace Ui {
    class MainWindow;
}

namespace wloop {

class MainWindow : public QWidget
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
};

}

#endif
