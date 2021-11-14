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
        TestTicket.fName = ui->lineEdit_3->text();
        TestTicket.lName = ui->lineEdit_8->text();
        TestTicket.Email = ui->lineEdit_4->text();
        TestTicket.Phone = ui->lineEdit_5->text();
        TestTicket.Description = ui->textEdit->toPlainText();

        if(ui->comboBox->currentIndex() == 0) {

            TestTicket.response = 'E';
        } else {
            TestTicket.response = 'P';
        }


        if(ui->comboBox_4->currentIndex() == 0) {

            TestTicket.Category = 'G';

        } else if (ui->comboBox_4->currentIndex() == 1) {

            TestTicket.Category = 'P';

        } else if (ui->comboBox_4->currentIndex() == 2) {

            TestTicket.Category = 'B';
        } else if (ui->comboBox_4->currentIndex() == 3) {

            TestTicket.Category = 'S';
        }






        ui->stackedWidget->setCurrentIndex(5);

        qDebug() << TestTicket.fName;
        qDebug() << TestTicket.lName;
        qDebug() << TestTicket.Email;
        qDebug() << TestTicket.Phone;
        qDebug() << TestTicket.Description;
        qDebug() << TestTicket.response;
        qDebug() << TestTicket.Category;


        //  File code starts
        QFile agentFile("Tickets.txt");
        agentFile.open(QIODevice::Append | QIODevice::Text);
        QTextStream out(&agentFile);
        //  File code ends

        out << TestTicket.fName << (',') << TestTicket.lName << (',') << TestTicket.Email << (',') << TestTicket.Email
            << (',') << TestTicket.Phone << (',') << TestTicket.Description << (',') << TestTicket.response << (',') << TestTicket.Category << Qt::endl;
     //Needs QMessagebox for successfull creation and failure.


    }

}





void MainWindow::on_pushButton_16_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}




void MainWindow::on_pushButton_17_clicked()
{    
    Agent Agent;
    Agent.userid = ui->lineEdit_userid->text();
    Agent.uname = ui->lineEdit_fname->text();
    Agent.password = ui->lineEdit_lname->text();
    Agent.fname = ui->lineEdit_uname->text();
    Agent.lname = ui->lineEdit_password->text();
    Agent.email = ui->lineEdit_email->text();
    Agent.phnum = ui->lineEdit_phnum->text();
    ui->comboBox_2->currentText();

     ui->lineEdit_userid->clear();
     ui->lineEdit_fname->clear();
     ui->lineEdit_lname->clear();
     ui->lineEdit_uname->clear();
     ui->lineEdit_password->clear();
     ui->lineEdit_email->clear();
     ui->lineEdit_phnum->clear();


    //  File code starts
    QFile agentFile("agents.txt");
    agentFile.open(QIODevice::Append | QIODevice::Text);
    QTextStream out(&agentFile);
    //  File code ends

      out << Agent.userid << (',') << Agent.fname << (',') << Agent.lname << (',') << Agent.uname
        << (',') << Agent.password << (',') << Agent.email << (',') << Agent.phnum << (',') << ui->comboBox_2->currentText() << Qt::endl;


      QMessageBox::information(this, "Agent Creation", "New Agent Created");

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
        QString line = in.readLine();
        QStringList data = line.split(",");

        if(Agent.uname==data.at(3) && Agent.password==data.at(4))
        {
            msg = "You have successfully logged in";
            ui->stackedWidget->setCurrentIndex(5);
            agentFile.close();
        }
        else
        {
            msg = "Invalid username or password";
        }
    }

}

void MainWindow::on_pushButton_18_clicked()
{
    QFile agentFile("agents.txt");
    if(!agentFile.open(QFile::ReadOnly | QFile::Text))
    {
        QMessageBox::warning(this, "Agents File", "File is not open!");
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











