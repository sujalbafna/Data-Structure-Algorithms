#include <iostream>
#include <vector>
#include <climits>
using namespace std;

// Structure to represent an edge in the graph
struct Edge {
    int u, v, weight;
};

class Graph {
public:
    int V, E;  // Number of vertices and edges
    vector<Edge> edges;  // List of edges

    // Constructor
    Graph(int V, int E) {
        this->V = V;
        this->E = E;
    }

    // Function to add an edge to the graph
    void addEdge(int u, int v, int weight) {
        edges.push_back({u, v, weight});
    }

    // Bellman-Ford algorithm to find the shortest path
    void bellmanFord(int source) {
        // Initialize distance array with infinity
        vector<int> dist(V, INT_MAX);
        dist[source] = 0;

        // Relax all edges (V-1) times
        for (int i = 1; i < V; i++) {
            for (const auto& edge : edges) {
                int u = edge.u;
                int v = edge.v;
                int weight = edge.weight;

                // If the distance to the destination can be shortened
                if (dist[u] != INT_MAX && dist[u] + weight < dist[v]) {
                    dist[v] = dist[u] + weight;
                }
            }
        }

        // Check for negative weight cycle
        for (const auto& edge : edges) {
            int u = edge.u;
            int v = edge.v;
            int weight = edge.weight;

            // If we can still relax an edge, there is a negative weight cycle
            if (dist[u] != INT_MAX && dist[u] + weight < dist[v]) {
                cout << "Graph contains a negative weight cycle" << endl;
                return;
            }
        }

        // Output the shortest distances from the source
        cout << "Shortest distances from node " << source << ":" << endl;
        for (int i = 0; i < V; i++) {
            if (dist[i] == INT_MAX) {
                cout << "Node " << i << ": Unreachable" << endl;
            } else {
                cout << "Node " << i << ": " << dist[i] << endl;
            }
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

    Graph g(V, E);

    // Input the edges
    cout << "Enter the edges (u v weight):" << endl;
    for (int i = 0; i < E; i++) {
        cin >> u >> v >> weight;
        g.addEdge(u, v, weight);
    }

    // Perform Bellman-Ford algorithm starting from node 0
    g.bellmanFord(0);

    return 0;
}
