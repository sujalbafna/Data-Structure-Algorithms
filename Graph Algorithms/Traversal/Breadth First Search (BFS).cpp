#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// Class to represent a graph
class Graph {
public:
    int V;  // Number of vertices
    vector<vector<int>> adjList;  // Adjacency list to store the graph

    // Constructor
    Graph(int V) {
        this->V = V;
        adjList.resize(V);
    }

    // Function to add an edge in the graph
    void addEdge(int u, int v) {
        adjList[u].push_back(v);  // Add v to u's list
        adjList[v].push_back(u);  // Add u to v's list (for undirected graph)
    }

    // BFS function (using a queue)
    void bfs(int start) {
        vector<bool> visited(V, false);  // To keep track of visited vertices
        queue<int> q;  // Queue to store vertices to visit

        // Mark the start node as visited and enqueue it
        visited[start] = true;
        q.push(start);

        cout << "BFS Traversal starting from node " << start << ": ";

        while (!q.empty()) {
            int node = q.front();
            q.pop();
            cout << node << " ";  // Visit the node

            // Visit all the adjacent unvisited vertices
            for (int neighbor : adjList[node]) {
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    q.push(neighbor);
                }
            }
        }
        cout << endl;
    }
};

int main() {
    int V, E, u, v;

    // Input the number of vertices and edges
    cout << "Enter the number of vertices: ";
    cin >> V;
    cout << "Enter the number of edges: ";
    cin >> E;

    Graph g(V);

    // Input the edges
    cout << "Enter the edges (u v):" << endl;
    for (int i = 0; i < E; i++) {
        cin >> u >> v;
        g.addEdge(u, v);
    }

    // Perform BFS starting from node 0
    g.bfs(0);

    return 0;
}
