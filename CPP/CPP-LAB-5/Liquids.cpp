#include "Liquids.h"


string CLiquid::get_name() {
	return m_name;
}

double CLiquid::get_densite() {
	return m_density;
}

double CAlcohol::get_strenght() {
	return m_strenght;
}

unsigned int CPetrol::get_oct_num() {
	return m_oct_num;
}

//------- CAlcohol -------//


void CAlcohol::set_info() {

	cout << "\n//------- �������� -------//\n" << endl;

	cout << "��������: ";
	string curr_name;
	cin >> curr_name;
	m_name = curr_name;
	cout << endl;

	cout << "���������: ";
	int curr_dens;
	cin >> curr_dens;
	m_density = curr_dens;
	cout << endl;

	cout << "������� ���-�� ������: ";
	unsigned int curr_strenght;
	cin >> curr_strenght;
	m_strenght = curr_strenght;
	cout << endl;

	cout << "\n//------- �������� -------//\n" << endl;
}

//------- CAlcohol -------//




//------- CPetrol -------//

void CPetrol::set_info() {

	cout << "\n//------- ������ -------//\n" << endl;

	cout << "��������: ";
	string curr_name;
	cin >> curr_name;
	m_name = curr_name;
	cout << endl;

	cout << "���������: ";
	int curr_dens;
	cin >> curr_dens;
	m_density = curr_dens;
	cout << endl;

	cout << "���-�� ���������� �����: ";
	int curr_oct_num;
	cin >> curr_oct_num;
	m_oct_num = curr_oct_num;
	cout << endl;

	cout << "\n//------- ������ -------//\n" << endl;


}


//------- CPetrol -------//



//------- CMenu -------//

void CMenu::set_info(CLiquid* liquid) {
	liquid->set_info();
}

//------- CMenu -------//