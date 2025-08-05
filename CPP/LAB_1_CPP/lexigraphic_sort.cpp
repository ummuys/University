#include "../hpp_files/lexigraphic_sort.hpp"

#include "../hpp_files/my_string.hpp"

int count_cost_of_word(char* word) {
    int cost = 0;
    for (int i = 0; word[i]; i++) {
        cost += word[i];
    }
    return cost;
}

void lexigrapgic_sort(char** arr, int len) {
    word* words = new word[len];
    for (int i = 0; i < len; i++) {
        strcpy(arr[i], words[i].str);
        words[i].cost = count_cost_of_word(arr[i]);
    }

    quick_sort_lexi(words, 0, len - 1);

    for (int i = 0; i < len; i++) {
        strcpy(words[i].str, arr[i]);
    }

    for (int i = 0; i < len; i++) {
        delete[] words[i].str;
    }
    delete[] words;
}

void quick_sort_lexi(word* arr, int start, int end) {
    if (start > end) {
        return;
    }
    int mid = arr[(start + end) / 2].cost;
    int i = start;
    int j = end;
    while (i <= j) {
        while (arr[i].cost < mid) i++;
        while (arr[j].cost > mid) j--;
        if (i <= j) {
            my_swap_lexi(&arr[i], &arr[j]);
            i++;
            j--;
        }
    }
    quick_sort_lexi(arr, start, j);
    quick_sort_lexi(arr, i, end);
}

void my_swap_lexi(word* obj1, word* obj2) {
    word tmp = *obj1;
    *obj1 = *obj2;
    *obj2 = tmp;
}