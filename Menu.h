/*
Final Project Milestone 2
Module: Menu.h
Filename: Menu
Version 0.1
Author	Dmitri Lyubomudrov
Revision History
-----------------------------------------------------------
Date       March 23
2020/3/16  Preliminary release
2020/3/18  Debugged DMA
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------
*/
#ifndef SDDS_MENU_H
#define SDDS_MENU_H

namespace sdds {

	class Menu	{

		char* m_text;
		int m_noOfSel;

	public:

		void display() const;

		Menu(const char* MenuContent, int NoOfSelections);
		Menu(const Menu& source);
		virtual ~Menu();

		Menu& operator=(const Menu& source) = delete; 

		int& operator>>(int& Selection);
	};
}

#endif // !SDDS_MENU_H