import threading
import time

class Graph:
    # Initialize the class
    def __init__(self, graph_dict=None, directed=True):
        self.graph_dict = graph_dict or {}
        self.directed = directed
        if not directed:
            self.make_undirected()
    # Create an undirected graph by adding symmetric edges
    def make_undirected(self):
        for a in list(self.graph_dict.keys()):
            for (b, dist) in self.graph_dict[a].items():
                self.graph_dict.setdefault(b, {})[a] = dist
    # Add a link from A and B of given distance, and also add the inverse link if the graph is undirected
    def connect(self, A, B, distance=1):
        self.graph_dict.setdefault(A, {})[B] = distance
        if not self.directed:
            self.graph_dict.setdefault(B, {})[A] = distance
    # Get neighbors or a neighbor
    def get(self, a, b=None):
        links = self.graph_dict.setdefault(a, {})
        if b is None:
            return links
        else:
            return links.get(b)
    # Return a list of nodes in the graph
    def nodes(self):
        s1 = set([k for k in self.graph_dict.keys()])
        s2 = set([k2 for v in self.graph_dict.values() for k2, v2 in v.items()])
        nodes = s1.union(s2)
        return list(nodes)
# This class represent a node
class Node:
    # Initialize the class
    def __init__(self, coordinates: tuple, parent:tuple):
        self.coordinates = coordinates
        self.parent = parent
        self.g = 0 # Distance to start node
        self.h = 0 # Distance to goal node
        self.f = 0 # Total cost
    # Compare nodes
    def __eq__(self, other):
        return self.coordinates == other.coordinates
    # Sort nodes
    def __lt__(self, other):
         return self.f < other.f
    # Print node
    def __repr__(self):
        return ('({0},{1})'.format(self.coordinates, self.f))

scale = 1

def build_graph(start_x, start_y, end_x, end_y,graph):
    if start_y + scale <= end_y:
        up(start_x,start_y,end_x,end_y,graph)
    if (start_x + scale <= end_x) and (start_y + scale <= end_y):
        up_diag(start_x,start_y,end_x,end_y,graph)
    if start_x + scale <= end_x:
        right(start_x,start_y,end_x,end_y,graph)
    if (start_x + scale <= end_x) and (start_y - scale >= end_y):
        down_diag(start_x,start_y,end_x,end_y,graph)

def up(x,y,end_x,end_y,graph):
    parent = (x,y)
    print(parent)
    neighbor = (x,y+scale)
    if neighbor in graph.nodes():
        graph.connect(parent,neighbor)
        print("up")
        return
    graph.connect(parent,neighbor)
    build_graph(x,y+scale,end_x,end_y,graph)

def up_diag(x,y,end_x,end_y,graph):
    parent = (x,y)
    print(parent)
    neighbor = (x+scale,y+scale)
    if neighbor in graph.nodes():
        graph.connect(parent,neighbor,1.4)
        print("up diag")
        return
    graph.connect(parent,neighbor,1.4)
    build_graph(x+scale,y+scale,end_x,end_y,graph)

def right(x,y,end_x,end_y,graph):
    parent = (x,y)
    print(parent)
    neighbor = (x+scale,y)
    if neighbor in graph.nodes():
        graph.connect(parent,neighbor)
        print("right")
        return
    graph.connect(parent,neighbor)
    build_graph(x+scale,y,end_x,end_y,graph)

def down_diag(x,y,end_x,end_y,graph):
    parent = (x,y)
    print(parent)
    neighbor = (x+scale,y-scale)
    if neighbor in graph.nodes():
        graph.connect(parent,neighbor,1.4)
        print("down diag")
        return
    graph.connect(parent,neighbor,1.4)
    build_graph(x+scale,y-scale,end_x,end_y,graph)

start_time = time.time()
graph = Graph()

build_graph(0,0,2,2,graph)

graph.make_undirected()
print(graph.nodes())
print(graph.graph_dict)

print("--- %s seconds ---" % (time.time() - start_time))