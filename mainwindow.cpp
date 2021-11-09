#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "Tickets.h"
#include "Profiles.h"


#include <QMessageBox>
#include <QListView>
#include <QDebug>
#include <QFile>
#include <QString>
#include <QTextStream>

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


void MainWindow::on_pushButton_16_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}




void MainWindow::on_pushButton_17_clicked()
{
    Agent Agent;
    Agent.userid = ui->lineEdit_userid->text();
    Agent.uname = ui->lineEdit_uname->text();
    Agent.password = ui->lineEdit_password->text();
    Agent.fname = ui->lineEdit_fname->text();
    Agent.lname = ui->lineEdit_lname->text();
    Agent.email = ui->lineEdit_email->text();
    Agent.phnum = ui->lineEdit_phnum->text();
    Agent.cat = ui->lineEdit_cat->text();


    //  File code starts
    QFile agentFile("agents.txt");
    agentFile.open(QIODevice::Append | QIODevice::Text);
    QTextStream out(&agentFile);
    //  File code ends

    out << "User ID: " << Agent.userid << Qt::endl << "Username: " << Agent.uname << Qt::endl << "Password: " << Agent.password << Qt::endl << "First Name: " << Agent.fname
        << Qt::endl << "Last Name: " << Agent.lname << Qt::endl << "Email: " << Agent.email << Qt::endl << "Phone: " << Agent.phnum << Qt::endl << "Category: " << Agent.cat << ('\n') << ('\n');

}


void MainWindow::on_pushButton_18_clicked()
{
    QFile agentFile("agents.txt");
    if(!agentFile.open(QFile::ReadOnly | QFile::Text))
    {
        QMessageBox::warning(this, "File", "File is not open!");
    }
    QTextStream in(&agentFile);
    QString rdata= in.readAll();
    ui->plainTextEdit->setPlainText(rdata);
    agentFile.close();
}


//void MainWindow::on_pushButton_19_clicked()
//{
//    QFile agentFile("C:/Users/GGPC/Documents/build-CS106GroupProject-Desktop_Qt_6_2_0_MinGW_64_bit-Debug/agents.txt");
//    if(!agentFile.open(QFile::ReadWrite | QFile::Text))
//    {
//       QString s;
//       QTextStream t(&agentFile);
//       while(!t.atEnd())
//       {
//           QString line = t.readLine();
//           if(!line.contains("DELETE"))
//               s.append(line + "\n");
//       }
//       agentFile.resize(0);
//       t << s;
//       agentFile.close();

//    }

//}



void MainWindow::on_pushButton_21_clicked()
{
     ui->stackedWidget->setCurrentIndex(4);
}


void MainWindow::on_pushButton_20_clicked()
{
    Agent Agent;

    Agent.uname = ui->lineEdit_6->text();
    Agent.password = ui->lineEdit_7->text();
    QString msg;

    //  File code starts
    QFile agentFile("agents.txt");
    agentFile.open(QFile::ReadOnly | QFile::Text);
    QTextStream in(&agentFile);
    //  File code ends

    while(!in.atEnd())
    {
        QTextStream in(&agentFile);
        QString rdata = in.readAll();

        if(Agent.uname==rdata && Agent.password==rdata)
        {
            msg = "You have successfully logged in";
            ui->stackedWidget->setCurrentIndex(5);
            agentFile.close();
        }
        else
        {
            msg = "Wrong username or password";
        }
    }
    QMessageBox::information(this,"Login",msg);

}

