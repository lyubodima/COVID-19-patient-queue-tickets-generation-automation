/*
Final Project Milestone 4
Module: TriagePatient.cpp
Filename: TriagePatient
Version 0.3
Author	Dmitri Lyubomudrov
Revision History
-----------------------------------------------------------
Date       8 April
2020/3/16  Preliminary release
2020/3/18  Debugged DMA
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------
*/
#include "TriagePatient.h"
#include "utils.h"
namespace sdds {

    int nextTriageTicket  = 1;

    TriagePatient::TriagePatient(int ticketNumber, bool fileIO) : Patient(nextTriageTicket, fileIO) {
        nextTriageTicket += 1;
    }

    char TriagePatient::type()const {
        return 'T';
    }
    TriagePatient::~TriagePatient()    {
        delete[] s;
    }
    std::ostream& TriagePatient::write(std::ostream& ostr)const {
        if (fileIO()) { csvWrite(ostr); }
        else {
            ostr << "TRIAGE" << std::endl; Patient::write(ostr) << std::endl;; ostr << "Symptoms: "; ostr << s;// << endl;
        };
        return ostr;
    }
    std::istream& TriagePatient::read(std::istream& istr) {
        if (fileIO()) { csvRead(istr); }
        else { Patient::read(istr);  delete[] s; s = getcstr("Symptoms: ", istr, '\n'); }
        return istr;
    }
    
    std::istream& TriagePatient::csvRead(std::istream& istr) {
        if (fileIO()) {
            Patient::csvRead(istr);
            istr.ignore();
            delete[] s;
            s = getcstr("", istr, '\n');
            nextTriageTicket = number() + 1;
        }
        else { read(istr); }
    
        return istr;
    }

    std::ostream& TriagePatient::csvWrite(std::ostream& ostr) const    {
        Patient::csvWrite(ostr); ostr << "," << s; //
        return ostr;
    }
    
}