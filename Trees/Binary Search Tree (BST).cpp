#include <iostream>
using namespace std;

// Node structure for the Binary Search Tree
struct Node {
    int data;
    Node *left, *right;

    // Constructor for creating a new node
    Node(int value) {
        data = value;
        left = right = nullptr;
    }
};

// Class for the Binary Search Tree
class BST {
private:
    Node *root;

    // Recursive function to insert a node into the BST
    Node* insertNode(Node *node, int value) {
        if (node == nullptr) {
            return new Node(value); // Create a new node if the current position is null
        }

        if (value < node->data) {
            node->left = insertNode(node->left, value); // Insert into the left subtree
        } else if (value > node->data) {
            node->right = insertNode(node->right, value); // Insert into the right subtree
        }

        return node;
    }

    // Recursive function for in-order traversal
    void inOrderTraversal(Node *node) {
        if (node == nullptr) return;
        inOrderTraversal(node->left);
        cout << node->data << " ";
        inOrderTraversal(node->right);
    }

    // Recursive function for pre-order traversal
    void preOrderTraversal(Node *node) {
        if (node == nullptr) return;
        cout << node->data << " ";
        preOrderTraversal(node->left);
        preOrderTraversal(node->right);
    }

    // Recursive function for post-order traversal
    void postOrderTraversal(Node *node) {
        if (node == nullptr) return;
        postOrderTraversal(node->left);
        postOrderTraversal(node->right);
        cout << node->data << " ";
    }

    // Recursive function to search for a value in the BST
    bool searchNode(Node *node, int value) {
        if (node == nullptr) return false; // Value not found
        if (node->data == value) return true; // Value found
        if (value < node->data) return searchNode(node->left, value); // Search left subtree
        return searchNode(node->right, value); // Search right subtree
    }

    // Recursive function to find the minimum value in the BST
    Node* findMin(Node *node) {
        while (node->left != nullptr) {
            node = node->left;
        }
        return node;
    }

    // Recursive function to delete a node from the BST
    Node* deleteNode(Node *node, int value) {
        if (node == nullptr) return node;

        if (value < node->data) {
            node->left = deleteNode(node->left, value); // Delete from the left subtree
        } else if (value > node->data) {
            node->right = deleteNode(node->right, value); // Delete from the right subtree
        } else {
            // Node with the value found
            if (node->left == nullptr) {
                Node *temp = node->right;
                delete node;
                return temp;
            } else if (node->right == nullptr) {
                Node *temp = node->left;
                delete node;
                return temp;
            }

            // Node with two children: Get the in-order successor (minimum value in the right subtree)
            Node *temp = findMin(node->right);
            node->data = temp->data; // Replace data
            node->right = deleteNode(node->right, temp->data); // Delete the in-order successor
        }
        return node;
    }

public:
    // Constructor to initialize the BST
    BST() {
        root = nullptr;
    }

    // Function to insert a value into the BST
    void insert(int value) {
        root = insertNode(root, value);
        cout << "Inserted " << value << " into the BST." << endl;
    }

    // Function to delete a value from the BST
    void deleteValue(int value) {
        root = deleteNode(root, value);
        cout << "Deleted " << value << " from the BST (if it existed)." << endl;
    }

    // Function to search for a value in the BST
    void search(int value) {
        if (searchNode(root, value)) {
            cout << value << " is found in the BST." << endl;
        } else {
            cout << value << " is not found in the BST." << endl;
        }
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
    BST bst;
    int choice, value;

    do {
        cout << "\nBinary Search Tree (BST) Operations Menu:\n";
        cout << "1. Insert\n";
        cout << "2. Delete\n";
        cout << "3. Search\n";
        cout << "4. In-order Traversal\n";
        cout << "5. Pre-order Traversal\n";
        cout << "6. Post-order Traversal\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter the value to insert: ";
            cin >> value;
            bst.insert(value);
            break;

        case 2:
            cout << "Enter the value to delete: ";
            cin >> value;
            bst.deleteValue(value);
            break;

        case 3:
            cout << "Enter the value to search: ";
            cin >> value;
            bst.search(value);
            break;

        case 4:
            bst.inOrder();
            break;

        case 5:
            bst.preOrder();
            break;

        case 6:
            bst.postOrder();
            break;

        case 7:
            cout << "Exiting program. Goodbye!" << endl;
            break;

        default:
            cout << "Invalid choice! Please try again." << endl;
        }
    } while (choice != 7);

    return 0;
}
