#include <iostream>
using namespace std;

class Stack {
private:
    int arr[100];  // Array to store stack elements
    int top;       // Points to the top of the stack
    int maxSize;   // Maximum size of the stack

public:
    Stack(int size) {
        maxSize = size;
        top = -1; // Stack is initially empty
    }

    // Function to add an element to the stack (push)
    void push(int element) {
        if (top >= maxSize - 1) {
            cout << "Stack Overflow! Cannot push " << element << endl;
            return;
        }
        arr[++top] = element;
        cout << "Pushed " << element << " onto the stack." << endl;
    }

    // Function to remove the top element from the stack (pop)
    void pop() {
        if (top == -1) {
            cout << "Stack Underflow! Stack is empty." << endl;
            return;
        }
        cout << "Popped " << arr[top--] << " from the stack." << endl;
    }

    // Function to view the top element of the stack (peek)
    void peek() const {
        if (top == -1) {
            cout << "Stack is empty! No top element." << endl;
            return;
        }
        cout << "Top element is: " << arr[top] << endl;
    }

    // Function to check if the stack is empty
    bool isEmpty() const {
        return top == -1;
    }

    // Function to display all elements in the stack
    void display() const {
        if (top == -1) {
            cout << "Stack is empty!" << endl;
            return;
        }
        cout << "Stack elements (from top to bottom): ";
        for (int i = top; i >= 0; i--) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    int size, choice, element;

    cout << "Enter the maximum size of the stack: ";
    cin >> size;

    Stack stack(size);

    do {
        cout << "\nStack Operations Menu:\n";
        cout << "1. Push\n";
        cout << "2. Pop\n";
        cout << "3. Peek\n";
        cout << "4. Check if Empty\n";
        cout << "5. Display Stack\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter the element to push: ";
            cin >> element;
            stack.push(element);
            break;

        case 2:
            stack.pop();
            break;

        case 3:
            stack.peek();
            break;

        case 4:
            if (stack.isEmpty())
                cout << "Stack is empty!" << endl;
            else
                cout << "Stack is not empty!" << endl;
            break;

        case 5:
            stack.display();
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
