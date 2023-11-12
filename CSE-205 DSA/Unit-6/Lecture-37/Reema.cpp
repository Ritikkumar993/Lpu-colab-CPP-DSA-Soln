//all testcase is running
#include <iostream>
#include <vector>
#include <string>
using namespace std;

const int INF = 1e7;

void printPath(int src, int dest, vector<vector<int>>& next) {
    if (next[src][dest] == -1) {
        cout << src;
        return;
    }

    cout << src << " -> ";
    while (src != dest) {
        src = next[src][dest];
        cout << src;
        if (src != dest) {
            cout << " -> ";
        }
    }
}

void floydWarshall(int V, vector<vector<int>>& graph, int dest) {
    vector<vector<int>> dist(V, vector<int>(V, 0));
    vector<vector<int>> next(V, vector<int>(V, -1));

    // Initialize distance and next arrays
    for (int i = 0; i < V; ++i) {
        for (int j = 0; j < V; ++j) {
            dist[i][j] = graph[i][j];
            if (graph[i][j] != INF && i != j) {
                next[i][j] = j;
            }
        }
    }

    // Apply Floyd-Warshall algorithm
    for (int k = 0; k < V; ++k) {
        for (int i = 0; i < V; ++i) {
            for (int j = 0; j < V; ++j) {
                if (dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                    next[i][j] = next[i][k];
                }
            }
        }
    }

    // Print the shortest path from Earth to the destination planet
    cout << "Shortest path from Earth to planet " << dest << ": ";
    printPath(0, dest, next);
}

int main() {
    int V;
    cin >> V;

    vector<vector<int>> graph(V, vector<int>(V));
    for (int i = 0; i < V; ++i) {
        for (int j = 0; j < V; ++j) {
            cin >> graph[i][j];
            if (graph[i][j] == 0 && i != j) {
                graph[i][j] = INF;
            }
        }
    }

    int dest;
    cin >> dest;

    floydWarshall(V, graph, dest);

    return 0;
}
