#include <iostream>
using namespace std;

class Deque {
private:
    int *arr;      // Array to store elements
    int front;     // Front index of the deque
    int rear;      // Rear index of the deque
    int size;      // Maximum size of the deque
    int count;     // Current number of elements in the deque

public:
    // Constructor to initialize the deque
    Deque(int capacity) {
        size = capacity;
        arr = new int[size];
        front = -1;
        rear = 0;
        count = 0;
    }

    ~Deque() {
        delete[] arr; // Free allocated memory
    }

    // Function to check if the deque is empty
    bool isEmpty() const {
        return count == 0;
    }

    // Function to check if the deque is full
    bool isFull() const {
        return count == size;
    }

    // Function to insert an element at the front
    void insertFront(int element) {
        if (isFull()) {
            cout << "Deque Overflow! Cannot insert at front." << endl;
            return;
        }
        if (isEmpty()) {
            front = rear = 0; // Initialize front and rear
        } else {
            front = (front - 1 + size) % size; // Circular decrement
        }
        arr[front] = element;
        count++;
        cout << "Inserted " << element << " at the front." << endl;
    }

    // Function to insert an element at the rear
    void insertRear(int element) {
        if (isFull()) {
            cout << "Deque Overflow! Cannot insert at rear." << endl;
            return;
        }
        if (isEmpty()) {
            front = rear = 0; // Initialize front and rear
        } else {
            rear = (rear + 1) % size; // Circular increment
        }
        arr[rear] = element;
        count++;
        cout << "Inserted " << element << " at the rear." << endl;
    }

    // Function to delete an element from the front
    void deleteFront() {
        if (isEmpty()) {
            cout << "Deque Underflow! Cannot delete from front." << endl;
            return;
        }
        cout << "Deleted " << arr[front] << " from the front." << endl;
        if (front == rear) {
            // Deque becomes empty
            front = rear = -1;
        } else {
            front = (front + 1) % size; // Circular increment
        }
        count--;
    }

    // Function to delete an element from the rear
    void deleteRear() {
        if (isEmpty()) {
            cout << "Deque Underflow! Cannot delete from rear." << endl;
            return;
        }
        cout << "Deleted " << arr[rear] << " from the rear." << endl;
        if (front == rear) {
            // Deque becomes empty
            front = rear = -1;
        } else {
            rear = (rear - 1 + size) % size; // Circular decrement
        }
        count--;
    }

    // Function to get the front element
    void getFront() const {
        if (isEmpty()) {
            cout << "Deque is empty! No front element." << endl;
            return;
        }
        cout << "Front element is: " << arr[front] << endl;
    }

    // Function to get the rear element
    void getRear() const {
        if (isEmpty()) {
            cout << "Deque is empty! No rear element." << endl;
            return;
        }
        cout << "Rear element is: " << arr[rear] << endl;
    }

    // Function to display the elements of the deque
    void display() const {
        if (isEmpty()) {
            cout << "Deque is empty!" << endl;
            return;
        }
        cout << "Deque elements (from front to rear): ";
        for (int i = 0; i < count; i++) {
            int index = (front + i) % size; // Calculate circular index
            cout << arr[index] << " ";
        }
        cout << endl;
    }
};

int main() {
    int capacity, choice, element;

    cout << "Enter the maximum size of the deque: ";
    cin >> capacity;

    Deque dq(capacity);

    do {
        cout << "\nDeque Operations Menu:\n";
        cout << "1. Insert Front\n";
        cout << "2. Insert Rear\n";
        cout << "3. Delete Front\n";
        cout << "4. Delete Rear\n";
        cout << "5. Get Front\n";
        cout << "6. Get Rear\n";
        cout << "7. Display\n";
        cout << "8. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter the element to insert at front: ";
            cin >> element;
            dq.insertFront(element);
            break;

        case 2:
            cout << "Enter the element to insert at rear: ";
            cin >> element;
            dq.insertRear(element);
            break;

        case 3:
            dq.deleteFront();
            break;

        case 4:
            dq.deleteRear();
            break;

        case 5:
            dq.getFront();
            break;

        case 6:
            dq.getRear();
            break;

        case 7:
            dq.display();
            break;

        case 8:
            cout << "Exiting program. Goodbye!" << endl;
            break;

        default:
            cout << "Invalid choice! Please try again." << endl;
        }
    } while (choice != 8);

    return 0;
}
