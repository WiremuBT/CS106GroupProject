#ifndef TICKETS_H
#define TICKETS_H

#include <QMainWindow>


class Ticket {
   public:
   int Ticket_id;
   QString fName, lName;
   QString Email;
   QString Phone;
   QString Category,response;
   QString Tags[4];
   QString Tags2;
   char Impact, Priority;
   QString Urgency;
   QString Time_Stamp;
   QString Agent_ResponseTag;
   QString Description;
   QString Response_Process;
   QString Support_Level;

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
