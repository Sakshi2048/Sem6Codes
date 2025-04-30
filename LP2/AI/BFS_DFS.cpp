#include <iostream>
#include <vector>
#include <queue>
#include <stack>
using namespace std;

class Graph {
    int V;
    vector<vector<int>> adj;

public:
    Graph(int x) {
        V = x;
        adj = vector<vector<int>>(V);
    }

    void addEdge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    void BFS(int s, int x) {
        bool ans = false;
        if (s == x) {
            cout << "Found! Start Node = Search Node" << endl;
            return;
        }

        vector<bool> visited(V, false);
        queue<int> q;
        q.push(s);
        visited[s] = true;

        while (!q.empty()) {
            int a = q.front();
            if (a == x) {
                ans = true;
            }
            cout << a << " ";
            q.pop();

            for (int i = 0; i < adj[a].size(); i++) {
                int m = adj[a][i];
                if (!visited[m]) {
                    visited[m] = true;
                    q.push(m);
                }
            }
        }
        cout << endl;
        if (ans)
            cout << "Found!" << endl;
        else
            cout << "Not Found!" << endl;
    }

    void BFSRecursiveUtil(queue<int> &q, vector<bool> &visited, int x, bool &found) {
        if (q.empty()) return;

        int a = q.front();
        q.pop();
        cout << a << " ";

        if (a == x) {
            found = true;
            return;
        }

        for (int i = 0; i < adj[a].size(); i++) {
            int m = adj[a][i];
            if (!visited[m]) {
                visited[m] = true;
                q.push(m);
            }
        }

        BFSRecursiveUtil(q, visited, x, found);
    }

    void BFSR(int s, int x) {
        if (s == x) {
            cout << "Found! Start Node = Search Node" << endl;
            return;
        }

        vector<bool> visited(V, false);
        queue<int> q;
        visited[s] = true;
        q.push(s);

        bool found = false;
        cout << "Recursive BFS: ";
        BFSRecursiveUtil(q, visited, x, found);

        cout << endl;
        if (found)
            cout << "Found!" << endl;
        else
            cout << "Not Found!" << endl;
    }

    void DFS(int s, int x) {
        bool ans = false;
        if (s == x) {
            cout << "Found! Start Node = Search Node" << endl;
            return;
        }

        vector<bool> visited(V, false);
        stack<int> st;
        st.push(s);
        visited[s] = true;

        while (!st.empty()) {
            int a = st.top();
            if (a == x) {
                ans = true;
            }
            cout << a << " ";
            st.pop();

            for (int i = 0; i < adj[a].size(); i++) {
                int m = adj[a][i];
                if (!visited[m]) {
                    visited[m] = true;
                    st.push(m);
                }
            }
        }

        cout << endl;
        if (ans)
            cout << "Found!" << endl;
        else
            cout << "Not Found!" << endl;
    }

    void DFSUtil(int s, int x, vector<bool> &visited, bool &found) {
        visited[s] = true;
        cout << s << " ";
        if (s == x) {
            found = true;
            return;
        }

        for (int i = 0; i < adj[s].size(); i++) {
            int v = adj[s][i];
            if (!visited[v]) {
                DFSUtil(v, x, visited, found);
                if (found) return;
            }
        }
    }

    void DFSR(int s, int x) {
        bool found = false;
        vector<bool> visited(V, false);
        DFSUtil(s, x, visited, found);
        cout << endl;
        if (found)
            cout << "Found!" << endl;
        else
            cout << "Not Found!" << endl;
    }
};

int main() {
    int V, E;
    cout << "Enter number of vertices: ";
    cin >> V;
    cout << "Enter number of edges: ";
    cin >> E;

    Graph g(V);

    cout << "Enter edges: " << endl;
    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;
        g.addEdge(u, v);
    }

    int s, x;
    cout << "Enter starting node for traversal: ";
    cin >> s;
    cout << "Enter node to search (x): ";
    cin >> x;

    cout << endl << "BFS Iterative:" << endl;
    g.BFS(s, x);

    cout << endl << "BFS Recursive:" << endl;
    g.BFSR(s, x);

    cout << endl << "DFS Iterative:" << endl;
    g.DFS(s, x);

    cout << endl << "DFS Recursive:" << endl;
    g.DFSR(s, x);

    return 0;
}
