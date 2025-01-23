#include <iostream>
using namespace std;

// Function to heapify a subtree rooted at index 'i' (with size 'n')
void heapify(int arr[], int n, int i) {
    int largest = i;  // Initialize largest as root
    int left = 2 * i + 1;  // Left child
    int right = 2 * i + 2; // Right child

    // If left child is larger than root
    if (left < n && arr[left] > arr[largest]) {
        largest = left;
    }

    // If right child is larger than largest so far
    if (right < n && arr[right] > arr[largest]) {
        largest = right;
    }

    // If largest is not root
    if (largest != i) {
        swap(arr[i], arr[largest]);  // Swap root with largest
        heapify(arr, n, largest);  // Recursively heapify the affected subtree
    }
}

// Function to implement Heap Sort
void heapSort(int arr[], int n) {
    // Build a max heap (rearrange the array)
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }

    // One by one extract elements from the heap
    for (int i = n - 1; i > 0; i--) {
        swap(arr[0], arr[i]);  // Move current root to the end
        heapify(arr, i, 0);     // Call heapify on the reduced heap
    }
}

// Function to display the array
void displayArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int n;

    // Input the number of elements in the array
    cout << "Enter the number of elements: ";
    cin >> n;

    int arr[n];

    // Input the elements of the array
    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // Display the array before sorting
    cout << "Array before sorting: ";
    displayArray(arr, n);

    // Perform Heap Sort
    heapSort(arr, n);

    // Display the array after sorting
    cout << "Array after sorting: ";
    displayArray(arr, n);

    return 0;
}
