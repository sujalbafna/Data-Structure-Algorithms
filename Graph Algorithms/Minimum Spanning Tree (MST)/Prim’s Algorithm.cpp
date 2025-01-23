#include <iostream>
#include <vector>
#include <climits>
#include <queue>

using namespace std;

// Function to implement Prim's Algorithm
void primMST(vector<vector<int>>& graph, int V) {
    // To store the parent of each vertex in the MST
    vector<int> parent(V, -1);
    // To keep track of the minimum edge weight
    vector<int> key(V, INT_MAX);
    // To track the vertices that are included in the MST
    vector<bool> inMST(V, false);
    
    // Min-heap to pick the vertex with the minimum edge weight
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    
    // Starting with the first vertex (0th vertex)
    key[0] = 0;
    pq.push({0, 0});
    
    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();
        
        inMST[u] = true;  // Mark the vertex as included in MST
        
        // Loop through all adjacent vertices
        for (int v = 0; v < V; ++v) {
            // If there is an edge from u to v and v is not in MST, and edge weight is smaller than the current key value of v
            if (graph[u][v] != 0 && !inMST[v] && graph[u][v] < key[v]) {
                key[v] = graph[u][v];
                parent[v] = u;
                pq.push({key[v], v});
            }
        }
    }
    
    // Printing the MST
    cout << "Edge \tWeight\n";
    for (int i = 1; i < V; ++i) {
        cout << parent[i] << " - " << i << "\t" << graph[i][parent[i]] << endl;
    }
}

int main() {
    int V, E;
    cout << "Enter number of vertices: ";
    cin >> V;
    
    cout << "Enter number of edges: ";
    cin >> E;
    
    // Initialize the graph with all edges having 0 weight
    vector<vector<int>> graph(V, vector<int>(V, 0));
    
    cout << "Enter the edges (u, v, weight) where u and v are vertices (0-based indexing):\n";
    for (int i = 0; i < E; ++i) {
        int u, v, weight;
        cin >> u >> v >> weight;
        graph[u][v] = weight;
        graph[v][u] = weight;  // Since the graph is undirected
    }
    
    // Calling Prim's Algorithm
    primMST(graph, V);
    
    return 0;
}
