#pragma once
#include <iostream>
#include <string>
#include <vector>
using namespace std;
long long u_hash(string str, int len_str);
long long re_hash(int back, int front, long long to_change, int dig);
vector<int> rb_find(string str, string substr);