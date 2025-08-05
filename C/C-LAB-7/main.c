#include "Link.h"
void show_all(Link* students, int c);

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int fl_cont = 1;
	int c_elems = 0;
	Link* students = (Link*)malloc(sizeof(Link));
	students->back = NULL;
	Link* rem_start = students;
	while (fl_cont) {
		printf("\nЧто нам нужно сделать?\n\n[1] Показать объекты листа\n[2] Добавить объект\n[3] Удалить последний объект\n[4] Очистить консоль\n[5] Выйти\n\n-> ");
		int answer;
		scanf_s("%d", &answer);
		switch (answer) {
		case 1: {
			show_all(rem_start, c_elems);
			break;
		}
		case 2: {
			push(&students);
			c_elems++;
			break;
		}
		
		case 3: {
			pop(&students);
			c_elems--;
			break;
		}
		
		case 4: {
			system("cls");
			break;
		}
		
		case 5: {
			fl_cont = 0;
			break;
		}

		}

	}

}





void show_all(Link* students, int c) {

	if (!c) {
		printf("\nВ списке никого нет . . .\n");
		return;
	}

	while (c) {
		printf("\nИмя -> %s\n", students->next->f_name);
		printf("Фамилия -> %s\n", students->next->s_name);
		printf("Дата рождения -> %s\n", students->next->data);
		printf("Средняя оценка -> %.3lf\n", students->next->grade);
		printf("\n");
		students = students->next;
		c--;
	}
}