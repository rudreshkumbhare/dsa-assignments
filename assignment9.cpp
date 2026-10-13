#include <iostream>
#include <stack>
#include <queue>
using namespace std;

class Node {
public:
    int vertex;
    Node *next;

    Node() {
        next = NULL;
    }
};

class Graph {
public:
    Node **adjlist;
    int numbers;

    Graph(int number) {
        numbers = number;
        adjlist = new Node*[number];

        for (int i = 0; i < number; i++) {
            adjlist[i] = NULL;
        }
    }

    void addedge(int src, int dest) {
        Node *newnode = new Node();
        newnode->vertex = dest;
        newnode->next = adjlist[src];
        adjlist[src] = newnode;

        Node *second = new Node();
        second->vertex = src;
        second->next = adjlist[dest];
        adjlist[dest] = second;
    }

    void display() {
        cout << "\nAdjacency List:\n";

        for (int i = 0; i < numbers; i++) {
            cout << i << " -> ";
            Node *temp = adjlist[i];

            while (temp != NULL) {
                cout << temp->vertex << " ";
                temp = temp->next;
            }

            cout << "\n";
        }
    }

    void DFS(int start, int goal) {
        stack<int> s;
        int visited[100] = {0};
        int parent[100];

        for (int i = 0; i < numbers; i++) {
            parent[i] = -1;
        }

        s.push(start);
        visited[start] = 1;

        while (!s.empty()) {
            int v = s.top();
            s.pop();

            if (v == goal) break;

            Node *temp = adjlist[v];

            while (temp != NULL) {
                int i = temp->vertex;
                if (!visited[i]) {
                    visited[i] = 1;
                    parent[i] = v;
                    s.push(i);
                }
                temp = temp->next;
            }
        }

        int path[100];
        int count = 0;
        int v = goal;

        if (!visited[goal]) {
            cout << "\nNo path found using DFS.\n";
            return;
        }

        while (v != -1) {
            path[count++] = v;
            v = parent[v];
        }

        cout << "\nDFS Path: ";

        for (int i = count - 1; i >= 0; i--) {
            cout << path[i] << " ";
        }
        cout << endl;
    }

    void BFS(int start, int goal) {
        queue<int> q;
        int visited[100] = {0};
        int parent[100];

        for (int i = 0; i < numbers; i++) {
            parent[i] = -1;
        }

        q.push(start);
        visited[start] = 1;

        while (!q.empty()) {
            int v = q.front();
            q.pop();

            if (v == goal) break;

            Node *temp = adjlist[v];

            while (temp != NULL) {
                int i = temp->vertex;
                if (!visited[i]) {
                    visited[i] = 1;
                    parent[i] = v;
                    q.push(i);
                }
                temp = temp->next;
            }
        }

        if (!visited[goal]) {
            cout << "\nNo path found using BFS.\n";
            return;
        }

        int path[100];
        int count = 0;
        int v = goal;

        while (v != -1) {
            path[count++] = v;
            v = parent[v];
        }

        cout << "\nBFS Path: ";

        for (int i = count - 1; i >= 0; i--) {
            cout << path[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    const int ROWS = 4;
    const int COLS = 4;

    // change the maze configuration as needed
    char maze[ROWS][COLS] = {
        {'S', '.', '.', '.'},
        {'.', '#', '#', '.'},
        {'.', '.', '.', '.'},
        {'#', '#', '#', 'G'}
    };

    cout << "Maze:\n";

    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            cout << maze[i][j] << " ";
        }
        cout << endl;
    }

    Graph g(ROWS * COLS);

    int start = 0;
    int goal = ROWS * COLS - 1;

    int rowmove[4] = {-1, 1, 0, 0};
    int colmove[4] = {0, 0, -1, 1};

    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (maze[i][j] == '#') {
                continue;
            }

            int src = i * COLS + j;

            for (int k = 0; k < 4; k++) {
                int nr = i + rowmove[k];
                int nc = j + colmove[k];

                if (nr >= 0 && nr < ROWS &&
                    nc >= 0 && nc < COLS &&
                    maze[nr][nc] != '#') {

                    int dest = nr * COLS + nc;

                    if (src < dest) {
                        g.addedge(src, dest);
                    }
                }
            }
        }
    }

    g.display();

    cout << "\nStart: " << start;
    cout << "\nGoal: " << goal << endl;

    g.DFS(start, goal);
    g.BFS(start, goal);

    return 0;
}