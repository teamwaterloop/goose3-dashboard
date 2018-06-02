/*****************************************************
 * This file is part of Waterloop                    *
 * Copyright 2018 Mohammed Nafees <hello@mnafees.me> *
 *                                                   *
 * src/MainWindow.cpp                                *
 *****************************************************/

// Self
#include "MainWindow.h"

// Qt
#include <QBoxLayout>

namespace wloop {

MainWindow::MainWindow(Data &data, QWidget *parent)
    : QWidget(parent),
      _data(data),
      _ui(new Ui::MainWindow),
      _tts(0)
{
    _ui->setupUi(this);

    setWindowTitle("Waterloop");
    setWindowIcon(QIcon(":/res/icon.png"));

    _timer = new QTimer(this);
    connect(_timer, SIGNAL(timeout()), this, SLOT(updateUi()));
    _timer->start(1000);

//    auto view = new QQuickView;
//    QWidget *container = QWidget::createWindowContainer(view, this);
//    container->setMinimumSize(200, 200);
//    container->setMaximumSize(200, 200);
//    container->setFocusPolicy(Qt::TabFocus);
//    view->setSource(QUrl("main.qml"));
//    ui->verticalLayout->addWidget(container);
}

MainWindow::~MainWindow()
{
    delete _timer;
    delete _ui;
}

void MainWindow::updateUi()
{
    _ui->velocity->setText(QString::number(_data.velocity()));
    _ui->velocity->setAlignment(Qt::AlignCenter);
    _ui->distance->setText(QString::number(_data.distance()));
    _ui->distance->setAlignment(Qt::AlignCenter);
    _ui->acceleration->setText(QString::number(_data.acceleration()));
    _ui->acceleration->setAlignment(Qt::AlignCenter);
    _ui->propulsionTemperature->setText(QString::number(_data.propulsionTemp()));
    _ui->propulsionTemperature->setAlignment(Qt::AlignCenter);
    _ui->brakingTemperature->setText(QString::number(_data.brakingTemp()));
    _ui->brakingTemperature->setAlignment(Qt::AlignCenter);
    _ui->motherboardTemperature->setText(QString::number(_data.motherboardTemp()));
    _ui->motherboardTemperature->setAlignment(Qt::AlignCenter);
    _ui->tts->setText(QString::number(_tts++) + " s");
    _ui->tts->setAlignment(Qt::AlignCenter);
    update();
}

}
