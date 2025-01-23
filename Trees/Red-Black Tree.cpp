#include <iostream>
using namespace std;

// Node structure for the Red-Black Tree
enum Color { RED, BLACK };

struct Node {
    int data;
    bool color; // RED or BLACK
    Node* left;
    Node* right;
    Node* parent;

    // Constructor
    Node(int value) {
        data = value;
        color = RED; // New node is initially red
        left = right = parent = nullptr;
    }
};

// Class for Red-Black Tree
class RedBlackTree {
private:
    Node* root;
    Node* TNULL; // Sentinel node (null equivalent)

    // Initialize the sentinel node
    void initializeTNULL() {
        TNULL = new Node(0);
        TNULL->color = BLACK;
        TNULL->left = nullptr;
        TNULL->right = nullptr;
    }

    // Perform a left rotation
    void leftRotate(Node* x) {
        Node* y = x->right;
        x->right = y->left;

        if (y->left != TNULL) {
            y->left->parent = x;
        }

        y->parent = x->parent;

        if (x->parent == nullptr) {
            root = y;
        } else if (x == x->parent->left) {
            x->parent->left = y;
        } else {
            x->parent->right = y;
        }

        y->left = x;
        x->parent = y;
    }

    // Perform a right rotation
    void rightRotate(Node* x) {
        Node* y = x->left;
        x->left = y->right;

        if (y->right != TNULL) {
            y->right->parent = x;
        }

        y->parent = x->parent;

        if (x->parent == nullptr) {
            root = y;
        } else if (x == x->parent->right) {
            x->parent->right = y;
        } else {
            x->parent->left = y;
        }

        y->right = x;
        x->parent = y;
    }

    // Fix the tree after insertion
    void fixInsert(Node* k) {
        Node* uncle;
        while (k->parent != nullptr && k->parent->color == RED) {
            if (k->parent == k->parent->parent->left) {
                uncle = k->parent->parent->right;

                // Case 1: Uncle is RED
                if (uncle != nullptr && uncle->color == RED) {
                    k->parent->color = BLACK;
                    uncle->color = BLACK;
                    k->parent->parent->color = RED;
                    k = k->parent->parent;
                } else {
                    // Case 2: Uncle is BLACK and k is a right child
                    if (k == k->parent->right) {
                        k = k->parent;
                        leftRotate(k);
                    }

                    // Case 3: Uncle is BLACK and k is a left child
                    k->parent->color = BLACK;
                    k->parent->parent->color = RED;
                    rightRotate(k->parent->parent);
                }
            } else {
                uncle = k->parent->parent->left;

                // Mirror cases
                if (uncle != nullptr && uncle->color == RED) {
                    k->parent->color = BLACK;
                    uncle->color = BLACK;
                    k->parent->parent->color = RED;
                    k = k->parent->parent;
                } else {
                    if (k == k->parent->left) {
                        k = k->parent;
                        rightRotate(k);
                    }
                    k->parent->color = BLACK;
                    k->parent->parent->color = RED;
                    leftRotate(k->parent->parent);
                }
            }

            if (k == root) {
                break;
            }
        }
        root->color = BLACK;
    }

    // Recursive in-order traversal
    void inOrderTraversal(Node* node) {
        if (node == TNULL) return;
        inOrderTraversal(node->left);
        cout << node->data << " ";
        inOrderTraversal(node->right);
    }

public:
    // Constructor
    RedBlackTree() {
        initializeTNULL();
        root = TNULL;
    }

    // Insert a value into the Red-Black Tree
    void insert(int key) {
        Node* node = new Node(key);
        node->parent = nullptr;
        node->data = key;
        node->left = TNULL;
        node->right = TNULL;
        node->color = RED;

        Node* y = nullptr;
        Node* x = root;

        while (x != TNULL) {
            y = x;
            if (node->data < x->data) {
                x = x->left;
            } else {
                x = x->right;
            }
        }

        node->parent = y;

        if (y == nullptr) {
            root = node;
        } else if (node->data < y->data) {
            y->left = node;
        } else {
            y->right = node;
        }

        if (node->parent == nullptr) {
            node->color = BLACK;
            return;
        }

        if (node->parent->parent == nullptr) {
            return;
        }

        fixInsert(node);
        cout << "Inserted " << key << " into the Red-Black Tree." << endl;
    }

    // Perform in-order traversal
    void inOrder() {
        cout << "In-order Traversal: ";
        inOrderTraversal(root);
        cout << endl;
    }
};

int main() {
    RedBlackTree rbt;
    int choice, value;

    do {
        cout << "\nRed-Black Tree Operations Menu:\n";
        cout << "1. Insert\n";
        cout << "2. In-order Traversal\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter the value to insert: ";
            cin >> value;
            rbt.insert(value);
            break;

        case 2:
            rbt.inOrder();
            break;

        case 3:
            cout << "Exiting program. Goodbye!" << endl;
            break;

        default:
            cout << "Invalid choice! Please try again." << endl;
        }
    } while (choice != 3);

    return 0;
}
