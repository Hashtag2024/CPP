#include <iostream>
#include <climits>

using namespace std;

#define vertices 5

int minimumKey(int k[], bool mst[]) {
    int min = INT_MAX, min_index;

    for (int i = 0; i < vertices; i++) {
        if (mst[i] == false && k[i] < min) {
            min = k[i];
            min_index = i;
        }
    }

    return min_index;
}

void prim(int g[vertices][vertices]) {
    int parent[vertices];
    int k[vertices];
    bool mst[vertices];

    for (int i = 0; i < vertices; i++) {
        k[i] = INT_MAX;
        mst[i] = false;
    }

    k[0] = 0;
    parent[0] = -1;

    for (int count = 0; count < vertices - 1; count++) {
        int u = minimumKey(k, mst);
        mst[u] = true;

        for (int v = 0; v < vertices; v++) {
            if (g[u][v] && mst[v] == false && g[u][v] < k[v]) {
                parent[v] = u;
                k[v] = g[u][v];
            }
        }
    }

    cout << "Edge \tWeight\n";
    for (int i = 1; i < vertices; i++) {
        cout << parent[i] << " - " << i << "\t" << g[i][parent[i]] << endl;
    }
}

int main() {
    int g[vertices][vertices] = {
        {0, 2, 0, 6, 0},
        {2, 0, 3, 8, 5},
        {0, 3, 0, 0, 7},
        {6, 8, 0, 0, 9},
        {0, 5, 7, 9, 0}
    };

    prim(g);

    return 0;
}

