#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Edge {
public:
    int u, v, weight;
    Edge(int a, int b, int w) {
        u = a;
        v = b;
        weight = w;
    }
};

bool compare(Edge a, Edge b) {
    return a.weight < b.weight;
}

void kruskalNaive(int V, vector<Edge>& edges) {
    vector<int> component(V);
    for (int i = 0; i < V; i++)
        component[i] = i;

    sort(edges.begin(), edges.end(), compare);

    int cost = 0;
    cout << "Edges in the MST:" << endl;

    for (Edge e : edges) {
        if (component[e.u] != component[e.v]) {
            cout << e.u << " - " << e.v << " \t" << e.weight << endl;
            cost += e.weight;

            int oldComp = component[e.v];
            int newComp = component[e.u];

            for (int i = 0; i < V; i++) {
                if (component[i] == oldComp)
                    component[i] = newComp;
            }
        }
    }

    cout << "Total Cost = " << cost << endl;
}

int main() {
    int V, E;
    cout << "Enter number of vertices and edges: ";
    cin >> V >> E;

    vector<Edge> edges;

    cout << "Enter edges (u v weight):" << endl;
    for (int i = 0; i < E; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        edges.push_back(Edge(u, v, w));
    }

    kruskalNaive(V, edges);

    return 0;
}

/*
Example
-------

Enter number of vertices and edges: 5 6
Enter edges (u v weight):
0 1 2
0 3 6
1 3 8
1 2 3
1 4 5
4 2 7
Edges in the MST:
0 - 1 	2
1 - 2 	3
1 - 4 	5
0 - 3 	6
Total Cost = 16


*/