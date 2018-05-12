// Self
#include "MainWindow.h"

// Qt
#include <QBoxLayout>

namespace wloop {

MainWindow::MainWindow(QWidget *parent)
    : QWidget(parent),
      ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    setWindowTitle("Waterloop");
    setFixedSize(800, 600);
    setWindowIcon(QIcon(":/res/icon.png"));

    //connect();
}

MainWindow::~MainWindow()
{
    delete ui;
}

}
