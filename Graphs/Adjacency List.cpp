#include <iostream>
#include <vector>
#include <list>
using namespace std;

// Graph Class using Adjacency List
class Graph {
private:
    vector<list<int>> adjList; // Vector of lists to represent adjacency list
    int vertices;              // Number of vertices in the graph

public:
    // Constructor
    Graph(int v) {
        vertices = v;
        adjList.resize(vertices); // Resize adjacency list to the number of vertices
    }

    // Add a directed edge between vertex u and vertex v
    void addEdge(int u, int v) {
        if (u >= 0 && u < vertices && v >= 0 && v < vertices) {
            adjList[u].push_back(v); // Add directed edge u -> v
        } else {
            cout << "Invalid vertex!" << endl;
        }
    }

    // Add an undirected edge between vertex u and vertex v
    void addUndirectedEdge(int u, int v) {
        if (u >= 0 && u < vertices && v >= 0 && v < vertices) {
            adjList[u].push_back(v); // Add edge u <-> v
            adjList[v].push_back(u); // For undirected graph, add reverse edge v <-> u
        } else {
            cout << "Invalid vertex!" << endl;
        }
    }

    // Display the adjacency list
    void display() {
        cout << "Adjacency List:" << endl;
        for (int i = 0; i < vertices; i++) {
            cout << "Vertex " << i << ": ";
            for (int v : adjList[i]) {
                cout << v << " ";
            }
            cout << endl;
        }
    }

    // Check if there is an edge between vertex u and vertex v
    bool isEdge(int u, int v) {
        if (u >= 0 && u < vertices && v >= 0 && v < vertices) {
            for (int adj : adjList[u]) {
                if (adj == v) {
                    return true;
                }
            }
            return false; // No edge found
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
        cout << "3. Display Adjacency List\n";
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
