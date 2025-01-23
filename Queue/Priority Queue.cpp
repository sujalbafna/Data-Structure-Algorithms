#include <iostream>
using namespace std;

// Struct to represent a priority queue element
struct Element {
    int data;      // The value of the element
    int priority;  // Priority of the element
};

class PriorityQueue {
private:
    Element arr[100];  // Array to store elements
    int size;          // Current size of the priority queue

public:
    PriorityQueue() {
        size = 0;  // Initialize size to 0
    }

    // Function to add an element with a given priority
    void enqueue(int data, int priority) {
        if (size == 100) {
            cout << "Priority Queue Overflow! Cannot enqueue " << data << endl;
            return;
        }

        // Insert the new element at the end
        arr[size].data = data;
        arr[size].priority = priority;
        size++;

        // Sort the queue based on priority (higher priority first)
        for (int i = size - 1; i > 0; i--) {
            if (arr[i].priority > arr[i - 1].priority) {
                // Swap elements to maintain priority order
                Element temp = arr[i];
                arr[i] = arr[i - 1];
                arr[i - 1] = temp;
            } else {
                break;
            }
        }

        cout << "Enqueued " << data << " with priority " << priority << endl;
    }

    // Function to remove the element with the highest priority
    void dequeue() {
        if (isEmpty()) {
            cout << "Priority Queue Underflow! Queue is empty." << endl;
            return;
        }

        cout << "Dequeued " << arr[0].data << " with priority " << arr[0].priority << endl;

        // Shift all elements to the left
        for (int i = 1; i < size; i++) {
            arr[i - 1] = arr[i];
        }
        size--;
    }

    // Function to view the element with the highest priority
    void peek() const {
        if (isEmpty()) {
            cout << "Priority Queue is empty! No front element." << endl;
            return;
        }

        cout << "Front element is: " << arr[0].data << " with priority " << arr[0].priority << endl;
    }

    // Function to check if the priority queue is empty
    bool isEmpty() const {
        return size == 0;
    }

    // Function to display all elements in the priority queue
    void display() const {
        if (isEmpty()) {
            cout << "Priority Queue is empty!" << endl;
            return;
        }

        cout << "Priority Queue elements (data:priority): ";
        for (int i = 0; i < size; i++) {
            cout << arr[i].data << ":" << arr[i].priority << " ";
        }
        cout << endl;
    }
};

int main() {
    PriorityQueue pq;

    int choice, data, priority;

    do {
        cout << "\nPriority Queue Operations Menu:\n";
        cout << "1. Enqueue (Insert)\n";
        cout << "2. Dequeue (Remove)\n";
        cout << "3. Peek (View Front)\n";
        cout << "4. Check if Empty\n";
        cout << "5. Display Queue\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter the element to enqueue: ";
            cin >> data;
            cout << "Enter the priority of the element: ";
            cin >> priority;
            pq.enqueue(data, priority);
            break;

        case 2:
            pq.dequeue();
            break;

        case 3:
            pq.peek();
            break;

        case 4:
            if (pq.isEmpty())
                cout << "Priority Queue is empty!" << endl;
            else
                cout << "Priority Queue is not empty!" << endl;
            break;

        case 5:
            pq.display();
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
