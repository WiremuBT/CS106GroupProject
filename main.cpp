#include "mainwindow.h"
#include <QApplication>


using namespace std;


int main(int argc, char *argv[])
{
    QApplication a(argc, argv); //Created as the QApplication Class
    MainWindow w; //Created as a QObject
    w.show(); //Shows the Window. W is the main window Class that is created.

    return a.exec(); // keeps the Application in an infinte loop to keep it running until told otherwise.
    //Git hub Sucks. It really sucks
}
