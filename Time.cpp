/*
Final Project Milestone 1
Module: Time.cpp
Filename: Time
Version 0.4
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
#include "Time.h"
#include "utils.h"
using namespace std;
namespace sdds {
    Time& Time::setToNow() { m_minutes = getTime(); return *this; }

    Time::Time(unsigned int min) : m_minutes{ min } {}

    std::istream& Time::read(std::istream& istr) {

        int hours = 0, minutes = 0;
        char separator = '\0';

        istr >> hours;
        istr >> separator;
        istr >> minutes;

        if (hours < 0 || separator != ':' || minutes < 0) { istr.setstate(ios::failbit);  }

        m_minutes = hours * 60 + minutes;
        return istr;
    }

    std::ostream& Time::write(std::ostream& ostr)const {
        unsigned int hours = m_minutes / 60;
        unsigned int minutes = m_minutes - hours * 60;
        ostr.fill('0');
        ostr.width(2);
        ostr << hours << ":";
        ostr.width(2);
        ostr << minutes;
        ostr.fill(' ');
        return ostr;
    }

    Time& Time::operator=(unsigned int val) { m_minutes = val; return *this; }
    Time& Time::operator *= (unsigned int val) { m_minutes *= val; return *this; }
    Time& Time::operator /= (unsigned int val) { m_minutes /= val; return *this; }
    Time Time::operator *(unsigned int val)const { return  m_minutes * val; }
    Time Time::operator /(unsigned int val)const { return m_minutes / val; }
    Time Time::operator+(const Time& Input)const { return m_minutes + Input.m_minutes; } 
    Time& Time::operator+=(const Time& Input) { *this = m_minutes + Input.m_minutes; return *this;  }
    Time Time::operator-(const Time& Input)const {    
        if (m_minutes - Input.m_minutes < 0) { return m_minutes + 1440; }
        return m_minutes - Input.m_minutes;
    }
    Time& Time::operator-=(const Time& Input) {
        if (this - Input.m_minutes < 0) { return *this += 1440; }
        return *this -= Input.m_minutes;
    }

    Time::operator unsigned int()const { return m_minutes; }
    Time::operator int()const { int output = m_minutes;  return output; }

    std::ostream& operator<<(std::ostream& ostr, const Time& O) { O.write(ostr); return ostr;  }
    
    std::istream& operator>>(std::istream& istr, Time& Object_for_Input) { Object_for_Input.read(istr); return istr;  }

    ostream& Time::csvWrite(ostream& ostr) const { return ostr;   }
    istream& Time::csvRead(istream& istr) { return istr; }
}