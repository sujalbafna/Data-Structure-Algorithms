#include <iostream>
using namespace std;

class Array {
private:
    int arr[100];  // Array with a maximum size of 100
    int size;      // Current size of the array

public:
    Array() : size(0) {}

    // Function to insert an element at a specific position
    void insert(int element, int position) {
        if (position < 0 || position > size || size >= 100) {
            cout << "Invalid position or array is full!" << endl;
            return;
        }
        for (int i = size; i > position; i--) {
            arr[i] = arr[i - 1];
        }
        arr[position] = element;
        size++;
        cout << "Inserted " << element << " at position " << position << endl;
    }

    // Function to delete an element at a specific position
    void remove(int position) {
        if (position < 0 || position >= size) {
            cout << "Invalid position!" << endl;
            return;
        }
        cout << "Deleted " << arr[position] << " from position " << position << endl;
        for (int i = position; i < size - 1; i++) {
            arr[i] = arr[i + 1];
        }
        size--;
    }

    // Function to traverse and display the array
    void traverse() const {
        if (size == 0) {
            cout << "Array is empty!" << endl;
            return;
        }
        cout << "Array elements: ";
        for (int i = 0; i < size; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    // Function to search for an element in the array
    void search(int element) const {
        for (int i = 0; i < size; i++) {
            if (arr[i] == element) {
                cout << "Element " << element << " found at position " << i << endl;
                return;
            }
        }
        cout << "Element " << element << " not found in the array!" << endl;
    }
};

int main() {
    Array myArray;
    int choice, element, position;

    do {
        cout << "\nArray Operations Menu:\n";
        cout << "1. Insert Element\n";
        cout << "2. Delete Element\n";
        cout << "3. Traverse Array\n";
        cout << "4. Search Element\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter the element to insert: ";
            cin >> element;
            cout << "Enter the position to insert (0-based index): ";
            cin >> position;
            myArray.insert(element, position);
            break;

        case 2:
            cout << "Enter the position to delete (0-based index): ";
            cin >> position;
            myArray.remove(position);
            break;

        case 3:
            myArray.traverse();
            break;

        case 4:
            cout << "Enter the element to search: ";
            cin >> element;
            myArray.search(element);
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
