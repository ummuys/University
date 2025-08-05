#pragma once
#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <map>


void edge_DFS(std::vector<std::vector<int>> graph, std::vector<int>& v, std::vector<bool>& visited,
	const size_t edges, const size_t n_edge, std::map<int,int>& ancestor, std::vector<int>& tags,
	std::vector<int>& anc_edges);
void increment_edges(std::map<int,int>& ancestor, std::vector<int>& tags, std::vector<int>& anc_edges);
std::pair<std::vector<int>, std::vector<int>> DFS(std::vector<std::vector<int>> graph);