/*
Final Project Milestone 4
Module: TriagePatient.h
Filename: TriagePatient
Version 0.2
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
#ifndef SDDS_TRIAGEPATIENT_H
#define SDDS_TRIAGEPATIENT_H

#include <iostream>
#include "Patient.h"

namespace sdds {

    class TriagePatient : public Patient {

        char* s = nullptr;

    public:


        TriagePatient(int ticketNumber = 0, bool fileIO = false);

        char type()const;

        ~TriagePatient(); 

        std::istream& read(std::istream& istr) override;

        std::ostream& write(std::ostream& ostr)const override;

        std::istream& csvRead(std::istream& istr) override;

        std::ostream& csvWrite(std::ostream& ostr) const override;

    };
}
#endif // !SDDS_TRIAGEPATIENT_H


