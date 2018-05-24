// Self
#include "MainWindow.h"

// Qt
#include <QBoxLayout>

namespace wloop {

MainWindow::MainWindow(QWidget *parent)
    : QWidget(parent),
      ui(new Ui::MainWindow),
      tts(0)
{
    ui->setupUi(this);

    setWindowTitle("Waterloop");
    //setFixedSize(800, 600);
    setWindowIcon(QIcon(":/res/icon.png"));

    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(updateUi()));
    timer->start(1000);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete timer;
}

void MainWindow::updateUi()
{
//    ui->velocity->setText(QString::number(qrand()));
//    ui->velocity->setAlignment(Qt::AlignCenter);
//    ui->distance->setText(QString::number(qrand()));
//    ui->distance->setAlignment(Qt::AlignCenter);
//    ui->acceleration->setText(QString::number(qrand()));
//    ui->acceleration->setAlignment(Qt::AlignCenter);
//    ui->propulsionTemperature->setText(QString::number(qrand()));
//    ui->propulsionTemperature->setAlignment(Qt::AlignCenter);
//    ui->brakingTemperature->setText(QString::number(qrand()));
//    ui->brakingTemperature->setAlignment(Qt::AlignCenter);
//    ui->motherboardTemperature->setText(QString::number(qrand()));
//    ui->motherboardTemperature->setAlignment(Qt::AlignCenter);
//    ui->tts->setText(QString::number(tts++) + " s");
//    ui->tts->setAlignment(Qt::AlignCenter);
//    update();
}

}
