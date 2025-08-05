CPP_GRAPH_PATH=graph_cpp/*.cpp
CPP_EXEC_NAME_GRAPH=graph_cpp/graph_cpp
PY_GRAPH_PATH="graph_py/graph.py"
CPP_FIND_DFS_N_BFS_PATH= algorithms/*.cpp
CPP_EXEC_NAME_FIND=graph_cpp/find_cpp
TXT_OUT_SSC="graph_py/ssc.txt"



TXT_GRAPH_PATH="graph_cpp/graph.txt"
TXT_MOD_PATH="graph_cpp/mode.txt"

lab2:clear graph find

graph:
	@g++ $(CPP_GRAPH_PATH) -o $(CPP_EXEC_NAME_GRAPH)
	@./$(CPP_EXEC_NAME_GRAPH) $(TXT_GRAPH_PATH) $(TXT_MOD_PATH)
	@rm $(CPP_EXEC_NAME_GRAPH)

find:
	@./do.sh

clear:
	@rm -rf $(TXT_GRAPH_PATH)
	@rm -rf $(TXT_MOD_PATH)
	@rm -rf $(TXT_OUT_SSC)
	@rm -rf $(CPP_EXEC_NAME_GRAPH)
	@rm -rf $(CPP_EXEC_NAME_FIND)
