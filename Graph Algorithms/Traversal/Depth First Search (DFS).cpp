#include <iostream>
#include <vector>
#include <stack>
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

    // DFS function (using recursion)
    void dfs(int start, vector<bool>& visited) {
        // Mark the current node as visited and print it
        visited[start] = true;
        cout << start << " ";

        // Recur for all the adjacent vertices
        for (int neighbor : adjList[start]) {
            if (!visited[neighbor]) {
                dfs(neighbor, visited);
            }
        }
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

    // Perform DFS starting from node 0
    vector<bool> visited(V, false);  // To keep track of visited vertices
    cout << "DFS Traversal starting from node 0: ";
    g.dfs(0, visited);

    return 0;
}
