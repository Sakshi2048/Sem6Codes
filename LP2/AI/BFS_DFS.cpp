#include <iostream>
#include <vector>
#include <queue>
#include <stack>
using namespace std;

void BFS(vector<vector<int>> &adj, int s, int x)
{
    int V = adj.size();
    bool found = false;

    if (s == x)
    {
        cout << "Found! Start Node = Search Node" << endl;
        return;
    }

    vector<bool> visited(V, false);
    queue<int> q;
    q.push(s);
    visited[s] = true;

    cout << "BFS Iterative: ";
    while (!q.empty())
    {
        int a = q.front();
        q.pop();
        cout << a << " ";
        if (a == x)
            found = true;

        for (int i = 0; i < adj[a].size(); i++)
        {
            int m = adj[a][i];
            if (!visited[m])
            {
                visited[m] = true;
                q.push(m);
            }
        }
    }

    cout << endl
         << (found ? "Found!" : "Not Found!") << endl;
}

void DFS(vector<vector<int>> &adj, int s, int x)
{
    int V = adj.size();
    bool found = false;

    if (s == x)
    {
        cout << "Found! Start Node = Search Node" << endl;
        return;
    }

    vector<bool> visited(V, false);
    stack<int> st;
    st.push(s);
    visited[s] = true;

    cout << "DFS Iterative: ";
    while (!st.empty())
    {
        int a = st.top();
        st.pop();
        cout << a << " ";
        if (a == x)
            found = true;

        for (int i = 0; i < adj[a].size(); i++)
        {
            int m = adj[a][i];
            if (!visited[m])
            {
                visited[m] = true;
                st.push(m);
            }
        }
    }

    cout << endl
         << (found ? "Found!" : "Not Found!") << endl;
}

void DFSUtil(vector<vector<int>> &adj, vector<bool> &visited, bool &found, int s, int x)
{
    visited[s] = true;
    cout << s << " ";
    if (s == x)
    {
        found = true;
        return;
    }

    for (int i = 0; i < adj[s].size(); i++)
    {
        int m = adj[s][i];
        if (!visited[m])
        {
            DFSUtil(adj, visited, found, m, x);
            if (found)
                return;
        }
    }
}

void DFSR(vector<vector<int>> &adj, int s, int x)
{
    int V = adj.size();
    vector<bool> visited(V, false);
    bool found = false;

    cout << "DFS Recursive: ";
    DFSUtil(adj, visited, found, s, x);

    cout << endl
         << (found ? "Found!" : "Not Found!") << endl;
}

void DLSearchUtil(vector<vector<int>> &adj, vector<bool> &visited, bool &found, int s, int x, int limit, int depth)
{
    visited[s] = true;
    cout << s << " ";

    if (s == x)
    {
        found = true;
        return;
    }

    if (depth >= limit)
        return;

    for (int i = 0; i < adj[s].size(); i++)
    {
        int m = adj[s][i];
        if (!visited[m])
        {
            DLSearchUtil(adj, visited, found, m, x, limit, depth + 1);
            if (found)
                return;
        }
    }
}

void DLSearch(vector<vector<int>> &adj, int s, int x, int limit)
{
    int V = adj.size();
    vector<bool> visited(V, false);
    bool found = false;

    cout << "Depth-Limited Search (limit " << limit << "): ";
    DLSearchUtil(adj, visited, found, s, x, limit, 0);

    cout << endl
         << (found ? "Found!" : "Not Found!") << endl;
}

int main()
{
    int V, E;
    cout << "Enter number of vertices: ";
    cin >> V;
    cout << "Enter number of edges: ";
    cin >> E;

    vector<vector<int>> adj(V);
    cout << "Enter edges (u v):" << endl;
    for (int i = 0; i < E; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u); // undirected graph
    }

    int s, x;
    cout << "Enter start node: ";
    cin >> s;
    cout << "Enter node to search: ";
    cin >> x;

    int choice;
    cout << "\nChoose Traversal:\n";
    cout << "1. BFS\n";
    cout << "2. DFS (Iterative)\n";
    cout << "3. DFS (Recursive)\n";
    cout << "4. Depth-Limited Search\n"; // new option
    cout << "Enter your choice: ";
    cin >> choice;

    cout << endl;
    switch (choice)
    {
    case 1:
        BFS(adj, s, x);
        break;
    case 2:
        DFS(adj, s, x);
        break;
    case 3:
        DFSR(adj, s, x);
        break;
    case 4:
    {
        int limit;
        cout << "Enter depth limit: ";
        cin >> limit;
        DLSearch(adj, s, x, limit);
        break;
    }

    default:
        cout << "Invalid Choice" << endl;
    }

    return 0;
}