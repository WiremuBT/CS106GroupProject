#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <stdio.h>
#include <fstream>
#include <cmath>
#include <vector>
#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <algorithm>


#include "ui_mainwindow.h"
#include "Profiles.h"
#include "Tickets.h"



QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:


    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_12_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_16_clicked();

    void on_pushButton_17_clicked();

    void on_pushButton_21_clicked();

    void on_pushButton_24_clicked();

    void on_listWidget_itemClicked(QListWidgetItem *item);

    void on_pushButton_19_clicked();

    void on_pushButton_25_clicked();


    void on_pushButton_11_clicked();

    void on_Reponse_Submit_clicked();

    void on_pushButton_18_clicked();

    void on_Processing_itemClicked(QListWidgetItem *item);

private:
    Ui::MainWindow *ui;

};
#endif // MAINWINDOW_H



