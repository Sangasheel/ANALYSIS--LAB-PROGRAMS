import networkx as nx
import matplotlib.pyplot as plt

G = nx.Graph()

edges = [
    (1,2,2),
    (3,5,3),
    (2,3,1),
   
]


for u,v,w in edges:
    G.add_edge(u,v,weight=w)

pos = nx.spring_layout(G)
nx.draw(G,pos,with_labels=True)
nx.draw_networkx_edge_labels(G,pos,
    edge_labels=nx.get_edge_attributes(G,'weight'))

plt.show()