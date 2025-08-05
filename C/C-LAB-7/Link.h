#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

typedef struct Link Link;


struct Link {
	char f_name[20];
	char s_name[20];
	char data[20];
	double grade;
	Link* next;
	Link* back;
};

void fill_info(Link* tmp);

void push(Link** students);

void pop(Link** students);