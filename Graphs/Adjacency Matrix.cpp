#include <iostream>
#include <vector>
using namespace std;

// Graph Class using Adjacency Matrix
class Graph {
private:
    vector<vector<int>> adjMatrix; // 2D vector for adjacency matrix
    int vertices;                  // Number of vertices in the graph

public:
    // Constructor
    Graph(int v) {
        vertices = v;
        adjMatrix.resize(vertices, vector<int>(vertices, 0)); // Initialize matrix with 0's
    }

    // Add an edge between vertex u and vertex v (directed graph)
    void addEdge(int u, int v) {
        if (u >= 0 && u < vertices && v >= 0 && v < vertices) {
            adjMatrix[u][v] = 1; // Add directed edge u -> v
        } else {
            cout << "Invalid vertex!" << endl;
        }
    }

    // Add an edge between vertex u and vertex v (undirected graph)
    void addUndirectedEdge(int u, int v) {
        if (u >= 0 && u < vertices && v >= 0 && v < vertices) {
            adjMatrix[u][v] = 1; // Add edge u <-> v
            adjMatrix[v][u] = 1; // For undirected graph, set both directions
        } else {
            cout << "Invalid vertex!" << endl;
        }
    }

    // Display the adjacency matrix
    void display() {
        cout << "Adjacency Matrix:" << endl;
        for (int i = 0; i < vertices; i++) {
            for (int j = 0; j < vertices; j++) {
                cout << adjMatrix[i][j] << " ";
            }
            cout << endl;
        }
    }

    // Check if there is an edge between vertex u and vertex v
    bool isEdge(int u, int v) {
        if (u >= 0 && u < vertices && v >= 0 && v < vertices) {
            return adjMatrix[u][v] == 1;
        } else {
            cout << "Invalid vertex!" << endl;
            return false;
        }
    }
};

int main() {
    int vertices, choice, u, v;

    cout << "Enter the number of vertices in the graph: ";
    cin >> vertices;

    Graph graph(vertices);

    do {
        cout << "\nGraph Operations Menu:\n";
        cout << "1. Add Directed Edge\n";
        cout << "2. Add Undirected Edge\n";
        cout << "3. Display Adjacency Matrix\n";
        cout << "4. Check if there is an edge\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter the directed edge (u v): ";
            cin >> u >> v;
            graph.addEdge(u, v);
            break;

        case 2:
            cout << "Enter the undirected edge (u v): ";
            cin >> u >> v;
            graph.addUndirectedEdge(u, v);
            break;

        case 3:
            graph.display();
            break;

        case 4:
            cout << "Enter the vertices to check for an edge (u v): ";
            cin >> u >> v;
            if (graph.isEdge(u, v)) {
                cout << "There is an edge between vertex " << u << " and vertex " << v << "." << endl;
            } else {
                cout << "No edge between vertex " << u << " and vertex " << v << "." << endl;
            }
            break;

        case 5:
            cout << "Exiting program. Goodbye!" << endl;
            break;

        default:
            cout << "Invalid choice! Please try again.\n";
        }
    } while (choice != 5);

    return 0;
}
