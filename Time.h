/*
Final Project Milestone 1
Module: Time.h
Filename: Time
Version 0.1
Author	Dmitri Lyubomudrov
Revision History
-----------------------------------------------------------
Date       19
2020/3/16  Preliminary release
2020/3/18  Debugged DMA
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------
*/
#ifndef SDDS_TIMER_H
#define SDDS_TIMER_H

#include <iostream>
#include "IOAble.h"

namespace sdds {

   class Time : public IOAble {

       unsigned int m_minutes;

   public:

      Time& setToNow();

      Time(unsigned int minutes = 0);


      virtual std::ostream& csvWrite(std::ostream& ostr) const override;
      virtual std::istream& csvRead(std::istream& istr) override;
      virtual std::ostream& write(std::ostream& ostr) const override;
      virtual std::istream& read(std::istream& istr) override;

      Time& operator-=(const Time& D);
      Time operator-(const Time& D)const;
      Time& operator+=(const Time& D);
      Time operator+(const Time& D)const;

      Time& operator=(unsigned int val);
      Time& operator *= (unsigned int val);
      Time& operator /= (unsigned int val);
      Time operator *(unsigned int val)const;
      Time operator /(unsigned int val)const;

      operator unsigned int()const;

      operator int()const;

   };

}

#endif // !SDDS_TIME_H

