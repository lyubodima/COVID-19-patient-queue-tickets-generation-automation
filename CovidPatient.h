/*
Final Project Milestone 4
Module: utils.cpp
Filename: CovidPatient.h
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
#ifndef SDDS_COVIDPATIENT_H_
#define SDDS_COVIDPATIENT_H_
#include <iostream>
#include "Patient.h"

namespace sdds {
    
    class CovidPatient : public Patient {

    public:


        CovidPatient(int ticketNumber = 0, bool fileIO = false);

        char type()const;


        std::istream& read(std::istream& istr) override;

        std::ostream& write(std::ostream& ostr)const override;

        std::istream& csvRead(std::istream& istr) override;

        

    };

}
#endif // !SDDS_COVIDPATIENT_H_



