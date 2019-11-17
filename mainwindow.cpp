#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "logger.h"
#include <QString>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    Logger::Regist(0,[&](QString str)
    {
        ui->textBrowser->append(str);
    });
}

MainWindow::~MainWindow()
{
    delete ui;
}

