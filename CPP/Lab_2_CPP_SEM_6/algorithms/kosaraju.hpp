#pragma once
#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <iomanip>
#include <fstream>
#include <cstdlib>
#include <string>
#include <sstream>
#include <limits>
#include "DFS.hpp"

typedef std::vector<std::vector<int>> vvi;
void reverse_matrix(vvi graph);
vvi get_ssc(vvi graph);