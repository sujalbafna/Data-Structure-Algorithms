#include <iostream>
#include <vector>
#include <climits>
#include <queue>
using namespace std;

// Class to represent a graph
class Graph {
public:
    int V;  // Number of vertices
    vector<vector<pair<int, int>>> adjList;  // Adjacency list to store the graph (pair: <neighbor, weight>)

    // Constructor
    Graph(int V) {
        this->V = V;
        adjList.resize(V);
    }

    // Function to add an edge to the graph
    void addEdge(int u, int v, int weight) {
        adjList[u].push_back({v, weight});  // Add edge u -> v with weight
        adjList[v].push_back({u, weight});  // Add edge v -> u for undirected graph
    }

    // Dijkstra's algorithm to find the shortest path
    void dijkstra(int start) {
        vector<int> dist(V, INT_MAX);  // Initialize distances with infinity
        dist[start] = 0;  // Distance to the start node is 0

        // Min-heap to store {distance, vertex}, sorted by distance
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, start});  // Push the start node with distance 0

        while (!pq.empty()) {
            // Get the node with the smallest tentative distance
            int u = pq.top().second;
            int currentDist = pq.top().first;
            pq.pop();

            // Skip processing if the distance is not up-to-date
            if (currentDist > dist[u]) continue;

            // Explore neighbors
            for (auto& neighbor : adjList[u]) {
                int v = neighbor.first;
                int weight = neighbor.second;

                // Relax the edge if a shorter path is found
                if (dist[u] + weight < dist[v]) {
                    dist[v] = dist[u] + weight;
                    pq.push({dist[v], v});  // Add the neighbor to the priority queue
                }
            }
        }

        // Output the shortest distances from the start node
        cout << "Shortest distances from node " << start << ":" << endl;
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

    Graph g(V);

    // Input the edges
    cout << "Enter the edges (u v weight):" << endl;
    for (int i = 0; i < E; i++) {
        cin >> u >> v >> weight;
        g.addEdge(u, v, weight);
    }

    // Perform Dijkstra's algorithm starting from node 0
    g.dijkstra(0);

    return 0;
}
