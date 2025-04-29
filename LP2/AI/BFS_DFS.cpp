#include <iostream>
#include <vector>
#include <queue>
#include <stack>
using namespace std;

class Graph
{
    int V;
    vector<vector<int>> adj;

public:
    Graph(int x)
    {
        V = x;
        adj = vector<vector<int>>(V);
    }

    void addEdge(int u, int v)
    {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    void BFS(int s, int x)
    {
        bool ans = false;
        if (s == x)
        {
            cout << "Found! Start Node = Search Node" << endl;
            return;
        }

        vector<bool> visited(V, false);
        queue<int> q;
        q.push(s);
        visited[s] = true;

        while (!q.empty())
        {
            int a = q.front();
            if (a == x)
            {
                ans = true;
            }
            cout << a << " ";
            q.pop();

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
        if (ans)
        {
            cout << endl;
            cout << "Found!" << endl;
        }
        else
        {
            cout << endl;
            cout << "Not Found!" << endl;
        }
    }

    void DFS(int s, int x)
    {
        bool ans = false;
        if (s == x)
        {
            cout << "Found! Start Node = Search Node" << endl;
            return;
        }

        vector<bool> visited(V, false);
        stack<int> st;
        st.push(s);
        visited[s] = true;

        while (!st.empty())
        {
            int a = st.top();
            if (a == x)
            {
                ans = true;
            }
            cout << a << " ";
            st.pop();

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
        if (ans)
        {
            cout << endl;
            cout << "Found!" << endl;
        }
        else
        {
            cout << endl;
            cout << "Not Found!" << endl;
        }
    }

    void DFSUtil(int s, int x, vector<bool> &visited, bool &found)
    {
        visited[s] = true;
        cout << s << " ";
        if (s == x)
        {
            found = true;
            return; // Early return if found
        }

        for (int i = 0; i < adj[s].size(); i++)
        {
            int v = adj[s][i];
            if (!visited[v])
            {
                DFSUtil(v, x, visited, found);
                if (found)
                    return; // Stop further recursion once found
            }
        }
    }

    void DFSR(int s, int x)
    {
        bool found = false;
        vector<bool> visited(V, false);
        DFSUtil(s, x, visited, found);
        cout << endl;
        if (found)
        {
            cout << "Found!" << endl;
        }
        else
        {
            cout << "Not Found!" << endl;
        }
    }
};
int main()
{

    int V, E;
    cout << "Enter number of vertices: ";
    cin >> V;
    cout << "Enter number of edges: ";
    cin >> E;

    Graph g(V);

    cout << "Enter edges: " << endl;
    for (int i = 0; i < E; i++)
    {
        int u, v;
        cin >> u >> v;
        g.addEdge(u, v);
    }

    int s, x;
    cout << "Enter starting node for traversal: ";
    cin >> s;
    cout << "Enter node to search (x): ";
    cin >> x;

    g.BFS(s, x);
    g.DFS(s, x);
    g.DFSR(s, x);

    return 0;
}