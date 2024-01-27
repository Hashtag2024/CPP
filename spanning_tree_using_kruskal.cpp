#include <iostream>
#include <algorithm>

using namespace std;

class Edge {
public:
    int src, dest, weight;
};

class Graph {
public:
    int V, E;
    Edge* edge;

    Graph(int V, int E) {
        this->V = V;
        this->E = E;
        edge = new Edge[E];
    }
};

class Subset {
public:
    int parent, rank;
};

int find(Subset subsets[], int i) {
    if (subsets[i].parent != i)
        subsets[i].parent = find(subsets, subsets[i].parent);
    return subsets[i].parent;
}

void Union(Subset subsets[], int x, int y) {
    int xroot = find(subsets, x);
    int yroot = find(subsets, y);

    if (subsets[xroot].rank < subsets[yroot].rank)
        subsets[xroot].parent = yroot;
    else if (subsets[xroot].rank > subsets[yroot].rank)
        subsets[yroot].parent = xroot;
    else {
        subsets[yroot].parent = xroot;
        subsets[xroot].rank++;
    }
}

int myComp(const void* a, const void* b) {
    return ((Edge*)a)->weight > ((Edge*)b)->weight;
}

void KruskalMST(Graph* graph) {
    int V = graph->V;
    Edge result[V];
    int e = 0;
    int i = 0;

    qsort(graph->edge, graph->E, sizeof(graph->edge[0]), myComp);

    Subset* subsets = new Subset[V];

    for (int v = 0; v < V; ++v) {
        subsets[v].parent = v;
        subsets[v].rank = 0;
    }

    while (e < V - 1 && i < graph->E) {
        Edge next_edge = graph->edge[i++];
        int x = find(subsets, next_edge.src);
        int y = find(subsets, next_edge.dest);

        if (x != y) {
            result[e++] = next_edge;
            Union(subsets, x, y);
        }
    }

    cout << "Following are the edges in the constructed MST\n";
    int minimumCost = 0;
    for (i = 0; i < e; ++i) {
        cout << result[i].src << " -- " << result[i].dest
             << " == " << result[i].weight << endl;
        minimumCost += result[i].weight;
    }

    cout << "Minimum Cost Spanning Tree: " << minimumCost << endl;
}

int main() {
    int V = 6;
    int E = 8;
    Graph* graph = new Graph(V, E);
    graph->edge[0] = {0, 1, 4};
    graph->edge[1] = {0, 5, 2};
    graph->edge[2] = {1, 2, 6};
    graph->edge[3] = {2, 3, 3};
    graph->edge[4] = {3, 4, 2};
    graph->edge[5] = {4, 5, 4};
    graph->edge[6] = {5, 1, 5};
    graph->edge[7] = {5, 2, 1};

    KruskalMST(graph);

    return 0;
}

