#include "../hpp_files/work_with_files.hpp"
const size_t MAX_LEN_STR = 256;
void convert_char_to_int(char* adress, long long** nums, int* len) {
    fstream file_in(adress);
    bool first_digit_zero = false;
    bool new_num = true;
    bool incorrect_num = false;
    bool is_negative = false;
    bool is_digit = false;

    int i = 0;
    if (!(*len)) {
        *len = 10;
    }

    *nums = new long long[*len];
    char tmp = file_in.get();
    if (tmp >= '0' && tmp <= '9') is_digit = true;
    long long num_tmp;

    while (tmp != EOF) {
        if (tmp == '-' && !is_negative && !is_digit) {
            is_negative = true;
        } else if (!is_digit && new_num) {
            incorrect_num = true;
        }

        if (tmp >= '0' && tmp <= '9') {
            if (tmp == '0' && new_num && !first_digit_zero) {
                num_tmp = 0;
                first_digit_zero = true;
                new_num = false;
            }

            else if (!new_num && first_digit_zero) {
                incorrect_num = true;
            }

            else if (new_num && tmp != '0' && !incorrect_num) {
                if (is_negative)
                    num_tmp = (tmp - '0') * -1;
                else
                    num_tmp = (tmp - '0');
                new_num = false;
            }

            else if (!incorrect_num && !new_num) {
                num_tmp *= 10;
                if (num_tmp < 0)
                    num_tmp -= (tmp - '0');
                else
                    num_tmp += (tmp - '0');
            }

        } else {
            if (!new_num && !incorrect_num) {
                (*nums)[i] = num_tmp;
                i++;
                first_digit_zero = false;
                new_num = true;
                incorrect_num = false;
                is_negative = false;
            } else if (incorrect_num && !is_digit) {
                first_digit_zero = false;
                new_num = true;
                incorrect_num = false;
                is_negative = false;
            }
        }
        tmp = file_in.get();
        if (tmp >= '0' && tmp <= '9')
            is_digit = true;
        else
            is_digit = false;

        if (i + 1 >= *len) {
            *len += 10;
            long long* tmp = (long long*)realloc(*nums, sizeof(long long) * (*len));
            *nums = tmp;
        }
    }

    if (!new_num && !incorrect_num) {
        (*nums)[i] = num_tmp;
        i++;
    }
    *len = i;
    file_in.close();
}

void fill_file(char* adress, int len) {
    fstream file(adress);
    srand(time(0));
    for (int i = 0; i < len; i++) {
        if (i + 1 != len) {
            file << 1 + rand() % 1000000 << " ";
        } else {
            file << 1 + rand() % 1000000 << "\0";
        }
    }
    file.close();
}

int count_space(char* adress) {
    int n = 1;
    fstream file_in(adress);
    char tmp_space = file_in.get();
    while (tmp_space != EOF) {
        if (tmp_space == ' ' || tmp_space == '\n') n++;
        tmp_space = file_in.get();
    }
    if (n) n += 1;
    file_in.close();
    return n;
}

//
// txt_files/random_nums.txt

void work_with_string_and_file(char* adress, char*** words, int* len) {
    int i = 0;
    int symb_i = 0;
    if (!(*len)) {
        *len = count_space(adress);
    }
    fstream file_in(adress);
    *words = new char*[*len];
    for (int i = 0; i < *len; i++) {
        (*words)[i] = new char[MAX_LEN_STR];
    }
    char tmp = file_in.get();
    while (tmp != EOF) {
        if (tmp == ' ' || tmp == '\n') {
            (*words)[i][symb_i] = '\0';
            i++;
            symb_i = 0;
        } else {
            (*words)[i][symb_i] = tmp;
            symb_i++;
        }
        tmp = file_in.get();
    }

    cout << endl;
    file_in.close();
}