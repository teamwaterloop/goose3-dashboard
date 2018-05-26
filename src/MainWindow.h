/*****************************************************
 * This file is part of Waterloop                    *
 * Copyright 2018 Mohammed Nafees <hello@mnafees.me> *
 *                                                   *
 * src/MainWindow.h                                  *
 *****************************************************/

#ifndef WLOOP_MAINWINDOW_H
#define WLOPP_MAINWINDOW_H

// UI
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
    ~MainWindow() = default;

public Q_SLOTS:
    void updateUi();

private:
    Ui::MainWindow* _ui;
    QTimer* _timer;
    int _tts;
};

} // namespace wloop

#endif // WLOOP_MAINWINDOW_H
