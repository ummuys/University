#include "CQueue.h"

template<typename T>
void show_queue(CQueue<T> queue) {

	if (!queue.get_pos()) {
		cout << "Никого нет. . . " << endl;
	}

	else {
		cout << "Очередь: ";
		for (int i = 0; i < queue.get_len(); i++) {
			cout << *(queue.get_obj(i)) << " ";
		}

		cout << endl;
	}
}

int main() {
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);

	CQueue<string> queue(1);
	bool f_exit = false;

	while (!f_exit) {
		cout << endl;
		cout << setw(40) << "{Что сделует сделать?}" << setw(21) << endl << endl;
		cout << "[1] Показать очередь\n[2] Добавить объект в очередь\n[3] Удалить объект из очереди\n[4] Очистить консоль\n";
		cout << "[5] Выйти" << endl << endl << "--> ";

		int answer;
		cin >> answer;
		cout << endl;

		switch (answer) {
		case 1: {
			show_queue(queue);
			break;
		}
		case 2: {
			string a;
			cout << "Добавляем: ";
			cin >> a;
			queue.add_person(a);
			break;
		}
		case 3: {
			queue.next();
			break;
		}

		case 4: {
			system("cls");
			break;
		}

		case 5: {
			f_exit = true;
			cout << setw(120) << "---------------------------------------" << setw(82) << endl;
			cout << setw(120) << "Работу выполнил: Евгений Егоров ИВБ-315" << setw(82) << endl;
			cout << setw(120) << "---------------------------------------" << setw(82) << endl;
			break;
		}

		}
	}

 }