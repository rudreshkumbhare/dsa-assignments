#include <iostream>
#include <string>
using namespace std;

#define MAX 10
#define INF 99999

class Graph {
public:
    int cost[MAX][MAX];
    string department[MAX];
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
        cout << "\nEnter department names:\n";

        for (int i = 0; i < V; i++) {
            cout << i << ". ";
            cin >> department[i];
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
            cout << department[i] << "\t";
        }
        cout << "\n";

        for (int i = 0; i < V; i++) {
            cout << department[i] << "\t";

            for (int j = 0; j < V; j++) {
                if (cost[i][j] == INF) cout << "INF\t";
                else cout << cost[i][j] << "\t";
            }
            cout << "\n";
        }
    }

    void prim() {
        int dist[MAX], parent[MAX];
        bool visited[MAX];

        for (int i = 0; i < V; i++) {
            dist[i] = INF;
            parent[i] = -1;
            visited[i] = false;
        }

        dist[0] = 0;

        for (int i = 0; i < V; i++) {
            int minimum = INF, u = -1;

            for (int j = 0; j < V; j++) {
                if (!visited[j] && dist[j] < minimum) {
                    minimum = dist[j];
                    u = j;
                }
            }

            if (u == -1) {
                cout << "\nGraph is disconnected, MST cannot be formed.\n";
                return;
            }

            visited[u] = true;

            for (int v = 0; v < V; v++) {
                if (cost[u][v] != INF &&
                    cost[u][v] != 0 &&
                    !visited[v] &&
                    cost[u][v] < dist[v]) {

                    dist[v] = cost[u][v];
                    parent[v] = u;
                }
            }
        }

        int totalCost = 0;

        cout << "\nMinimum Spanning Tree:\n";
        cout << "Connection\tDistance\n";

        for (int i = 1; i < V; i++) {
            cout << department[parent[i]] << " - "
                 << department[i] << "\t"
                 << cost[i][parent[i]] << "\n";

            totalCost += cost[i][parent[i]];
        }

        cout << "Total MST distance = " << totalCost << endl;
    }
};

int main() {
    int n;

    cout << "Enter number of departments (max 10): ";
    cin >> n;

    if (n < 1 || n > MAX) {
        cout << "Invalid number of departments.\n";
        return 0;
    }

    Graph g(n);

    g.createGraph();
    g.display();
    g.prim();

    return 0;
}