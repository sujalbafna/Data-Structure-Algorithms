#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int value) {
        data = value;
        next = nullptr;
    }
};

class CircularLinkedList {
private:
    Node* head;

public:
    CircularLinkedList() {
        head = nullptr;
    }

    // Insert a node at the beginning
    void insertAtBeginning(int value) {
        Node* newNode = new Node(value);
        if (head == nullptr) {
            head = newNode;
            newNode->next = head;
        } else {
            Node* temp = head;
            while (temp->next != head) {
                temp = temp->next;
            }
            newNode->next = head;
            temp->next = newNode;
            head = newNode;
        }
        cout << value << " inserted at the beginning.\n";
    }

    // Insert a node at the end
    void insertAtEnd(int value) {
        Node* newNode = new Node(value);
        if (head == nullptr) {
            head = newNode;
            newNode->next = head;
        } else {
            Node* temp = head;
            while (temp->next != head) {
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->next = head;
        }
        cout << value << " inserted at the end.\n";
    }

    // Delete a node with a specific value
    void deleteNode(int value) {
        if (head == nullptr) {
            cout << "List is empty. Cannot delete " << value << ".\n";
            return;
        }

        Node* temp = head;
        Node* prev = nullptr;

        // If the node to delete is the head
        if (head->data == value) {
            while (temp->next != head) {
                temp = temp->next;
            }
            if (head->next == head) { // Only one node in the list
                delete head;
                head = nullptr;
            } else {
                temp->next = head->next;
                delete head;
                head = temp->next;
            }
            cout << value << " deleted from the list.\n";
            return;
        }

        // Traverse the list to find the node
        do {
            prev = temp;
            temp = temp->next;
        } while (temp != head && temp->data != value);

        if (temp == head) {
            cout << value << " not found in the list.\n";
        } else {
            prev->next = temp->next;
            delete temp;
            cout << value << " deleted from the list.\n";
        }
    }

    // Search for a value in the list
    bool search(int value) {
        if (head == nullptr) return false;

        Node* temp = head;
        do {
            if (temp->data == value) {
                return true;
            }
            temp = temp->next;
        } while (temp != head);

        return false;
    }

    // Display the list
    void display() {
        if (head == nullptr) {
            cout << "List is empty.\n";
            return;
        }

        Node* temp = head;
        cout << "Circular Linked List: ";
        do {
            cout << temp->data << " -> ";
            temp = temp->next;
        } while (temp != head);
        cout << "(head)\n";
    }
};

int main() {
    CircularLinkedList list;
    int choice, value;

    while (true) {
        cout << "\nMenu:\n";
        cout << "1. Insert at Beginning\n";
        cout << "2. Insert at End\n";
        cout << "3. Delete a Node\n";
        cout << "4. Search for a Value\n";
        cout << "5. Display List\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter value to insert at the beginning: ";
            cin >> value;
            list.insertAtBeginning(value);
            break;

        case 2:
            cout << "Enter value to insert at the end: ";
            cin >> value;
            list.insertAtEnd(value);
            break;

        case 3:
            cout << "Enter value to delete: ";
            cin >> value;
            list.deleteNode(value);
            break;

        case 4:
            cout << "Enter value to search: ";
            cin >> value;
            if (list.search(value)) {
                cout << value << " is present in the list.\n";
            } else {
                cout << value << " is not present in the list.\n";
            }
            break;

        case 5:
            list.display();
            break;

        case 6:
            cout << "Exiting program.\n";
            return 0;

        default:
            cout << "Invalid choice. Please try again.\n";
        }
    }
}
