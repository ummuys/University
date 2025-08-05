#include "Boyer_Moore.hpp"
#include <map>

map<char, int> table(string substr) {
	map<char, int> res;
	int end = substr.size() - 1;
	res[substr[end - 1]] = 1;
	int c = 2;
	for (int i = end - 2; i != end - 1; i--) {
		res[substr[i]] = !res[substr[i]] ? c : res[substr[i]];
		c++;
		if (i == 0)i = end + 1;
	}
	return res;
}

int bm_find(string str, string substr) {
	map<char, int> res = table(substr);
	int max_shift = substr.size();
	int j = substr.size() - 1;
	int i = j;
	while(i < str.size()) {
		int cp_i = i;
		while (substr[j] == str[cp_i] && j > 0) {
			j--; cp_i--;
		}
		if (!j)return i - max_shift + 1;
		j = max_shift - 1;
		i += !res[str[i]] ? max_shift : res[str[i]];
	}
	return -1;
}