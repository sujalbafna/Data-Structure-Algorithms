#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Graph {
public:
    int V;  // Number of vertices
    vector<vector<int>> dist;  // Distance matrix

    // Constructor
    Graph(int V) {
        this->V = V;
        dist.resize(V, vector<int>(V, INT_MAX));
    }

    // Function to add an edge to the graph
    void addEdge(int u, int v, int weight) {
        dist[u][v] = weight;  // Set the distance from u to v
        dist[v][u] = weight;  // Set the distance from v to u (for undirected graph)
    }

    // Floyd-Warshall algorithm to find the shortest paths
    void floydWarshall() {
        // Initialize the distance matrix (dist[i][j] is the shortest distance from i to j)
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                if (i == j) {
                    dist[i][j] = 0;  // Distance from a node to itself is 0
                }
            }
        }

        // Main algorithm: check all pairs of nodes
        for (int k = 0; k < V; k++) {
            for (int i = 0; i < V; i++) {
                for (int j = 0; j < V; j++) {
                    // If the distance through node k is shorter, update the distance
                    if (dist[i][k] != INT_MAX && dist[k][j] != INT_MAX && dist[i][j] > dist[i][k] + dist[k][j]) {
                        dist[i][j] = dist[i][k] + dist[k][j];
                    }
                }
            }
        }

        // Output the shortest distances
        cout << "Shortest distances between every pair of nodes:" << endl;
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                if (dist[i][j] == INT_MAX) {
                    cout << "INF ";
                } else {
                    cout << dist[i][j] << " ";
                }
            }
            cout << endl;
        }
    }
};

int main() {
    int V, E, u, v, weight;

    // Input the number of vertices and edges
    cout << "Enter the number of vertices: ";
    cin >> V;
    cout << "Enter the number of edges: ";
    cin >> E;

    Graph g(V);

    // Input the edges
    cout << "Enter the edges (u v weight):" << endl;
    for (int i = 0; i < E; i++) {
        cin >> u >> v >> weight;
        g.addEdge(u, v, weight);
    }

    // Perform Floyd-Warshall algorithm
    g.floydWarshall();

    return 0;
}
