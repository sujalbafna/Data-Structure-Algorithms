#include <iostream>
using namespace std;

// Node structure for the binary tree
struct Node {
    int data;
    Node *left, *right;

    // Constructor for creating a new node
    Node(int value) {
        data = value;
        left = right = nullptr;
    }
};

// Class for the Binary Tree
class BinaryTree {
private:
    Node *root;

    // Recursive function for in-order traversal
    void inOrderTraversal(Node *node) {
        if (node == nullptr)
            return;
        inOrderTraversal(node->left);
        cout << node->data << " ";
        inOrderTraversal(node->right);
    }

    // Recursive function for pre-order traversal
    void preOrderTraversal(Node *node) {
        if (node == nullptr)
            return;
        cout << node->data << " ";
        preOrderTraversal(node->left);
        preOrderTraversal(node->right);
    }

    // Recursive function for post-order traversal
    void postOrderTraversal(Node *node) {
        if (node == nullptr)
            return;
        postOrderTraversal(node->left);
        postOrderTraversal(node->right);
        cout << node->data << " ";
    }

    // Recursive function to insert a new node in the binary tree
    Node *insertNode(Node *node, int value) {
        if (node == nullptr) {
            return new Node(value); // Create a new node if the current position is null
        }

        if (value < node->data) {
            // Insert into the left subtree
            node->left = insertNode(node->left, value);
        } else {
            // Insert into the right subtree
            node->right = insertNode(node->right, value);
        }
        return node;
    }

    // Recursive function to search for a value in the binary tree
    bool searchNode(Node *node, int value) {
        if (node == nullptr)
            return false;
        if (node->data == value)
            return true;
        if (value < node->data)
            return searchNode(node->left, value); // Search in the left subtree
        return searchNode(node->right, value);  // Search in the right subtree
    }

public:
    // Constructor to initialize the binary tree
    BinaryTree() {
        root = nullptr;
    }

    // Function to insert a value into the binary tree
    void insert(int value) {
        root = insertNode(root, value);
        cout << "Inserted " << value << " into the tree." << endl;
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

    // Function to search for a value in the binary tree
    void search(int value) {
        if (searchNode(root, value)) {
            cout << value << " is found in the tree." << endl;
        } else {
            cout << value << " is not found in the tree." << endl;
        }
    }
};

int main() {
    BinaryTree bt;
    int choice, value;

    do {
        cout << "\nBinary Tree Operations Menu:\n";
        cout << "1. Insert\n";
        cout << "2. In-order Traversal\n";
        cout << "3. Pre-order Traversal\n";
        cout << "4. Post-order Traversal\n";
        cout << "5. Search\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter the value to insert: ";
            cin >> value;
            bt.insert(value);
            break;

        case 2:
            bt.inOrder();
            break;

        case 3:
            bt.preOrder();
            break;

        case 4:
            bt.postOrder();
            break;

        case 5:
            cout << "Enter the value to search: ";
            cin >> value;
            bt.search(value);
            break;

        case 6:
            cout << "Exiting program. Goodbye!" << endl;
            break;

        default:
            cout << "Invalid choice! Please try again." << endl;
        }
    } while (choice != 6);

    return 0;
}
