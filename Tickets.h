#ifndef TICKETS_H
#define TICKETS_H

#include <QMainWindow>


class Ticket {
   public:
   int Ticket_id;
   QString Category;
   QString Tags[5];
   char Impact, Priority;
   int Urgency;
   int Time_Stamp[3];
   QString Description;
   int Support_Level;

   void CreateTicket() {


   }
   void UpdateTicket() {



   }
   void CloseTicket() {



   }
   void Re_OpenTicket(){



   }




};







#endif // TICKETS_H
