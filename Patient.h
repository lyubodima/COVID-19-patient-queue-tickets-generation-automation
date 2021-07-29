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
#ifndef SDDS_PATIENT_H
#define SDDS_PATIENT_H
#define _CRT_SECURE_NO_WARNINGS
#include "Ticket.h"
#include "IOAble.h"

namespace sdds{

	class Patient : public IOAble{

		char* m_name = nullptr;
		int m_OHIP = 0;
		Ticket m_ticket;
		bool m_fileIO;

	public:

		Patient( int ticketNumber = 0, const bool fileIO = false);
		Patient(const Patient&) = delete;
		~Patient();

		void setArrivalTime();

		bool fileIO() const;
		void fileIO(const bool fileIO);
		

		virtual char type() const = 0;

		int number() const;

		Patient& operator=(const Patient&) = delete;
		bool operator==(const char type) const;
		bool operator==(const Patient& obj) const;
		operator Time() const;



		std::ostream& csvWrite(std::ostream& ostr) const override;
		std::istream& csvRead(std::istream& istr)	override;
		std::ostream& write(std::ostream& ostr) const	override;
		std::istream& read(std::istream& istr) override;

	};
}

#endif // !SDDS_PATIENT_H