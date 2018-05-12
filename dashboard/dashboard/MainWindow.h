#ifndef MAINWINDOW_H
#define MAINWINDOW_H

// Self
#include "ui_MainWindow.h"

// Qt
#include <QWidget>
#include <QTimer>

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

public Q_SLOTS:
    void updateUi();

private:
    Ui::MainWindow *ui;
    QTimer *timer;
    int tts;
};

}

#endif
