/*****************************************************
 * This file is part of Waterloop                    *
 * Copyright 2018 Mohammed Nafees <hello@mnafees.me> *
 *                                                   *
 * src/MainWindow.h                                  *
 *****************************************************/

#ifndef WLOOP_MAINWINDOW_H
#define WLOOP_MAINWINDOW_H

// UI
#include "ui_MainWindow.h"

// Project
#include "src/websockets/Data.h"

// Qt
#include <QWidget>
#include <QTimer>

// std
#include <memory>

namespace Ui {
    class MainWindow;
}

namespace wloop {

class MainWindow : public QWidget
{
    Q_OBJECT

public:
    MainWindow(Data& data, QWidget *parent = 0);
    ~MainWindow();

public Q_SLOTS:
    void updateUi();

private:
    Ui::MainWindow* _ui;
    QTimer* _timer;
    int _tts;
    Data& _data;
};

} // namespace wloop

#endif // WLOOP_MAINWINDOW_H
