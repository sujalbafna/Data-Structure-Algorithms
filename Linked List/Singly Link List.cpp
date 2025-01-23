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

class SinglyLinkedList {
private:
    Node* head;

public:
    SinglyLinkedList() {
        head = nullptr;
    }

    // Insert a node at the beginning
    void insertAtBeginning(int value) {
        Node* newNode = new Node(value);
        newNode->next = head;
        head = newNode;
        cout << value << " inserted at the beginning.\n";
    }

    // Insert a node at the end
    void insertAtEnd(int value) {
        Node* newNode = new Node(value);
        if (head == nullptr) {
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
        cout << value << " inserted at the end.\n";
    }

    // Delete a node with a specific value
    void deleteNode(int value) {
        if (head == nullptr) {
            cout << "List is empty. Cannot delete " << value << ".\n";
            return;
        }

        if (head->data == value) {
            Node* temp = head;
            head = head->next;
            delete temp;
            cout << value << " deleted from the list.\n";
            return;
        }

        Node* temp = head;
        while (temp->next != nullptr && temp->next->data != value) {
            temp = temp->next;
        }

        if (temp->next == nullptr) {
            cout << value << " not found in the list.\n";
        } else {
            Node* nodeToDelete = temp->next;
            temp->next = temp->next->next;
            delete nodeToDelete;
            cout << value << " deleted from the list.\n";
        }
    }

    // Search for a value in the list
    bool search(int value) {
        Node* temp = head;
        while (temp != nullptr) {
            if (temp->data == value) {
                return true;
            }
            temp = temp->next;
        }
        return false;
    }

    // Display the linked list
    void display() {
        if (head == nullptr) {
            cout << "List is empty.\n";
            return;
        }

        Node* temp = head;
        cout << "Linked List: ";
        while (temp != nullptr) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }
};

int main() {
    SinglyLinkedList list;
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
