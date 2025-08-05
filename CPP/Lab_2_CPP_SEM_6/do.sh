#!/bin/sh

PY_GRAPH_PATH="graph_py/graph.py"
PY_SSC_GRAPH_PATH="graph_py/ssc_graph.py"
CPP_FIND_DFS_N_BFS_PATH="algorithms/*.cpp"
CPP_EXEC_NAME_FIND="graph_cpp/find_cpp"

TXT_GRAPH_PATH="graph_cpp/graph.txt"
TXT_MOD_PATH="graph_cpp/mode.txt"
TXT_OUT_SSC="graph_py/ssc.txt"

# Graph view
# & <-- multithreading
python3 $PY_GRAPH_PATH $TXT_GRAPH_PATH $TXT_MOD_PATH&
g++ $CPP_FIND_DFS_N_BFS_PATH -o $CPP_EXEC_NAME_FIND
./$CPP_EXEC_NAME_FIND $TXT_GRAPH_PATH $TXT_MOD_PATH $TXT_OUT_SSC
if [ -e $TXT_OUT_SSC ]; then
    python3 $PY_SSC_GRAPH_PATH $TXT_GRAPH_PATH $TXT_OUT_SSC
fi
#vvv -- Command to wait a threads
wait

