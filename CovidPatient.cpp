/*
Final Project Milestone 4
Module: CovidPatient.cpp
Filename: CovidPatient
Version 0.4
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
#include "CovidPatient.h"
namespace sdds {

   int nextCovidTicket = 1;


   CovidPatient::CovidPatient(int ticketNumber, bool fileIO) : Patient(nextCovidTicket, fileIO) {
       nextCovidTicket += 1;
   }


   char CovidPatient::type()const {
       return 'C';
   }

   std::istream& CovidPatient::read(std::istream& istr) {
       return fileIO() ? csvRead(istr).ignore(1000, '\n') : Patient::read(istr);
   }

   std::ostream& CovidPatient::write(std::ostream& ostr)const {

       if (fileIO()) {  csvWrite(ostr); }
       else { ostr << "COVID TEST" << std::endl; Patient::write(ostr);  };//
       return ostr;
   }

   std::istream& CovidPatient::csvRead(std::istream& istr) {
       if (fileIO()) { Patient::csvRead(istr); nextCovidTicket = number() + 1; }
       else { Patient::read(istr); }
       return istr;
   }

   
   
}