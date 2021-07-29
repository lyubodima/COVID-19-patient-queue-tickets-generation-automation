/*
Final Project Milestone 2
Module: IOAble.cpp
Filename: IOAble
Version 0.3
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
#include "IOAble.h"
using namespace std;
namespace sdds {
	IOAble::~IOAble(){

	}

	ostream& operator<<(ostream& ostr, const IOAble& obj)	{
		obj.write(ostr);
		return ostr;
	}
	istream& operator>>(istream& istr, IOAble& obj)	{
		obj.read(istr);
		return istr;
	}
}

