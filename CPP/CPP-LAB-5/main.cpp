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
		cout << setw(27) << "|Что следует сделать ?|" << setw(6) << endl;
		cout << setw(27) << "-----------------------" << setw(6);

		cout << "\n\n[1] Посмотреть данные объекта класса Алкоголь\n[2] Посмотреть данные объекта класса Бензин\n";
		cout << "[3] Изменить данные объекта класса Alcohol\n[4] Изменить данные объекта класса Бензин\n[5] Выйти" << endl << endl << ">>";

		int answer;
		cin >> answer;
		switch (answer) {
		case 1: {
			cout << "\n//------- Алкоголь -------//\n" << endl;
			cout << "Название: " << alchl.get_name() << endl;
			cout << "Плотность: " << alchl.get_densite() << endl;
			cout << "Процент кол-во спирта: " << alchl.get_strenght() << "%" << endl;
			cout << "\n//------- Алкоголь -------//\n" << endl;
			break;
		}

		case 2: {
			cout << "\n//------- Бензин -------//\n" << endl;
			cout << "Название: " << petrl.get_name() << endl;
			cout << "Плотность: " << petrl.get_densite() << endl;
			cout << "Октановое число: " << petrl.get_oct_num() << endl;
			cout << "\n//------- Бензин -------//\n" << endl;
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
			cout << setw(118) << "|Работу выполнил: Евгений Егоров ИВБ-315|" << setw(80) << endl;
			cout << setw(118) << "-----------------------------------------" << setw(80) << endl;
			break;
		}

		}
	}


}
