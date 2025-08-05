#pragma once
#include <stdlib.h>

#include <fstream>
#include <iostream>
using namespace std;
void convert_char_to_int(char* adress, long long** nums, int* len);
void fill_file(char* adress, int len);
void work_with_string_and_file(char* adress, char*** nums, int* len);
int count_space(char* adress);

template <typename T>
void get_result(T* nums, int len) {
    fstream res("txt_files/result.txt", ios::out);
    for (int i = 0; i < len; i++) {
        if (i % 5 == 0 && i != 0) {
            res << nums[i] << "\n";
        } else if (i + 1 != len && i != 0) {
            res << nums[i] << " ";
        } else {
            res << nums[i] << "\0";
        }
    }
    res.close();
}
