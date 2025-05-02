#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Node {
public:
    int x;
    int y;
    int g;
    int h;
    int f;
    Node* parent;

    Node(int a, int b, int c, int d, Node* parentNode) {
        x = a;
        y = b;
        g = c;
        h = d;
        f = g + h;
        parent = parentNode;
    }
};

class Compare {
public:
    bool operator()(Node* a, Node* b) {
        if(a->f > b->f)
        {
            return true;
        }
        return false;
    }
};

int hDistance(int x1, int y1, int x2, int y2) {
    if(abs(x1 - x2) + abs(y1 - y2))
    {
        return 1;
    }
    return 0;
}

bool isValid(int x, int y, int rows, int cols, vector<vector<int>>& grid) {
    if(x >= 0 && y >= 0 && x < rows && y < cols && grid[x][y] == 0)
    {
        return true;
    }
    return false;
}

vector<pair<int, int>> aStar(vector<vector<int>>& grid, pair<int, int> start, pair<int, int> goal) {
    int rows = grid.size();
    int cols = grid[0].size();

    priority_queue<Node*, vector<Node*>, Compare> openList;
    unordered_map<int, Node*> visited;

    Node* startNode = new Node(start.first, start.second, 0, hDistance(start.first, start.second, goal.first, goal.second), NULL);
    
    openList.push(startNode);

    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, -1, 1};

    while (!openList.empty()) {
        Node* current = openList.top();
        openList.pop();

        if (current->x == goal.first && current->y == goal.second) {
            vector<pair<int, int>> path;
            while (current != NULL) {
                path.push_back({current->x, current->y});
                current = current->parent;
            }
            reverse(path.begin(), path.end());
            return path;
        }

        int key = current->x * cols + current->y;
        visited[key] = current;

        for (int i = 0; i < 4; i++) {
            int nx = current->x + dx[i];
            int ny = current->y + dy[i];

            if (isValid(nx, ny, rows, cols, grid)) {
                int gNew = current->g + 1;
                int hNew = hDistance(nx, ny, goal.first, goal.second);
                int fNew = gNew + hNew;

                int nKey = nx * cols + ny;
                if (visited.find(nKey) == visited.end() || visited[nKey]->f > fNew) {
                    Node* neighbor = new Node(nx, ny, gNew, hNew, current);
                    openList.push(neighbor);
                    visited[nKey] = neighbor;
                }
            }
        }
    }

    return {};
}

int main() {
    int rows, cols;
    cout << "Enter number of rows: ";
    cin >> rows;
    cout << "Enter number of columns: ";
    cin >> cols;

    vector<vector<int>> grid(rows, vector<int>(cols));
    cout << "Enter grid values (0 = free, 1 = blocked):" << endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cin >> grid[i][j];
        }
    }

    pair<int, int> start, goal;
    cout << "Enter start: ";
    cin >> start.first >> start.second;
    cout << "Enter goal: ";
    cin >> goal.first >> goal.second;

    vector<pair<int, int>> path = aStar(grid, start, goal);

    if (!path.empty()) {
        cout<<endl;
        cout << "Path found:" << endl;
        for (int i = 0; i < path.size(); i++) {
            cout << "(" << path[i].first << ", " << path[i].second << ")";
            if (i != path.size() - 1) {
                cout << " -> ";
            }
        }
        cout << endl;
    } 
    else {
        cout << "No path found" << endl;
    }

    return 0;
}

/*
Example
--------
Enter number of rows: 4
Enter number of columns: 5
Enter grid values (0 = free, 1 = blocked):
0 0 0 0 0
0 1 0 0 0
0 0 0 0 0
0 0 0 0 0
Enter start: 3 0 
Enter goal: 1 2

Path found:
(3, 0) -> (2, 0) -> (2, 1) -> (2, 2) -> (1, 2)

*/
