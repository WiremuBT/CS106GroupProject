#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "ui_login.h"
#include "Tickets.h"
#include "Profiles.h"


#include <QMessageBox>
#include <QListView>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->stackedWidget->setCurrentIndex(0);
}

MainWindow::~MainWindow()
{
    delete ui;
}










void MainWindow::on_pushButton_2_clicked()
{

    ui->stackedWidget->setCurrentIndex(1);

}


void MainWindow::on_pushButton_clicked()
{


    ui->stackedWidget->setCurrentIndex(2);
}


void MainWindow::on_pushButton_3_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}


void MainWindow::on_pushButton_4_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}


void MainWindow::on_pushButton_5_clicked()
{
    QString Username = ui->lineEdit->text();
       QString Password = ui->lineEdit_2->text();
       Admin Admin;
       Admin.Username = "admin";
       Admin.Password = "admin";
       if ((Username==Admin.Username)&&(Password==Admin.Password)) {

       QMessageBox::information(this,"Login","Successfull!!!");
       ui->stackedWidget->setCurrentIndex(3);
}
}

void MainWindow::on_pushButton_12_clicked()
{
    {
        ui->stackedWidget->setCurrentIndex(1);
    }
}


void MainWindow::on_pushButton_6_clicked()
{
    {
        Ticket TestTicket;
        TestTicket.Name = ui->lineEdit_3->text();
        TestTicket.Email = ui->lineEdit_4->text();
        TestTicket.Phone = ui->lineEdit_5->text();
        ui->stackedWidget->setCurrentIndex(4);

        qDebug() << TestTicket.Name;
        qDebug() << TestTicket.Email;
        qDebug() << TestTicket.Phone;
    }

}


void MainWindow::on_pushButton_13_clicked()
{
    ui->stackedWidget_2->setCurrentIndex(0);







}

