/*
Final Project Milestone 3
Module: Ticket
Filename: Ticket.h
Version 0.1
Author	Dmitri Lyubomudrov
Revision History
-----------------------------------------------------------
Date       29 March
2020/3/16  Preliminary release
2020/3/18  Debugged DMA
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------
*/
#ifndef SDDS_TICKET_H_
#define SDDS_TICKET_H_
#include "Time.h"
#include "IOAble.h"

namespace sdds {

   class Ticket:public IOAble{

       Time m_time;
       int m_number;

   public:

      Ticket(int number);
      operator Time()const;
      int number()const;
      void resetTime();

      std::ostream& csvWrite(std::ostream& ostr)const override;
      std::istream& csvRead(std::istream& istr) override;
      std::ostream& write(std::ostream& ostr )const override;
      std::istream& read(std::istream& istr) override;
   };
}
#endif // !SDDS_TICKET_H_
