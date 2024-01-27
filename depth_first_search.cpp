#include <iostream>
#include <list>
using namespace std;

class Graph {
    int numVertices;
    list<int> *adjLists;
    bool *visited;

public:
    Graph(int V);
    void addEdge(int src, int dest);
    void DFS(int vertex);
};

Graph::Graph(int vertices) {
    numVertices = vertices;
    adjLists = new list<int>[vertices];
    visited = new bool[vertices];

    for (int i = 0; i < vertices; i++)
        visited[i] = false;
}

void Graph::addEdge(int src, int dest) {
    adjLists[src].push_back(dest);
}

void Graph::DFS(int vertex) {
    visited[vertex] = true;
    cout << vertex << " ";

    list<int>::iterator i;
    for (i = adjLists[vertex].begin(); i != adjLists[vertex].end(); ++i) {
        if (!visited[*i]) {
            DFS(*i);
        }
    }
}

int main() {
    Graph g(5);

    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 3);
    g.addEdge(3, 1);

    cout << "DFS starting from vertex 2: ";
    g.DFS(2);

    return 0;
}

