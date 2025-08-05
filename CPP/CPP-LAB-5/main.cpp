#include "Liquids.h"
#include <iomanip>

int main() {

	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);

	CPetrol petrl;
	CAlcohol alchl;
	CMenu menu;
	bool flag = true;

	while (flag) {
		cout << endl;
		cout << setw(27) << "-----------------------" << setw(6) << endl;
		cout << setw(27) << "|��� ������� ������� ?|" << setw(6) << endl;
		cout << setw(27) << "-----------------------" << setw(6);

		cout << "\n\n[1] ���������� ������ ������� ������ ��������\n[2] ���������� ������ ������� ������ ������\n";
		cout << "[3] �������� ������ ������� ������ Alcohol\n[4] �������� ������ ������� ������ ������\n[5] �����" << endl << endl << ">>";

		int answer;
		cin >> answer;
		switch (answer) {
		case 1: {
			cout << "\n//------- �������� -------//\n" << endl;
			cout << "��������: " << alchl.get_name() << endl;
			cout << "���������: " << alchl.get_densite() << endl;
			cout << "������� ���-�� ������: " << alchl.get_strenght() << "%" << endl;
			cout << "\n//------- �������� -------//\n" << endl;
			break;
		}

		case 2: {
			cout << "\n//------- ������ -------//\n" << endl;
			cout << "��������: " << petrl.get_name() << endl;
			cout << "���������: " << petrl.get_densite() << endl;
			cout << "��������� �����: " << petrl.get_oct_num() << endl;
			cout << "\n//------- ������ -------//\n" << endl;
			break;
		}
		case 3: {
			menu.set_info(&alchl);
			break;
		}

		case 4: {
			menu.set_info(&petrl);
			break;
		}

		case 5: {
			flag = false;
			cout << setw(118) << "-----------------------------------------" << setw(80) << endl;
			cout << setw(118) << "|������ ��������: ������� ������ ���-315|" << setw(80) << endl;
			cout << setw(118) << "-----------------------------------------" << setw(80) << endl;
			break;
		}

		}
	}


}
