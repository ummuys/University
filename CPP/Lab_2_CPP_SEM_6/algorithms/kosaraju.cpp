#include "kosaraju.hpp"
#include <algorithm> 

void reverse_graph(vvi& graph){
    vvi marked(graph.size(), std::vector<int>(graph[0].size()));
    for(int i = 0; i < graph.size(); i++){
        for(int j = 0; j < graph[i].size(); j++){
            if (graph[i][j] && !marked[i][j] && !marked[j][i]){
                marked[i][j] = 1;
                marked[j][i] = 1;
                int tmp = graph[i][j];
                graph[i][j] = graph[j][i];
                graph[j][i] = tmp;
            }
        }
    }
}

void ssc_DFS(std::vector<std::vector<int>> graph, vvi& ssc, std::vector<bool>& visited,
	const size_t edges, const size_t n_edge){
	std::stack<int> s;
	s.push(n_edge);
	visited[n_edge] = true;
    std::vector<int> part_of_ssc;
	while (!s.empty()) {
		size_t curr_edge = s.top();
		s.pop();
		//----------------------------------------------------//
		size_t mem_size_s = s.size();
		for (int i = int(edges - 1); i >= 0; i--) {
			if (curr_edge == i)continue;
			if (!visited[i] && graph[curr_edge][i]) {
				visited[i] = true;
				s.push(i);
			}
		}

		part_of_ssc.push_back(curr_edge);
		//----------------------------------------------------//
	}
    ssc.push_back(part_of_ssc);
}


vvi get_ssc(vvi graph){
    std::vector<int> tags = DFS(graph).second;
    size_t edges = graph.size();
	std::vector<bool> visited(edges);
    vvi ssc;
    reverse_graph(graph);
    for(int i = 0; i < tags.size(); i++){
        auto max_it = std::max_element(tags.begin(), tags.end());
        int max_index = std::distance(tags.begin(), max_it);
        if(!visited[max_index]){
            ssc_DFS(graph, ssc, visited, edges, max_index);
        }
        *max_it = -1;
    }

    return ssc;
}