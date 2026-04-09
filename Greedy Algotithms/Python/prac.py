import networkx as nx
import matplotlib.pyplot as plt

G = nx.Graph()

edges = [
    (5,4,9),
    (1,5,4),
    (1,2,2),
    (2,6,7),
    (6,3,8),
    (3,4,5),
    (1,4,1),
    (2,4,3),
    (2,3,3)
]

for u,v,w in edges:
    G.add_edge(u,v,weight=w)

pos = nx.spring_layout(G)
nx.draw(G,pos,with_labels=True)
nx.draw_networkx_edge_labels(G,pos,
    edge_labels=nx.get_edge_attributes(G,'weight'))

plt.show()