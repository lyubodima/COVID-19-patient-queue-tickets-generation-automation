/*
Final Project Milestone 2
Module: IOAble.h
Filename: IOAble
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
#ifndef SDDS_IOABLE_H
#define SDDS_IOABLE_H
#include <iostream>

namespace sdds {

	class IOAble{

	public:

		virtual ~IOAble();
		virtual std::ostream& csvWrite(std::ostream& ostr) const = 0;
		virtual std::istream& csvRead(std::istream& istr) = 0;
		virtual std::ostream& write(std::ostream& ostr) const = 0;
		virtual std::istream& read(std::istream& istr) = 0;
	};

	std::ostream& operator<<(std::ostream& ostr, const IOAble&);
	std::istream& operator>>(std::istream& istr, IOAble&);
}

#endif// !SDDS_IOABLE_H
