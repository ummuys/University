#include "Knuth_Morris_Pratt.hpp"

void prefix_func(vector<int>& arr, string str) {
	int len_str = str.size();
	arr.push_back(0);
	for (int i = 1; i < str.size(); i++) {
		int c = arr[i - 1];
		while (c > 0 && str[i] != str[c]) {
			c = arr[c - 1];
		}
		if (str[i] == str[c])c++;
		arr.push_back(c);
	}
}

int kmp_find(string str, string substr) {
	vector<int> arr;
	prefix_func(arr, substr);
	int ans = -1;
	int c = 0;
	for (int i = 0; i < str.size(); i++) {
		while (c > 0 && substr[c] != str[i]) {
			c = arr[c - 1];
		}
		if (substr[c] == str[i]) {
			c = c + 1;
		}
		if (c == substr.size()) {
			ans = i - substr.size() + 1;
			break;
		}
	}
	return ans;
}




