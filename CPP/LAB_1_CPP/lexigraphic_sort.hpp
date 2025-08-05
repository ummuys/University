#pragma once
#include <iostream>
using namespace std;
const size_t MAX_LEN_STR = 256;

typedef struct word {
    char* str = new char[MAX_LEN_STR];
    int cost;
} word;

void my_swap_lexi(word* obj1, word* obj2);
int count_cost_of_word(char* word);
void lexigrapgic_sort(char** arr, int len);
void quick_sort_lexi(word* arr, int start, int end);