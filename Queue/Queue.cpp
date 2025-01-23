#include <iostream>
using namespace std;

class Queue {
private:
    int arr[100];  // Array to store queue elements
    int front;     // Index of the front element
    int rear;      // Index of the rear element
    int maxSize;   // Maximum size of the queue

public:
    Queue(int size) {
        maxSize = size;
        front = -1;  // Initialize front
        rear = -1;   // Initialize rear
    }

    // Function to add an element to the queue (enqueue)
    void enqueue(int element) {
        if (rear == maxSize - 1) {
            cout << "Queue Overflow! Cannot enqueue " << element << endl;
            return;
        }
        if (front == -1) front = 0;  // Set front to 0 if the queue was empty
        arr[++rear] = element;
        cout << "Enqueued " << element << " to the queue." << endl;
    }

    // Function to remove an element from the queue (dequeue)
    void dequeue() {
        if (isEmpty()) {
            cout << "Queue Underflow! Queue is empty." << endl;
            return;
        }
        cout << "Dequeued " << arr[front] << " from the queue." << endl;
        if (front == rear) {
            // Reset the queue when it becomes empty
            front = rear = -1;
        } else {
            front++;
        }
    }

    // Function to view the front element of the queue (peek)
    void peek() const {
        if (isEmpty()) {
            cout << "Queue is empty! No front element." << endl;
            return;
        }
        cout << "Front element is: " << arr[front] << endl;
    }

    // Function to check if the queue is empty
    bool isEmpty() const {
        return front == -1 || front > rear;
    }

    // Function to display all elements in the queue
    void display() const {
        if (isEmpty()) {
            cout << "Queue is empty!" << endl;
            return;
        }
        cout << "Queue elements (from front to rear): ";
        for (int i = front; i <= rear; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    int size, choice, element;

    cout << "Enter the maximum size of the queue: ";
    cin >> size;

    Queue queue(size);

    do {
        cout << "\nQueue Operations Menu:\n";
        cout << "1. Enqueue\n";
        cout << "2. Dequeue\n";
        cout << "3. Peek\n";
        cout << "4. Check if Empty\n";
        cout << "5. Display Queue\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter the element to enqueue: ";
            cin >> element;
            queue.enqueue(element);
            break;

        case 2:
            queue.dequeue();
            break;

        case 3:
            queue.peek();
            break;

        case 4:
            if (queue.isEmpty())
                cout << "Queue is empty!" << endl;
            else
                cout << "Queue is not empty!" << endl;
            break;

        case 5:
            queue.display();
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
