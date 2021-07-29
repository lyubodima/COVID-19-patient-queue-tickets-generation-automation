/*
Final Project Milestone 3
Module: Patient.h
Filename: Menu
Version 3
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
#define _CRT_SECURE_NO_WARNINGS
#include "Patient.h"
#include "utils.h"

namespace sdds {
	Patient::Patient(int ticketNumber, bool const fileIO ): m_ticket(ticketNumber) {
		m_fileIO = fileIO;		
	}

	Patient::~Patient()	{		
		delete [] m_name;	
	}

	void Patient::setArrivalTime() {
		m_ticket.resetTime();
	}

	bool Patient::fileIO() const	{		
		return m_fileIO;
	}

	void Patient::fileIO(const bool fileIO)	{	
		m_fileIO = fileIO;	
	}

	int Patient::number() const	{	
		return m_ticket.number();
	}

	bool Patient::operator==(const Patient& obj) const {
		return (*this == obj.type());
	}
	bool Patient::operator==(const char type) const { 
		if (this->type() == type) { 
			return true; 
		}	
		return false; 
	}

	Patient::operator Time() const { 
		return (Time)m_ticket; 
	}

	std::istream& Patient::read(std::istream& istr) {
		delete[] m_name;
		m_name = getcstr("Name: ", istr, '\n');
		m_OHIP = getInt(100000000, 999999999, "OHIP: ", "Invalid OHIP Number, ", true);//OHIP_
		return istr;
	}

	std::istream& Patient::csvRead(std::istream& istr) {
		if (istr.good() && !istr.eof()) {
			delete[] m_name;
			m_name = getcstr("", istr, ',');
			istr >> m_OHIP;
			istr.ignore();
			if (istr.good() && !istr.eof()) { m_ticket.csvRead(istr); }
		}
		return istr;
	}

	std::ostream& Patient::write(std::ostream& ostr) const	{
		m_ticket.write(ostr);
		ostr << std::endl;
		if (strLen(m_name) > 25)		{
			char temp[26];
			strnCpy(temp, m_name, 25);
			ostr << temp;
		}
		else {	ostr << m_name;	}
		ostr << ", OHIP: " << m_OHIP;
		return ostr;
	}

	std::ostream& Patient::csvWrite(std::ostream& ostr) const {
		ostr <<type() << ","<<	m_name << "," << m_OHIP << ",";
		m_ticket.csvWrite(ostr);
		return ostr;
	}

}
