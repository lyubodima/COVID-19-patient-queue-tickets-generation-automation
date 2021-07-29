/*
Final Project Milestone 5
Module: PreTriage.cpp
Filename: PreTriage
Version 3
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
#define _CRT_SECURE_NO_WARNINGS
#include "PreTriage.h"
using namespace std;
namespace sdds {

	PreTriage::PreTriage(char const* dataFilename) : m_averCovidWait(15), m_averTriageWait(5),
		m_appMenu("General Hospital Pre-Triage Application\n1- Register\n2- Admit", 2),
		m_pMenu("Select Type of Admittance:\n1- Covid Test\n2- Triage", 2) {

		m_dataFilename = new char[strLen(dataFilename) + 1];
		strCpy(m_dataFilename, dataFilename);

		if (dataFilename != nullptr) {
			delete[] m_dataFilename;
			m_dataFilename = new char[strLen(dataFilename) + 1];
			strCpy(m_dataFilename, dataFilename);
		}

		load();
	}

	PreTriage::~PreTriage() {
		ofstream fout(m_dataFilename);
		if (fout.is_open()) {

			fout <<(Time)m_averCovidWait << ","
				<< (Time)m_averTriageWait << endl;

			cout << "Saving Average Wait Times," << endl
				<< "   COVID Test: " << (Time)m_averCovidWait << endl
				<< "   Triage: " << (Time)m_averTriageWait << endl;

			if (m_lineupSize > 0) {
				cout << "Saving m_lineup..." << endl;
				for (int i = 0; i < m_lineupSize; ++i) {
					m_lineup[i]->csvWrite(fout);
					fout << endl;

					cout << i + 1 << "- ";
					m_lineup[i]->csvWrite(cout);
					cout << endl;

					delete m_lineup[i];
				}
			}
			fout.close();
		}
		delete[] m_dataFilename;
		cout << "done!" << endl;;
	}

	void sdds::PreTriage::run(void) {
		m_appMenu.display(); int selection; cin >> selection;

		switch (selection) {
		case 0: break; 
		case 1: reg(); break;
		case 2: admit(); break;
		}
	}

	void  PreTriage::load() {

		cout << "Loading data..." << endl;

		ifstream in(m_dataFilename);

		if (in) { in >> m_averCovidWait; in.ignore(); in >> m_averTriageWait; in.ignore();

			Patient* ptr = nullptr;
			char type;

			for (int i = 0; i < maxNoOfPatients && in; ++i) {
				in >> type;	in.ignore();

				if (type == 'C') { ptr = new CovidPatient; }
				else if (type == 'T') { ptr = new TriagePatient; }


				if (ptr != nullptr && in) {
					ptr->fileIO(true);
					ptr->csvRead(in);
					ptr->fileIO(false);
					m_lineup[i] = ptr;
					++m_lineupSize;//m_lineupSize++;
				}
			}
			if (!in.eof()) {
				cout << "Warning: number of records exceeded " << maxNoOfPatients << endl;
			}

			if (ptr == nullptr) {//m_lineupSize == 0
				cout << "No data or bad data file!";
				m_averCovidWait = 15;
				m_averTriageWait = 5;
			}
			else {
				cout << m_lineupSize << " Records imported...";
			}

			cout << endl << endl;
			in.close();
		}
	}

	void sdds::PreTriage::reg() {
		
		if (m_lineupSize == maxNoOfPatients) { cout << "Line up full!" << endl; run(); }

		else {
			int selection;
			m_pMenu >> selection;

			if (selection == 1) { m_lineup[m_lineupSize] = new CovidPatient; }
			else if (selection == 2) { m_lineup[m_lineupSize] = new TriagePatient; }
			else if (selection == 0) { exit(0); }

			m_lineup[m_lineupSize]->setArrivalTime();
			cout << "Please enter patient information: " << endl;
			m_lineup[m_lineupSize]->fileIO(false);			
			cin >> *m_lineup[m_lineupSize];	

			cout << endl << "******************************************" << endl;
			cout << *m_lineup[m_lineupSize] << endl << "Estimated Wait Time: " << getWaitTime(*m_lineup[m_lineupSize]) << endl;
			cout << "******************************************" << endl << endl;

			++m_lineupSize; //m_lineupSize++;
			run(); 
		}
	}

	const Time sdds::PreTriage::getWaitTime(const Patient& p) const {

		int count = 0;

		for (int i = 0; i < m_lineupSize ; ++i) { 

			if (m_lineup[i] != nullptr && m_lineup[i]->type() == p.type()) {
				++count;
			}
		}
		if (p.type() == 'C') { return  count * (int)m_averCovidWait; } 
		else if (p.type() == 'T') { return count * (int)m_averTriageWait; }
		else { return -1; }
	}

	void sdds::PreTriage::admit() {

		m_pMenu.display();
		int selection; cin >> selection;

		char type;// = ' ';
		//int index = -1;

		if (selection == 1) { type = 'C'; }
		else if (selection == 2) { type = 'T'; }
		else if (selection == 0) { exit(0); }

		int index = indexOfFirstInLine(type);
		if (index == -1) { exit(0); }

		cout << endl << "******************************************" << endl;
		
		m_lineup[index]->fileIO(false);
		cout << "Calling for " << *m_lineup[index];
		cout << endl << "******************************************" << endl << endl;

		setAverageWaitTime(*m_lineup[index]);
		removePatientFromLineup(index);
		run();
	}

	void PreTriage::setAverageWaitTime(const Patient& p) {
		if (p.type() == 'C') { 
			m_averCovidWait = ((getTime() - (unsigned int)(Time)p) + (unsigned int)(Time)m_averCovidWait * (p.number() - 1)) / (p.number());
		}
		else if(p.type() == 'T') { 
			m_averTriageWait = ((getTime() - (unsigned int)(Time)p) + (unsigned int)(Time)m_averTriageWait * (p.number() - 1)) / (p.number());
		}
	}

	int sdds::PreTriage::indexOfFirstInLine(char type) const {
		for (int i = 0; i < m_lineupSize; ++i) {
			if (m_lineup[i]->type() == type) {	return i;break;	}
		}
		return -1;
	}

	void sdds::PreTriage::removePatientFromLineup(int index) {
		removeDynamicElement<Patient>(m_lineup, index, m_lineupSize);
	}

}