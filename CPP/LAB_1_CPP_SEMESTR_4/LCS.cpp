#include "LCS.hpp"
#include <algorithm>

int LCS(string word1, string word2) {
	int len_word1 = word1.size();
	int len_word2 = word2.size();
	int** LCS_table = new int* [len_word1];
	for (int i = 0; i < len_word1; i++) {
		LCS_table[i] = new int[len_word2];
	}
	for (int dig_w1 = 0; dig_w1 < len_word1; dig_w1++) {
		for (int dig_w2 = 0; dig_w2 < len_word2; dig_w2++) {
			if (dig_w1 > 0) {
				if (word1[dig_w1] == word2[dig_w2]) {
					LCS_table[dig_w1][dig_w2] = LCS_table[dig_w1 - 1][dig_w2 - 1] + 1;
				}
				else {
					LCS_table[dig_w1][dig_w2] = LCS_table[dig_w1 - 1][dig_w2] > LCS_table[dig_w1][dig_w2 - 1] ?
						LCS_table[dig_w1 - 1][dig_w2] : LCS_table[dig_w1][dig_w2 - 1];
				}
			}
			else {
				if (word1[dig_w1] == word2[dig_w2]) {
					LCS_table[dig_w1][dig_w2] = 1;
				}
				else {
					LCS_table[dig_w1][dig_w2] = 0;
				}
			}
		}
	}
	int answer = LCS_table[len_word1 - 1][len_word2 - 1];
	for (int i = 0; i < len_word1; i++) {
		delete[] LCS_table[i];
	}
	delete[] LCS_table;
	return answer;
}

int LCS_extended(string word1, string word2, string word3) {
	int len_word1 = word1.size();
	int len_word2 = word2.size();
	int len_word3 = word3.size();
	int*** LCS_table = new int** [len_word1];
	for (int i = 0; i < len_word1; i++) {
		LCS_table[i] = new int*[len_word2];
		for (int j = 0; j < len_word2; j++) {
			LCS_table[i][j] = new int[len_word3];
		}
	}
	for (int dig_w1 = 0; dig_w1 < len_word1; dig_w1++) {
		for (int dig_w2 = 0; dig_w2 < len_word2; dig_w2++) {
			for (int dig_w3 = 0; dig_w3 < len_word3; dig_w3++) {
				if (dig_w1 > 0 && dig_w2 > 0) {
					if (LCS_compare(word1[dig_w1], word2[dig_w2], word3[dig_w3])) {
						LCS_table[dig_w1][dig_w2][dig_w3] = LCS_table[dig_w1 - 1][dig_w2 - 1][dig_w3 - 1] + 1;
					}
					else {
						LCS_table[dig_w1][dig_w2][dig_w3] = max(max(
							max(LCS_table[dig_w1 - 1][dig_w2][dig_w3],
								LCS_table[dig_w1][dig_w2 - 1][dig_w3]),
							LCS_table[dig_w1][dig_w2][dig_w3 - 1]),
							LCS_table[dig_w1 - 1][dig_w2 - 1][dig_w3 - 1]);
					}
				}
				else {
					if (LCS_compare(word1[dig_w1], word2[dig_w2], word3[dig_w3])){
						LCS_table[dig_w1][dig_w2][dig_w3] = 1;
					}
					else {
						LCS_table[dig_w1][dig_w2][dig_w3] = 0;
					}
				}
			}
		}
	}
	int answer = LCS_table[len_word1 - 1][len_word2 - 1][len_word3 - 1];
	for (int dig_w1 = 0; dig_w1 < len_word1; dig_w1++) {
		for (int dig_w2 = 0; dig_w2 < len_word2; dig_w2++) {
			delete[] LCS_table[dig_w1][dig_w2];
		}
		delete[] LCS_table[dig_w1];
	}
	delete[] LCS_table;

	return answer;
}

bool LCS_compare(char symb1, char symb2, char symb3) {
	return symb1 == symb2 && symb1 == symb3 && symb2 == symb3;
}