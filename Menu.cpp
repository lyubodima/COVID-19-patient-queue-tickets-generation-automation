/*
Final Project Milestone 2
Module: Menu.cpp
Filename: Menu
Version 0.2
Author	Dmitri Lyubomudrov
Revision History
-----------------------------------------------------------
Date       23 March
2020/3/16  Preliminary release
2020/3/18  Debugged DMA
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------
*/
#include "Menu.h"
#include "utils.h"
using namespace std;
namespace sdds {

	Menu::Menu(const char* MenuContent, int NoOfSelections) : m_text{ nullptr }, m_noOfSel{ NoOfSelections }{
		if (MenuContent != nullptr) {
			delete[] m_text;
			m_text = new char[strLen(MenuContent) + 1];
			strCpy(m_text, MenuContent);
		}
	}

	Menu::Menu(const Menu& source) : Menu(source.m_text, source.m_noOfSel)	{	}

	Menu::~Menu()	{
		delete[] m_text; 
		m_text = nullptr;
	}

	void Menu::display() const	{
		if (m_text != nullptr)		{
			cout << m_text << endl<< "0- Exit" << endl;
			cout << "> ";
		}
	}

	int& Menu::operator>>(int& Selection)	{
		//this->display();//
		display();
		Selection = getInt(0, this->m_noOfSel, nullptr, "Invalid option ", true);//"> "
		return Selection;
	}
}