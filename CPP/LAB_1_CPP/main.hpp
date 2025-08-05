#pragma once
#include <chrono>
#include <iostream>

#include "../hpp_files/lexigraphic_sort.hpp"
#include "../hpp_files/sort.hpp"
#include "../hpp_files/work_with_files.hpp"
using namespace std;

template <typename T, typename N>
void result_info(T* arr, int len, N clock) {
    cout << "===================RESULT===================" << endl;
    cout << "The time: " << clock.count() << "ms" << endl;
    cout << "===================RESULT===================" << endl;
}

template <typename T>
auto my_sort(void (*sort)(T*, int, int), T* arr, int len) {
    auto begin = chrono::steady_clock::now();
    sort(arr, 0, len);
    auto end = chrono::steady_clock::now();
    return chrono::duration_cast<chrono::milliseconds>(end - begin);
}

int choose_message() {
    int variant;
    cout << endl << "What a type of data do you want to sort?" << endl;
    cout << "1)Char/Int/Double/Float/.." << endl;
    cout << "2)String" << endl;
    cout << ">>";
    cin >> variant;
    return variant;
}

void work_with_non_string(char* adress, bool is_empty) {
    int len = 0;
    if (is_empty) {
        cout << "Write a count of random nums between 1 and 1.000.000: ";
        cin >> len;
        fill_file(adress, len);
    }
    cout << "===========FILE PREPARATION STAGE===========" << endl << endl;

    fstream file_in(adress);
    long long* arr;
    convert_char_to_int(adress, &arr, &len);
    file_in.close();
    auto time_waste = my_sort(insertion_sort, arr, len);
    result_info(arr, len, time_waste);
    get_result(arr, len);
    delete[] arr;
}

void work_with_string(char* adress, bool is_empty) {
    int len = 0;
    cout << "===========FILE PREPARATION STAGE===========" << endl << endl;
    char** arr;
    work_with_string_and_file(adress, &arr, &len);
    auto begin = chrono::steady_clock::now();
    lexigrapgic_sort(arr, len);
    auto end = chrono::steady_clock::now();
    auto res = chrono::duration_cast<chrono::milliseconds>(end - begin);
    result_info(arr, len, res);
    get_result(arr, len);
    for (int i = 0; i < len; i++) {
        delete[] arr[i];
    }
    delete[] arr;
}