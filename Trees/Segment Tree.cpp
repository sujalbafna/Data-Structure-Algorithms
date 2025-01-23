#include <iostream>
#include <vector>
using namespace std;

// Segment Tree Class
class SegmentTree {
private:
    vector<int> tree; // Segment Tree array
    vector<int> arr;  // Original array
    int n;            // Size of the original array

    // Build the Segment Tree recursively
    void buildTree(int node, int start, int end) {
        if (start == end) {
            // Leaf node: store the array value
            tree[node] = arr[start];
        } else {
            int mid = (start + end) / 2;
            int leftChild = 2 * node + 1;
            int rightChild = 2 * node + 2;

            // Recursively build the left and right subtrees
            buildTree(leftChild, start, mid);
            buildTree(rightChild, mid + 1, end);

            // Internal node stores the sum of its children
            tree[node] = tree[leftChild] + tree[rightChild];
        }
    }

    // Range Sum Query
    int query(int node, int start, int end, int l, int r) {
        if (r < start || l > end) {
            // Range completely outside
            return 0;
        }
        if (l <= start && end <= r) {
            // Range completely inside
            return tree[node];
        }

        // Partial overlap
        int mid = (start + end) / 2;
        int leftSum = query(2 * node + 1, start, mid, l, r);
        int rightSum = query(2 * node + 2, mid + 1, end, l, r);

        return leftSum + rightSum;
    }

    // Update a specific index in the array
    void update(int node, int start, int end, int idx, int value) {
        if (start == end) {
            // Update the leaf node
            arr[idx] = value;
            tree[node] = value;
        } else {
            int mid = (start + end) / 2;
            int leftChild = 2 * node + 1;
            int rightChild = 2 * node + 2;

            // Update the left or right child based on the index
            if (idx <= mid) {
                update(leftChild, start, mid, idx, value);
            } else {
                update(rightChild, mid + 1, end, idx, value);
            }

            // Update the current node based on children
            tree[node] = tree[leftChild] + tree[rightChild];
        }
    }

public:
    // Constructor
    SegmentTree(vector<int>& input) {
        arr = input;
        n = input.size();
        tree.resize(4 * n, 0); // Allocate enough space for the tree
        buildTree(0, 0, n - 1); // Build the tree
    }

    // Public function to perform a range sum query
    int rangeSumQuery(int l, int r) {
        return query(0, 0, n - 1, l, r);
    }

    // Public function to update a specific index
    void updateValue(int idx, int value) {
        update(0, 0, n - 1, idx, value);
    }

    // Print the internal Segment Tree (for debugging)
    void printTree() {
        cout << "Segment Tree: ";
        for (int val : tree) {
            if (val != 0) cout << val << " ";
        }
        cout << endl;
    }
};

int main() {
    int n, choice, l, r, idx, value;
    cout << "Enter the size of the array: ";
    cin >> n;

    vector<int> input(n);
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++) {
        cin >> input[i];
    }

    SegmentTree st(input);

    do {
        cout << "\nSegment Tree Operations:\n";
        cout << "1. Range Sum Query\n";
        cout << "2. Update Value\n";
        cout << "3. Print Segment Tree (Debugging)\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter range (l r): ";
            cin >> l >> r;
            if (l < 0 || r >= n || l > r) {
                cout << "Invalid range!" << endl;
            } else {
                cout << "Range Sum [" << l << ", " << r << "] = " << st.rangeSumQuery(l, r) << endl;
            }
            break;

        case 2:
            cout << "Enter index and new value: ";
            cin >> idx >> value;
            if (idx < 0 || idx >= n) {
                cout << "Invalid index!" << endl;
            } else {
                st.updateValue(idx, value);
                cout << "Value updated at index " << idx << "." << endl;
            }
            break;

        case 3:
            st.printTree();
            break;

        case 4:
            cout << "Exiting program. Goodbye!" << endl;
            break;

        default:
            cout << "Invalid choice! Please try again." << endl;
        }
    } while (choice != 4);

    return 0;
}
