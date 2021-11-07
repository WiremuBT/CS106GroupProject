#include "mainwindow.h"
#include "ui_mainwindow.h"


#include <QPixmap>
#include <QPalette>
#include <QPainter>

#include <QListView>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}







void MainWindow::on_pushButton_2_clicked()
{

}

