#ifndef PROFILES_H
#define PROFILES_H

#include <QMainWindow>


class profile {
public:
    int id;
    QString Username, Password;

    void readUsername() {


    }
    void readPassword() {


    }
    void showUsername() {


    }

    void LoginValidation() {


    }

};

class Admin : public profile {
public:
    int admin_id;


    void readUsername() {


    }
    void readPassword() {


    }
    void showUsername() {


    }
    void LoginValidation() {


    }
    void createAdmin() {


    }




};


class Agent : public profile {
public:
    int Agent_id;
    char category;
    QString userid, uname, password, fname, lname, email, phnum, cat;
    int Closed_count, Open_count, Stats_fact;


    void readUsername() {


    }
    void readPassword() {


    }
    void showUsername() {


    }
    void LoginValidation() {


    }
    void createAgent() {


    }
    void CreateEmail() {


    }
    void DeleteAgent() {


    }




};

#endif // PROFILES_H



