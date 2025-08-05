#include "DFS.hpp"

void increment_edges(std::map<int,int>& ancestor, std::vector<int>& tags, std::vector<int>& anc_edges){
	for(int i = anc_edges.size()-1; i >= 0; i--){
		tags[ancestor[anc_edges[i]]] = tags[anc_edges[i]] + 1;
		anc_edges.pop_back();
	}
}

void edge_DFS(std::vector<std::vector<int>> graph, std::vector<int>& v, std::vector<bool>& visited,
	const size_t edges, const size_t n_edge, std::map<int,int>& ancestor, std::vector<int>& tags,
	std::vector<int>& anc_edges){
	std::stack<int> s;
	s.push(n_edge);
	visited[n_edge] = true;

	while (!s.empty()) {

		size_t curr_edge = s.top();
		s.pop();

		//----------------------------------------------------//
		if(!ancestor.size()){
			ancestor[0] = -1;
			tags[0] = 1;
		}
		else{
			tags[curr_edge] = tags[ancestor[curr_edge]] + 1;
			anc_edges.push_back(curr_edge);
			// std::cout << "--------------------------------\n";
			// for(int i = 0; i < anc_edges.size(); i++){
			// 	std::cout << anc_edges[i] << std::endl;
			// }
			// std::cout << "--------------------------------\n";
			
		}
		//----------------------------------------------------//


		//----------------------------------------------------//
		size_t mem_size_s = s.size();
		for (int i = int(edges - 1); i >= 0; i--) {
			if (curr_edge == i)continue;
			if (!visited[i] && graph[curr_edge][i]) {
				visited[i] = true;
				ancestor[i] = curr_edge;
				s.push(i);
			}
		}
		if(mem_size_s == s.size()){
			increment_edges(ancestor, tags, anc_edges);
		}

		v.push_back(curr_edge);
		//----------------------------------------------------//
	}
}

std::pair<std::vector<int>, std::vector<int>> DFS(std::vector<std::vector<int>> graph) {
	size_t edges = graph.size();
	std::vector<bool> visited(edges);
	std::vector<int> res_DFS;
	std::map<int,int> ancestor;
	std::vector<int> tags(edges);
	std::vector<int> anc_edges;
	for (size_t i = 0; i < edges && res_DFS.size() < edges; i++) {
		if (!visited[i])edge_DFS(graph, res_DFS, visited, edges, i, ancestor, tags, anc_edges);
	}

	// std::cout << std::endl; 
	// std::cout << "Ancestor" << std::endl; 
	// for(int i = 0; i < edges; i++){
	// 	std::cout << ancestor[i] << std::endl; 
	// }

	// std::cout << std::endl; 
	// std::cout << "Tags" << std::endl; 
	// for(int i = 0; i < edges; i++){
	// 	std::cout << tags[i] << std::endl; 
	// }
	// std::cout << std::endl;
	// std::cout << std::endl;
	// std::cout << std::endl;

	return std::pair(res_DFS, tags);
}
