#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// A structure to represent an edge in the graph
struct Edge {
    int u, v, weight;
    
    // Overloading the < operator to sort edges by weight
    bool operator<(const Edge& e) const {
        return weight < e.weight;
    }
};

// A class to represent Disjoint Set Union (DSU) / Union-Find data structure
class DisjointSet {
private:
    vector<int> parent, rank;

public:
    DisjointSet(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; ++i)
            parent[i] = i;
    }

    int find(int u) {
        if (parent[u] != u)
            parent[u] = find(parent[u]);  // Path compression
        return parent[u];
    }

    void unionSet(int u, int v) {
        int rootU = find(u);
        int rootV = find(v);
        
        if (rootU != rootV) {
            // Union by rank
            if (rank[rootU] > rank[rootV])
                parent[rootV] = rootU;
            else if (rank[rootU] < rank[rootV])
                parent[rootU] = rootV;
            else {
                parent[rootV] = rootU;
                rank[rootU]++;
            }
        }
    }
};

// Kruskal’s algorithm to find the MST
void kruskalMST(int V, vector<Edge>& edges) {
    DisjointSet ds(V);
    vector<Edge> mst;

    // Sort edges by weight
    sort(edges.begin(), edges.end());

    for (const Edge& edge : edges) {
        int u = edge.u;
        int v = edge.v;

        // If u and v are not in the same set, add the edge to the MST
        if (ds.find(u) != ds.find(v)) {
            ds.unionSet(u, v);
            mst.push_back(edge);
        }
    }

    // Print the edges of the MST
    cout << "Edge \tWeight\n";
    for (const Edge& edge : mst) {
        cout << edge.u << " - " << edge.v << "\t" << edge.weight << endl;
    }
}

int main() {
    int V, E;
    cout << "Enter number of vertices: ";
    cin >> V;
    
    cout << "Enter number of edges: ";
    cin >> E;
    
    vector<Edge> edges(E);
    
    cout << "Enter the edges (u, v, weight) where u and v are vertices (0-based indexing):\n";
    for (int i = 0; i < E; ++i) {
        cin >> edges[i].u >> edges[i].v >> edges[i].weight;
    }
    
    // Calling Kruskal’s Algorithm to find the MST
    kruskalMST(V, edges);
    
    return 0;
}
