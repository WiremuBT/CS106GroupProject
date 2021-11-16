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
#include <vector>
#include <stdlib.h>
#include <QDateTime>

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

        QDateTime date = QDateTime::currentDateTime();
        QString formatTime = date.toString("dd.MM.yyyy hh:mm:ss");


        Ticket TestTicket;
        TestTicket.fName = ui->lineEdit_3->text();
        TestTicket.lName = ui->lineEdit_8->text();
        TestTicket.Email = ui->lineEdit_4->text();
        TestTicket.Phone = ui->lineEdit_5->text();
        TestTicket.Description = ui->textEdit->toPlainText();
        TestTicket.Description.remove(',');
        TestTicket.Time_Stamp = formatTime;
        TestTicket.Support_Level = "O";






        if(ui->comboBox->currentIndex() == 0) {

            TestTicket.response = "E";
        } else {
            TestTicket.response = "P";
        }


        if(ui->comboBox_4->currentIndex() == 0) {

            TestTicket.Category = "G";

        } else if (ui->comboBox_4->currentIndex() == 1) {

            TestTicket.Category = "P";

        } else if (ui->comboBox_4->currentIndex() == 2) {

            TestTicket.Category = "B";
        } else if (ui->comboBox_4->currentIndex() == 3) {

            TestTicket.Category = "S";
        }

        ui->stackedWidget->setCurrentIndex(5);
    /*
        qDebug() << TestTicket.fName;
        qDebug() << TestTicket.lName;
        qDebug() << TestTicket.Email;
        qDebug() << TestTicket.Phone;
        qDebug() << TestTicket.Description;
        qDebug() << TestTicket.response;
        qDebug() << TestTicket.Category;
*/

        //  File code starts
        QFile agentFile("Tickets.txt");
        agentFile.open(QIODevice::Append | QIODevice::Text);
        QTextStream out(&agentFile);
        //  File code ends

        out << TestTicket.fName << (',') << TestTicket.lName << (',') << TestTicket.Email << (',')
             << TestTicket.Phone << (',') << TestTicket.Description << (',') << TestTicket.response << (',') << TestTicket.Category << (',')
             << TestTicket.Time_Stamp << (',') << TestTicket.Support_Level << Qt::endl;

        //Needs QMessagebox for successfull creation and failure.

        //~~~~~~File code starts~~~~~~~~~~~~
         QFile userFile("Tickets.txt");
         userFile.open(QIODevice::ReadOnly | QIODevice::Text);
         QTextStream in(&userFile);
         //~~~~~~File code ends~~~~~~~~~~~~
        QVector<Ticket> TicketV;
         while(!in.atEnd())
         {
             QString line = in.readLine();
             QStringList data= line.split(",");
           Ticket Temp;

            Temp.fName = data.at(0);
            Temp.lName = data.at(1);
            Temp.Email = data.at(2);
            Temp.Phone = data.at(3);
            Temp.Description = data.at(4);
            Temp.response = data.at(5);
            Temp.Category = data.at(6);
            Temp.Time_Stamp = data.at(7);
            Temp.Support_Level = data.at(8);

            TicketV.push_back(Temp);




          }

         qDebug() << TicketV[0].fName;
         qDebug() << TicketV[0].lName;
         qDebug() << TicketV[0].Email;
         qDebug() << TicketV[0].Phone;
         qDebug() << TicketV[0].Description;
         qDebug() << TicketV[0].response;
         qDebug() << TicketV[0].Category;

        ui->label_21->setText("Ticket has been successfully Generated. A confirmation email has been sent too..");
        ui->label_23->setText(TestTicket.Email);








    }








void MainWindow::on_pushButton_16_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}




void MainWindow::on_pushButton_17_clicked()
{    
    Agent Agent;
    Agent.userid = ui->lineEdit_userid->text();
    Agent.fname = ui->lineEdit_fname->text();
    Agent.lname = ui->lineEdit_lname->text();
    Agent.uname = ui->lineEdit_uname->text();
    Agent.password = ui->lineEdit_password->text();
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
    agentFile.close();

      agentFile.open(QFile::ReadOnly | QFile::Text);
      QTextStream in(&agentFile);

//      while(!in.atEnd())
//      {
//          QString line = in.readLine();
//          QStringList data = line.split(",");

//          if(Agent.uname==data.at(3) && (Agent.password==data.at(4)))
//          {
//              QMessageBox::information(this, "Agent Creation", "Agent Username Already Exists!");

//          }
//          else
//          {
//              QMessageBox::information(this, "Agent Creation", "New Agent Created");
//              agentFile.close();
//          }
//      }


}

void MainWindow::on_pushButton_20_clicked()
{
    Agent Agent;

    Agent.uname = ui->lineEdit_6->text();
    Agent.password = ui->lineEdit_7->text();

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
            QMessageBox::information(this, "Agent Login", "Login Successful!");
            ui->stackedWidget->setCurrentIndex(5);
            agentFile.close();
        }
        else
        {
            QMessageBox::information(this, "Agent Login", "Invalid Username/Password try again");
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


void MainWindow::on_pushButton_21_clicked()
{
     ui->stackedWidget->setCurrentIndex(4);
}



void MainWindow::on_pushButton_19_clicked()
{
    QFile agentFile("agents.txt");
    if(!agentFile.open(QFile::ReadOnly | QFile::Text))
    {
        QMessageBox::warning(this, "File", "File is not open");
    }
    QTextStream in(&agentFile);
    QString rdata= in.readAll();
    ui->plainTextEdit_2->setPlainText(rdata);
    agentFile.close();
}


void MainWindow::on_pushButton_13_clicked()
{
    QFile agentFile("agents.txt");
    if(!agentFile.open(QFile::WriteOnly|QFile::Text))
    {
        QMessageBox::warning(this, "File", "File is not open");
    }
    QTextStream out(&agentFile);
    QString data = ui->plainTextEdit_2->toPlainText();
    out << data;
    agentFile.flush();
    agentFile.close();
}


void MainWindow::on_pushButton_24_clicked()
{
    ui->stackedWidget->setCurrentIndex(4);

    //~~~~~~File code starts~~~~~~~~~~~~
     QFile userFile("Tickets.txt");
     userFile.open(QIODevice::ReadOnly | QIODevice::Text);
     QTextStream in(&userFile);
     //~~~~~~File code ends~~~~~~~~~~~~
    QVector<Ticket> TicketV;

     while(!in.atEnd())
     {
         QString line = in.readLine();
         QStringList data= line.split(",");
            Ticket Temp;

        Temp.fName = data.at(0);
        Temp.lName = data.at(1);
        Temp.Email = data.at(2);
        Temp.Phone = data.at(3);
        Temp.Description = data.at(4);
        Temp.response = data.at(5);
        Temp.Category = data.at(6);
        Temp.Time_Stamp = data.at(7);
        Temp.Support_Level = data.at(8);

        TicketV.push_back(Temp);

      }

     for(int i = 0; i<TicketV.size(); i++)
         {

        if (TicketV[i].Support_Level == "O") {
        ui->listWidget->addItem(TicketV[i].fName);
        } else if (TicketV[i].Support_Level == "P") {

            ui->Processing->addItem(TicketV[i].fName);

        } else if (TicketV[i].Support_Level == "C") {

            ui->Closed->addItem(TicketV[i].fName);
        }
}






}







void MainWindow::on_listWidget_itemClicked(QListWidgetItem *item)
{
    int temp = ui->listWidget->row(item);
    qDebug() << ui->listWidget->row(item);


    qDebug() << temp;
    QMessageBox::information(this,"Login", QString::number(temp));
    ui->stackedWidget->setCurrentIndex(6);

    //~~~~~~File code starts~~~~~~~~~~~~
     QFile userFile("Tickets.txt");
     userFile.open(QIODevice::ReadOnly | QIODevice::Text);
     QTextStream in(&userFile);
     //~~~~~~File code ends~~~~~~~~~~~~
    QVector<Ticket> TicketV;

     while(!in.atEnd())
     {
         QString line = in.readLine();
         QStringList data= line.split(",");
            Ticket Temp;

        Temp.fName = data.at(0);
        Temp.lName = data.at(1);
        Temp.Email = data.at(2);
        Temp.Phone = data.at(3);
        Temp.Description = data.at(4);
        Temp.response = data.at(5);
        Temp.Category = data.at(6);
        Temp.Time_Stamp = data.at(7);
        Temp.Support_Level = data.at(8);

        TicketV.push_back(Temp);

      }

    ui->TicketDis->setPlainText(TicketV[temp].Description);
    ui->TicketfName->setText(TicketV[temp].fName);
    ui->TicketlName->setText(TicketV[temp].lName);
    ui->TicketTime->setText(TicketV[temp].Time_Stamp);
    ui->TicketUrgency->setText(TicketV[temp].Description);

}

