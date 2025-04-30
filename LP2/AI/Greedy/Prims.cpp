/*
Minimum Spanning Tree (MST)
A subset of the edges in a connected, weighted graph that connects all vertices with the minimum total edge weight, and no cycles.

Algorithms: Prim's and Kruskal's
*/

#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;

int findMinVertex(vector<int> &key, vector<bool> &mstSet, int V) {
    int min = INT_MAX, vertex = -1;
    for (int i = 0; i < V; i++) {
        if (!mstSet[i] && key[i] < min) {
            min = key[i];
            vertex = i;
        }
    }
    return vertex;
}

void primMST(vector<vector<int>> &graph, int V) {
    vector<int> parent(V, -1);
    vector<int> key(V, INT_MAX);
    vector<bool> mstSet(V, false);

    key[0] = 0; // Start from node 0

    for (int count = 0; count < V - 1; count++) {
        int u = findMinVertex(key, mstSet, V);
        mstSet[u] = true;

        for (int v = 0; v < V; v++) {
            if (graph[u][v] && !mstSet[v] && graph[u][v] < key[v]) {
                key[v] = graph[u][v];
                parent[v] = u;
            }
        }
    }

    int cost = 0;

    cout << "\nEdge \tWeight\n";
    for (int i = 1; i < V; i++){
        cout << parent[i] << " - " << i << "\t" << graph[i][parent[i]] << endl;
        cost+=graph[i][parent[i]];
    }
    
    cout<<"Total Cost = "<<cost<<endl;
}

int main() {
    int V;
    cout << "Enter number of vertices: ";
    cin >> V;

    vector<vector<int>> graph(V, vector<int>(V));
    
    cout << "Enter adjacency matrix:\n";
    for (int i = 0; i < V; i++)
        for (int j = 0; j < V; j++)
            cin >> graph[i][j];

    primMST(graph, V);
    return 0;
}


/*
Example 
-------
Enter number of vertices: 5
Enter adjacency matrix:
0 2 0 6 0
2 0 3 8 5
0 3 0 0 7
6 8 0 0 0
0 5 7 0 0

Edge 	Weight
0 - 1	2
1 - 2	3
0 - 3	6
1 - 4	5
Total Cost = 16

*/