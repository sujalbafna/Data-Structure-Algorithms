#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <cmath>
#include <climits>
#include <algorithm>

using namespace std;

// A structure to represent a node in the graph
struct Node {
    int x, y;      // Coordinates of the node
    double f, g, h; // f = g + h, g = cost to reach the node, h = heuristic estimate
    Node* parent;  // Parent node for path reconstruction

    Node(int x, int y) : x(x), y(y), f(0), g(0), h(0), parent(nullptr) {}

    // Comparison operator for priority queue (min-heap based on f)
    bool operator>(const Node& other) const {
        return f > other.f;
    }
};

// Heuristic function (Euclidean distance)
double heuristic(Node* a, Node* b) {
    return sqrt(pow(a->x - b->x, 2) + pow(a->y - b->y, 2));
}

// A* Algorithm to find the shortest path
vector<Node*> AStar(Node* start, Node* goal, vector<vector<int>>& grid) {
    priority_queue<Node*, vector<Node*>, greater<Node*>> openSet;
    unordered_map<int, unordered_map<int, Node*>> allNodes;
    unordered_map<int, unordered_map<int, bool>> closedSet;

    openSet.push(start);

    while (!openSet.empty()) {
        Node* current = openSet.top();
        openSet.pop();

        if (current == goal) {
            // Reconstruct the path
            vector<Node*> path;
            while (current != nullptr) {
                path.push_back(current);
                current = current->parent;
            }
            reverse(path.begin(), path.end());
            return path;
        }

        closedSet[current->x][current->y] = true;

        // Possible moves (4 directions)
        vector<pair<int, int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        for (auto& dir : directions) {
            int newX = current->x + dir.first;
            int newY = current->y + dir.second;

            if (newX >= 0 && newX < grid.size() && newY >= 0 && newY < grid[0].size() && grid[newX][newY] != 1) {
                // Skip nodes in the closed set
                if (closedSet[newX][newY]) continue;

                Node* neighbor = allNodes[newX][newY];
                if (!neighbor) {
                    neighbor = new Node(newX, newY);
                    allNodes[newX][newY] = neighbor;
                }

                double tentativeG = current->g + 1;  // Assuming cost between nodes is 1 (for grid movement)
                if (tentativeG < neighbor->g || !neighbor->parent) {
                    neighbor->g = tentativeG;
                    neighbor->h = heuristic(neighbor, goal);
                    neighbor->f = neighbor->g + neighbor->h;
                    neighbor->parent = current;
                    openSet.push(neighbor);
                }
            }
        }
    }

    return {};  // No path found
}

int main() {
    int rows, cols;
    cout << "Enter the number of rows and columns: ";
    cin >> rows >> cols;

    vector<vector<int>> grid(rows, vector<int>(cols));

    cout << "Enter the grid (0 for free space, 1 for obstacle):" << endl;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cin >> grid[i][j];
        }
    }

    int startX, startY, goalX, goalY;
    cout << "Enter the start node coordinates (x y): ";
    cin >> startX >> startY;

    cout << "Enter the goal node coordinates (x y): ";
    cin >> goalX >> goalY;

    Node* start = new Node(startX, startY);  // Start node
    Node* goal = new Node(goalX, goalY);    // Goal node

    vector<Node*> path = AStar(start, goal, grid);

    if (path.empty()) {
        cout << "No path found!" << endl;
    } else {
        cout << "Path found:" << endl;
        for (auto& node : path) {
            cout << "(" << node->x << ", " << node->y << ") ";
        }
        cout << endl;
    }

    return 0;
}
