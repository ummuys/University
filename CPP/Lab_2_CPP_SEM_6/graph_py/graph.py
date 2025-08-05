import os
import sys
import networkx as nx
import matplotlib.pyplot as plt

with open(sys.argv[1]) as f:
    adj_matrix = [line.strip().split() for line in f]

with open(sys.argv[2]) as f:
    mode = f.read(1)

G = nx.DiGraph() if mode == '2' else nx.Graph()

for i in range(len(adj_matrix)):
    for j in range(len(adj_matrix[i])):
        if adj_matrix[i][j] == '1':
            G.add_edge(i, j)

plt.figure(figsize=(8, 6))
pos = nx.spring_layout(G)
nx.draw(G, pos, with_labels=True, node_color='lightblue', node_size=500, font_size=12, edge_color='gray')
plt.show()