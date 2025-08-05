#include "Link.h"

void fill_info(Link* tmp) {

	printf("\nИмя: ");
	scanf_s("%s", tmp->f_name, 20);

	printf("Фамилия: ");
	scanf_s("%s", tmp->s_name, 20);

	printf("Дата рождения: ");
	scanf_s("%s", tmp->data, 20);

	printf("Средняя оценка: ");
	scanf_s("%lf", &tmp->grade);

	printf("\n");
}

void push(Link** students) {
	Link* tmp = (Link*)malloc(sizeof(Link));
	fill_info(tmp);
	(*students)->next = tmp;
	(*students)->next->back = (*students);
	(*students) = tmp;
}

void pop(Link** students) {
	Link* del = (*students);
	(*students) = (*students)->back;
	free(del);
}
