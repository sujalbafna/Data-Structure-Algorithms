#include <iostream>
using namespace std;

class CircularQueue {
private:
    int *arr;        // Dynamic array to store queue elements
    int front;       // Index of the front element
    int rear;        // Index of the rear element
    int maxSize;     // Maximum size of the queue
    int count;       // Current number of elements in the queue

public:
    // Constructor to initialize the queue
    CircularQueue(int size) {
        maxSize = size;
        arr = new int[maxSize];
        front = -1;
        rear = -1;
        count = 0;
    }

    ~CircularQueue() {
        delete[] arr; // Free the memory allocated for the queue
    }

    // Function to add an element to the queue (enqueue)
    void enqueue(int element) {
        if (isFull()) {
            cout << "Queue Overflow! Cannot enqueue " << element << endl;
            return;
        }
        if (isEmpty()) {
            front = rear = 0; // Initialize front and rear for the first element
        } else {
            rear = (rear + 1) % maxSize; // Move rear to the next position circularly
        }
        arr[rear] = element;
        count++;
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
            // Queue becomes empty
            front = rear = -1;
        } else {
            front = (front + 1) % maxSize; // Move front to the next position circularly
        }
        count--;
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
        return count == 0;
    }

    // Function to check if the queue is full
    bool isFull() const {
        return count == maxSize;
    }

    // Function to display all elements in the queue
    void display() const {
        if (isEmpty()) {
            cout << "Queue is empty!" << endl;
            return;
        }
        cout << "Queue elements (from front to rear): ";
        for (int i = 0; i < count; i++) {
            int index = (front + i) % maxSize; // Calculate the circular index
            cout << arr[index] << " ";
        }
        cout << endl;
    }
};

int main() {
    int size, choice, element;

    cout << "Enter the maximum size of the circular queue: ";
    cin >> size;

    CircularQueue queue(size);

    do {
        cout << "\nCircular Queue Operations Menu:\n";
        cout << "1. Enqueue\n";
        cout << "2. Dequeue\n";
        cout << "3. Peek\n";
        cout << "4. Check if Empty\n";
        cout << "5. Check if Full\n";
        cout << "6. Display Queue\n";
        cout << "7. Exit\n";
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
            if (queue.isFull())
                cout << "Queue is full!" << endl;
            else
                cout << "Queue is not full!" << endl;
            break;

        case 6:
            queue.display();
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
