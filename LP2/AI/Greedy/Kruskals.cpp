#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Edge {
    int u, v, weight;
};

bool compare(Edge a, Edge b) {
    return a.weight < b.weight;
}

int findParent(int node, vector<int> &parent) {
    if (parent[node] == node) return node;
    return parent[node] = findParent(parent[node], parent); // Path compression
}

void unionSet(int a, int b, vector<int> &parent) {
    a = findParent(a, parent);
    b = findParent(b, parent);
    if (a != b) parent[b] = a;
}

void kruskalMST(int V, vector<Edge> &edges) {
    sort(edges.begin(), edges.end(), compare);
    vector<int> parent(V);
    for (int i = 0; i < V; i++) parent[i] = i;

    vector<Edge> result;

    for (Edge e : edges) {
        if (findParent(e.u, parent) != findParent(e.v, parent)) {
            result.push_back(e);
            unionSet(e.u, e.v, parent);
        }
    }

    cout << "\nEdge \tWeight\n";
    for (Edge e : result)
        cout << e.u << " - " << e.v << "\t" << e.weight << endl;
}

int main() {
    int V, E;
    cout << "Enter number of vertices and edges: ";
    cin >> V >> E;

    vector<Edge> edges(E);
    cout << "Enter edges (u v weight):\n";
    for (int i = 0; i < E; i++) {
        cin >> edges[i].u >> edges[i].v >> edges[i].weight;
    }

    kruskalMST(V, edges);
    return 0;
}
