#pragma once
#include <iostream>
#include <vector>
#include <queue>
#include <stack>

void edge_BFS(std::vector<std::vector<int>> graph, std::vector<int>& v, std::vector<bool>& visited,
	const size_t edges, int edge);

std::vector<int>BFS(std::vector<std::vector<int>> graph);
