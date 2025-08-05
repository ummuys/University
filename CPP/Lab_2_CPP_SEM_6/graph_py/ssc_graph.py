import os
import sys
import networkx as nx
import matplotlib.pyplot as plt
import random

def unique_colors(n):
    return ["#{:06x}".format(random.randint(0, 0xFFFFFF)) for _ in range(n)]

def get_info_from_txt(way1, way2):
    adg_matrix = []
    with open(way1, "r") as file1:
        for line in file1:
            adg_matrix.append(line.strip().split())
        
    ssc_matrix = []
    with open(way2, "r") as file2:
        for line in file2:
            ssc_matrix.append(line.strip().split())

    return adg_matrix, ssc_matrix

file_path_graph = os.path.join(sys.argv[1])
file_path_mode = os.path.join(sys.argv[2])
adj_matrix, ssc_matrix = get_info_from_txt(file_path_graph, file_path_mode)

G = nx.DiGraph()

for i in range(len(adj_matrix)):
    for j in range(len(adj_matrix[i])):
        if adj_matrix[i][j] == '1':
            G.add_edge(i, j)  

# Создаем словарь для соответствия вершины к номеру компоненты
node_to_component = {}
for component_idx, component in enumerate(ssc_matrix):
    for node in component:
        node_to_component[int(node)] = component_idx

# Генерируем уникальные цвета для каждого компонента
colors = unique_colors(len(ssc_matrix))

# Создаем список цветов для вершин
node_colors = []
for node in G.nodes():
    if node in node_to_component:
        node_colors.append(colors[node_to_component[node]])
    else:
        node_colors.append("#FFFFFF")  # Белый цвет для вершин без компоненты

# Визуализация
plt.figure(figsize=(10, 8))
pos = nx.spring_layout(G, seed=42)

# Рисуем граф
nx.draw_networkx_edges(G, pos, width=2, alpha=0.7, arrowsize=20)
nodes = nx.draw_networkx_nodes(
    G, pos,
    node_color=node_colors,
    node_size=800,
    edgecolors='black',
    linewidths=1.5
)
nx.draw_networkx_labels(G, pos, font_size=12, font_weight='bold')

# Добавляем легенду
legend_patches = [
    plt.Line2D([0], [0], 
               marker='o', 
               color='w', 
               label=f'Компонента {i}',
               markersize=10, 
               markerfacecolor=colors[i]) 
    for i in range(len(ssc_matrix))
]
plt.legend(handles=legend_patches, title="Компоненты сильной связности")

plt.title("Раскраска вершин по компонентам сильной связности", pad=20)
plt.axis('off')
plt.tight_layout()
plt.show()