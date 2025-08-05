#include "Rabin_Karp.hpp"
#include <cmath>

long long u_hash(string str, int len_str) {
	long long res = 0;
	for (int i = 0; i < len_str; i++) {
		res += str[i];
	}
	return res;
}

long long re_hash(int back, int front, long long to_change, int dig) {
	to_change -= back;
	to_change += front;
	return to_change;
}

vector<int> rb_find(string str, string substr) {
	vector<int> answer;
	int len_substr = substr.size();
	long long hash_str = u_hash(str, len_substr);
	long long hash_substr = u_hash(substr, len_substr);
	int c = 0;

	if (hash_str == hash_substr) {
		for (int i = 0; i < len_substr; i++) {
			if (str[i] == substr[i])c++;
			else break;
		}
		if (c == len_substr)answer.push_back(0);
	}

	for (int i = 1; i < str.size() - len_substr + 1; i++) {
		hash_str = re_hash(str[i - 1], str[i + len_substr - 1], hash_str, len_substr - 1);
		if (hash_str == hash_substr) {
			for (int j = 0, ij = i; j < len_substr; j++, ij++) {
				if (str[ij] == substr[j])c++;
				else break;
			}
			if (c == len_substr)answer.push_back(i);
			c = 0;
		}
	}

	return answer;

}