#include <iostream>
#include <string>
using namespace std;

#define MAX 10
#define INF 99999

class Graph {
public:
    int cost[MAX][MAX];
    string vertex[MAX];
    int V;

    Graph(int n) {
        V = n;

        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                cost[i][j] = (i == j) ? 0 : INF;
            }
        }
    }

    void createGraph() {
        cout << "\nEnter vertex names:\n";

        for (int i = 0; i < V; i++) {
            cout << i << ". ";
            cin >> vertex[i];
        }

        int edges;
        cout << "\nEnter number of connections: ";
        cin >> edges;

        cout << "Enter connections (source destination distance):\n";

        for (int i = 0; i < edges; i++) {
            int u, v, distance;
            cin >> u >> v >> distance;

            cost[u][v] = distance;
            cost[v][u] = distance;
        }
    }

    void display() {
        cout << "\nAdjacency Matrix:\n\t";

        for (int i = 0; i < V; i++) {
            cout << vertex[i] << "\t";
        }
        cout << "\n";

        for (int i = 0; i < V; i++) {
            cout << vertex[i] << "\t";

            for (int j = 0; j < V; j++) {
                if (cost[i][j] == INF) cout << "INF\t";
                else cout << cost[i][j] << "\t";
            }
            cout << "\n";
        }
    }

    void dijkstra(int start) {
        int dist[MAX], parent[MAX];
        bool visited[MAX];

        for (int i = 0; i < V; i++) {
            dist[i] = INF;
            parent[i] = -1;
            visited[i] = false;
        }

        dist[start] = 0;

        for (int i = 0; i < V - 1; i++) {
            int minimum = INF, u = -1;

            for (int j = 0; j < V; j++) {
                if (!visited[j] && dist[j] < minimum) {
                    minimum = dist[j];
                    u = j;
                }
            }

            if (u == -1) break;

            visited[u] = true;

            for (int v = 0; v < V; v++) {
                if (cost[u][v] != INF &&
                    cost[u][v] != 0 &&
                    !visited[v]) {

                    int newDist = dist[u] + cost[u][v];

                    if (newDist < dist[v]) {
                        dist[v] = newDist;
                        parent[v] = u;
                    }
                }
            }
        }

        cout << "\nVertex\tDistance\tParent\n";

        for (int i = 0; i < V; i++) {
            cout << vertex[i] << "\t";

            if (dist[i] == INF) cout << "INF\t";
            else cout << dist[i] << "\t";

            if (parent[i] == -1) cout << "-";
            else cout << vertex[parent[i]];

            cout << "\n";
        }
    }
};

int main() {
    int n;

    cout << "Enter number of vertices (max 10): ";
    cin >> n;

    if (n < 1 || n > MAX) {
        cout << "Invalid number of vertices.\n";
        return 0;
    }

    Graph g(n);

    g.createGraph();
    g.display();

    int start;
    cout << "\nEnter starting vertex index (0 to " << n - 1 << "): ";
    cin >> start;

    if (start < 0 || start >= n) {
        cout << "Invalid starting vertex.\n";
        return 0;
    }

    g.dijkstra(start);

    return 0;
}