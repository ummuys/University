#include "BFS.hpp"

void edge_BFS(std::vector<std::vector<int>> graph, std::vector<int>& v, std::vector<bool>& visited,
	const size_t edges, int edge) {
	std::queue<int> s;
	s.push(edge);
	visited[edge] = true;
	while (!s.empty()) {
		size_t curr_edge = s.front();
		s.pop();
		for (int i = 0; i < int(edges); i++) {
			if (curr_edge == i)continue;
			if (!visited[i] && graph[curr_edge][i]) {
				visited[i] = true;
				s.push(i);
			}
		}
		v.push_back(curr_edge);
	}
}


std::vector<int> BFS(std::vector<std::vector<int>> graph) {
	size_t edges = graph.size();
	std::vector<bool> visited(edges);
	std::vector<int> res_BFS;
	for(int i = 0; i < graph.size() && res_BFS.size() < edges; i++){
		if(!visited[i])edge_BFS(graph, res_BFS, visited, edges, i);
	}
	return res_BFS;
}
