/*
Minimum Spanning Tree (MST)
A subset of the edges in a connected, weighted graph that connects all vertices with the minimum total edge weight, and no cycles.
*/

#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;

int minVertex(vector<int> &key , vector<bool> &mst, int v )
{
    int minval = INT_MAX;
    int ind = -1;
    
    for(int i=0; i<v; i++)
    {
        if(key[i]<minval && !mst[i])
        {
            minval = key[i];
            ind = i;
        }
    }
    return ind;
}

void primMST(vector<vector<int>> graph,int v)
{
    vector<int> parent (v,-1);
    vector<int> key(v,INT_MAX);
    vector<bool> mst(v,false);
    
    int cost = 0;
    key[0] = 0;
    
    for(int i=0; i<v-1; i++)
    {
        int u = minVertex(key,mst,v);
        mst[u] = true;
        
        for(int a = 0; a<v; a++)
        {
            if(graph[u][a]>0 && !mst[a] && key[a]>graph[u][a])
            {
                key[a] = graph[u][a];
                parent[a] = u;
            }
        }
    }
    
    cout << "\nEdge \tWeight\n";
    for(int i=1; i<v; i++)
    {
        cout<<parent[i]<<" - "<<i<<" \t"<<graph[i][parent[i]]<<endl;
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
0 - 1 	2
1 - 2 	3
0 - 3 	6
1 - 4 	5
Total Cost = 16

*/