#include <iostream>
using namespace std;

// Node structure for the AVL Tree
struct Node {
    int data;
    Node* left;
    Node* right;
    int height;

    // Constructor
    Node(int value) {
        data = value;
        left = right = nullptr;
        height = 1; // New node is initially added at height 1
    }
};

// Class for AVL Tree
class AVLTree {
private:
    Node* root;

    // Get the height of the node
    int height(Node* node) {
        return node == nullptr ? 0 : node->height;
    }

    // Calculate the balance factor of a node
    int getBalanceFactor(Node* node) {
        return node == nullptr ? 0 : height(node->left) - height(node->right);
    }

    // Perform a right rotation
    Node* rightRotate(Node* y) {
        Node* x = y->left;
        Node* T2 = x->right;

        // Perform rotation
        x->right = y;
        y->left = T2;

        // Update heights
        y->height = max(height(y->left), height(y->right)) + 1;
        x->height = max(height(x->left), height(x->right)) + 1;

        return x; // Return new root
    }

    // Perform a left rotation
    Node* leftRotate(Node* x) {
        Node* y = x->right;
        Node* T2 = y->left;

        // Perform rotation
        y->left = x;
        x->right = T2;

        // Update heights
        x->height = max(height(x->left), height(x->right)) + 1;
        y->height = max(height(y->left), height(y->right)) + 1;

        return y; // Return new root
    }

    // Recursive function to insert a value into the AVL Tree
    Node* insertNode(Node* node, int value) {
        // Step 1: Perform normal BST insertion
        if (node == nullptr) {
            return new Node(value);
        }

        if (value < node->data) {
            node->left = insertNode(node->left, value);
        } else if (value > node->data) {
            node->right = insertNode(node->right, value);
        } else {
            return node; // No duplicates allowed
        }

        // Step 2: Update the height of the current node
        node->height = max(height(node->left), height(node->right)) + 1;

        // Step 3: Get the balance factor to check if the node is balanced
        int balance = getBalanceFactor(node);

        // Step 4: Perform rotations if the node is unbalanced

        // Left Left Case
        if (balance > 1 && value < node->left->data) {
            return rightRotate(node);
        }

        // Right Right Case
        if (balance < -1 && value > node->right->data) {
            return leftRotate(node);
        }

        // Left Right Case
        if (balance > 1 && value > node->left->data) {
            node->left = leftRotate(node->left);
            return rightRotate(node);
        }

        // Right Left Case
        if (balance < -1 && value < node->right->data) {
            node->right = rightRotate(node->right);
            return leftRotate(node);
        }

        return node; // Return the unchanged node pointer
    }

    // Recursive function to perform in-order traversal
    void inOrderTraversal(Node* node) {
        if (node == nullptr) return;
        inOrderTraversal(node->left);
        cout << node->data << " ";
        inOrderTraversal(node->right);
    }

    // Recursive function to perform pre-order traversal
    void preOrderTraversal(Node* node) {
        if (node == nullptr) return;
        cout << node->data << " ";
        preOrderTraversal(node->left);
        preOrderTraversal(node->right);
    }

    // Recursive function to perform post-order traversal
    void postOrderTraversal(Node* node) {
        if (node == nullptr) return;
        postOrderTraversal(node->left);
        postOrderTraversal(node->right);
        cout << node->data << " ";
    }

public:
    // Constructor
    AVLTree() {
        root = nullptr;
    }

    // Function to insert a value into the AVL Tree
    void insert(int value) {
        root = insertNode(root, value);
        cout << "Inserted " << value << " into the AVL Tree." << endl;
    }

    // Function to perform in-order traversal
    void inOrder() {
        cout << "In-order Traversal: ";
        inOrderTraversal(root);
        cout << endl;
    }

    // Function to perform pre-order traversal
    void preOrder() {
        cout << "Pre-order Traversal: ";
        preOrderTraversal(root);
        cout << endl;
    }

    // Function to perform post-order traversal
    void postOrder() {
        cout << "Post-order Traversal: ";
        postOrderTraversal(root);
        cout << endl;
    }
};

int main() {
    AVLTree avl;
    int choice, value;

    do {
        cout << "\nAVL Tree Operations Menu:\n";
        cout << "1. Insert\n";
        cout << "2. In-order Traversal\n";
        cout << "3. Pre-order Traversal\n";
        cout << "4. Post-order Traversal\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter the value to insert: ";
            cin >> value;
            avl.insert(value);
            break;

        case 2:
            avl.inOrder();
            break;

        case 3:
            avl.preOrder();
            break;

        case 4:
            avl.postOrder();
            break;

        case 5:
            cout << "Exiting program. Goodbye!" << endl;
            break;

        default:
            cout << "Invalid choice! Please try again." << endl;
        }
    } while (choice != 5);

    return 0;
}
