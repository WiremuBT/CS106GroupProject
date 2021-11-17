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
#include <QUrl>
#include <QtCore>
#include <QDesktopServices>

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
    ui->pushButton_5->setDefault(true);
    ui->pushButton_5->setAutoDefault(false);

    Agent Agent;
    Agent.uname = ui->lineEdit->text();
    Agent.password = ui->lineEdit_2->text();

    if(Agent.uname=="admin" && Agent.password=="admin")
    {
        QMessageBox::information(this,"Login","Successfull");
        ui->stackedWidget->setCurrentIndex(3);
    }

    //File code starts
    QFile agentFile("agents.txt");
    agentFile.open(QFile::ReadOnly | QFile::Text);
    QTextStream in(&agentFile);
    //file code ends

    while(!in.atEnd())
    {
        QString line = in.readLine();
        QStringList data = line.split(",");

        if(Agent.uname==data.at(3) && Agent.password==data.at(4))
        {
            QMessageBox::information(this,"Login","Successfull");
            ui->stackedWidget->setCurrentIndex(4);
        }


    }

    ui->lineEdit->clear();
    ui->lineEdit_2->clear();

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
        TestTicket.Support_Level = "Open";
        if(ui->checkBox->isChecked()) {

          TestTicket.Tags[0] = "Connection";

        }

        if (ui->checkBox_2->isChecked()){

            TestTicket.Tags[1] = "Hardware";

        }

        if (ui->checkBox_3->isChecked()) {

            TestTicket.Tags[2] = "Software";

        }

        if (ui->checkBox_4->isChecked()) {

            TestTicket.Tags[3] = "Login";

        }

        qDebug() << TestTicket.Tags[0];
        qDebug() << TestTicket.Tags[1];
        qDebug() << TestTicket.Tags[2];
        qDebug() << TestTicket.Tags[3];



        if(ui->comboBox->currentIndex() == 0) {

            TestTicket.response = "Email";
        } else {
            TestTicket.response = "Phone";
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
             << TestTicket.Time_Stamp << (',') << TestTicket.Support_Level << (',') << TestTicket.Tags[0] << (',') << TestTicket.Tags[1] << (',') << TestTicket.Tags[2] << (',') << TestTicket.Tags[3] << Qt::endl;

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
            Temp.Tags[0] = data.at(9);
            Temp.Tags[1] = data.at(10);
            Temp.Tags[2] = data.at(11);
            Temp.Tags[3] = data.at(12);
            TicketV.push_back(Temp);




          }

         qDebug() << TicketV[0].fName;
         qDebug() << TicketV[0].lName;
         qDebug() << TicketV[0].Email;
         qDebug() << TicketV[0].Phone;
         qDebug() << TicketV[0].Description;
         qDebug() << TicketV[0].response;
         qDebug() << TicketV[0].Category;
         qDebug() << TicketV[0].Tags[0];
         qDebug() << TicketV[0].Tags[1];
         qDebug() << TicketV[0].Tags[2];
         qDebug() << TicketV[0].Tags[3];

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

    QMessageBox::information(this, "Agent Creation", "New Agent Created Successfully");

}


void MainWindow::on_pushButton_21_clicked()
{
     ui->stackedWidget->setCurrentIndex(2);
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

        if (TicketV[i].Support_Level == "Open") {
        ui->listWidget->addItem(TicketV[i].fName);
        }




            }



    userFile.close();


     QFile userFile2("Processing.txt");
     userFile2.open(QIODevice::ReadOnly | QIODevice::Text);
     QTextStream in2(&userFile2);
     //~~~~~~File code ends~~~~~~~~~~~~
    QVector<Ticket> TicketV2;
    Ticket Temp2;
     while(!in2.atEnd())
     {
         QString line2 = in2.readLine();
         QStringList data2= line2.split(",");


        Temp2.fName = data2.at(0);
        Temp2.lName = data2.at(1);
        Temp2.Email = data2.at(2);
        Temp2.Phone = data2.at(3);
        Temp2.Description = data2.at(4);
        Temp2.response = data2.at(5);
        Temp2.Category = data2.at(6);
        Temp2.Time_Stamp = data2.at(7);
        Temp2.Support_Level = data2.at(8);
        Temp2.Tags2 = data2.at(9);
        Temp2.Urgency = data2.at(10);
        Temp2.Response_Process = data2.at(11);



        qDebug() << Temp2.fName;
        TicketV2.push_back(Temp2);

      }

        for(int i = 0; i<TicketV2.size(); i++) {

        if (TicketV2[i].Support_Level == "Processing") {

            ui->Processing->addItem(TicketV2[i].fName);

        }
        }











        /* (TicketV[i].Support_Level == "Closed") {

            ui->Closed->addItem(TicketV[i].fName);
        }
*/






}



void MainWindow::on_listWidget_itemClicked(QListWidgetItem *item)
{
    QString ExampleEmail = "Hi [Customer], \n\nI'm so sorry that you had a negative experience with [product, service, or company department]. I've looked into the issue, and it seems that [briefly explain the reason for their bad experience, if applicable]. \n\nI've forwarded this issue to [head of the appropriate department], our [person's job title]. In the meantime, I'd like to offer a [discount/refund] for the inconvenience and will be checking in with you in a few days to update you on the status of [issue]. \n\nOnce more, I sincerely apologize for the inconvenience. Please let me know if I can answer any questions, and I'd be happy to help! \n\n[Your name]";


    ui->Response_Edit->setPlainText(ExampleEmail);


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
        Temp.Tags[0] = data.at(9);
        Temp.Tags[1] = data.at(10);
        Temp.Tags[2] = data.at(11);
        Temp.Tags[3] = data.at(12);

        TicketV.push_back(Temp);

      }

    ui->TicketDis->setText(TicketV[temp].Description);
    ui->TicketfName->setText(TicketV[temp].fName);
    ui->TicketlName->setText(TicketV[temp].lName);
    ui->TicketTime->setText(TicketV[temp].Time_Stamp);
    ui->TicketPhone->setText(TicketV[temp].Phone);
    ui->TicketEmail->setText(TicketV[temp].Email);
    ui->TicketResponse->setText(TicketV[temp].response);
    ui->TicketSupport->setText(TicketV[temp].Support_Level);


    QString TagsC;

    TagsC = TicketV[temp].Tags[0] + " " + TicketV[temp].Tags[1] + " " + TicketV[temp].Tags[2] + " " + TicketV[temp].Tags[3];

    ui->TicketTags->setText(TagsC);

    if (TicketV[temp].Category == "B") {

        ui->TicketCategory->setText("Bug Report");

    } else if (TicketV[temp].Category == "P") {

        ui->TicketCategory->setText("Performance Report");
} else if (TicketV[temp].Category == "G") {

        ui->TicketCategory->setText("General Issue");
       } else if (TicketV[temp].Category == "S") {
        ui->TicketCategory->setText("Service Report");
    }


    if ((TicketV[temp].Category == "B")||(TicketV[temp].Category == "P")) {

        TicketV[temp].Urgency = "High";

    } else if (TicketV[temp].Category == "G") {

        TicketV[temp].Urgency = "Medium";


    } else {

        TicketV[temp].Urgency = "Low";

    }

    ui->TicketUrgency->setText(TicketV[temp].Urgency);







}



void MainWindow::on_pushButton_25_clicked()
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


void MainWindow::on_pushButton_19_clicked()
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


void MainWindow::on_pushButton_11_clicked()
{
    QDesktopServices::openUrl(QUrl("http://www.google.com", QUrl::TolerantMode));
}


void MainWindow::on_Reponse_Submit_clicked()
{


    Ticket TestTicket;

    TestTicket.fName = ui->TicketfName->text();
    TestTicket.lName = ui->TicketlName->text();
    TestTicket.Email = ui->TicketEmail->text();
    TestTicket.Phone = ui->TicketPhone->text();
    TestTicket.Description = ui->TicketDis->text();
    TestTicket.Response_Process = ui->Response_Edit->toPlainText();
    TestTicket.Time_Stamp = ui->TicketTime->text();
    TestTicket.Tags2 = ui->TicketTags->text();
    TestTicket.Urgency = ui->TicketUrgency->text();
    TestTicket.Category = ui->TicketCategory->text();
    TestTicket.Support_Level = "Processing";
    TestTicket.response = ui->TicketResponse->text();
    TestTicket.Response_Process.remove(',');
    TestTicket.Response_Process.remove('\n');
    TestTicket.Response_Process.remove('\r');


    //  File code starts
    QFile agentFile("Processing.txt");
    agentFile.open(QIODevice::Append | QIODevice::Text);
    QTextStream out(&agentFile);
    //  File code ends

    out << TestTicket.fName << (',') << TestTicket.lName << (',') << TestTicket.Email << (',')
         << TestTicket.Phone << (',') << TestTicket.Description << (',') << TestTicket.response << (',') << TestTicket.Category << (',')
         << TestTicket.Time_Stamp << (',') << TestTicket.Support_Level << (',') << TestTicket.Tags2 << (',') << TestTicket.Urgency << (',') << TestTicket.Response_Process <<Qt::endl;


    agentFile.close();

   QFile f("Tickets.txt");
   if(f.open(QIODevice::ReadWrite | QIODevice::Text))
   {
       QString s = "";
       QTextStream t(&f);
       while(!t.atEnd())
       {
           QString line = t.readLine();
           if(!line.contains(TestTicket.Email))
               s.append(line + "\n");
       }
       f.resize(0);
       t << s;
       f.close();
   }

ui->stackedWidget->setCurrentIndex(4);






}


void MainWindow::on_pushButton_18_clicked()
{
    ui->stackedWidget->setCurrentIndex(4);
}


void MainWindow::on_Processing_itemClicked(QListWidgetItem *item)
{

    int temp = ui->Processing->row(item);
    qDebug() << ui->Processing->row(item);


    qDebug() << temp;
    QMessageBox::information(this,"Login", QString::number(temp));
    ui->stackedWidget->setCurrentIndex(6);

    //~~~~~~File code starts~~~~~~~~~~~~
     QFile userFile("Processing.txt");
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
            Temp.Tags2 = data.at(9);
            Temp.Urgency = data.at(10);
            Temp.Response_Process = data.at(11);

            TicketV.push_back(Temp);

      }

    ui->TicketDis->setText(TicketV[temp].Description);
    ui->TicketfName->setText(TicketV[temp].fName);
    ui->TicketlName->setText(TicketV[temp].lName);
    ui->TicketTime->setText(TicketV[temp].Time_Stamp);
    ui->TicketPhone->setText(TicketV[temp].Phone);
    ui->TicketEmail->setText(TicketV[temp].Email);
    ui->TicketResponse->setText(TicketV[temp].response);
    ui->TicketSupport->setText(TicketV[temp].Support_Level);
    ui->Response_Edit->setPlainText(TicketV[temp].Response_Process);
    ui->TicketCategory->setText(TicketV[temp].Category);




    ui->TicketTags->setText(TicketV[temp].Tags2);

    if (TicketV[temp].Category == "B") {

        ui->TicketCategory->setText("Bug Report");

    } else if (TicketV[temp].Category == "P") {

        ui->TicketCategory->setText("Performance Report");
} else if (TicketV[temp].Category == "G") {

        ui->TicketCategory->setText("General Issue");
       } else if (TicketV[temp].Category == "S") {
        ui->TicketCategory->setText("Service Report");
    }


    if ((TicketV[temp].Category == "B")||(TicketV[temp].Category == "P")) {

        TicketV[temp].Urgency = "High";

    } else if (TicketV[temp].Category == "G") {

        TicketV[temp].Urgency = "Medium";


    } else {

        TicketV[temp].Urgency = "Low";

    }

    ui->TicketUrgency->setText(TicketV[temp].Urgency);








}

