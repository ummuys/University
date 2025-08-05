#include "../hpp_files/main.hpp"

//==================//
// LIST OF SORT:
//  selection_sort
//  bubble_sort
//  insertion_sort
//  quick_sort
//  merge_sort
//  heap_sort
//==================//

// BASIC ADRESS OF FILES TO TEST --> txt_files/...
// FILE TO TEST --> txt_files/random_nums.txt

const size_t MAX_LEN_ADRESS = 256;

int main() {
    cout << "\x1B[2J\x1B[H";
    cout << "===========FILE PREPARATION STAGE===========" << endl;

    bool is_empty = false;
    bool is_create = false;
    char* adress = new char[MAX_LEN_ADRESS];

    cout << "Write a file adress to sort: ";
    cin >> adress;

    // Testing file
    fstream file(adress);
    if (file) is_create = true;
    if (is_create && file.get() == EOF) is_empty = true;
    file.close();

    if (is_create) {
        // If file is empty
        switch (choose_message()) {
            case 1: {
                work_with_non_string(adress, is_empty);
                break;
            }
            case 2: {
                work_with_string(adress, is_empty);
                break;
            }
        }

    } else {
        cout << "ERROR 404: FILE DOESN'T EXIST!:(" << endl;
    }
    delete[] adress;
    return 0;
}