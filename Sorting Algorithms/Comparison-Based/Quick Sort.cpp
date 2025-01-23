#include <iostream>
using namespace std;

// Function to partition the array into two subarrays based on the pivot
int partition(int arr[], int low, int high) {
    int pivot = arr[high];  // Choosing the last element as pivot
    int i = low - 1;  // Index of smaller element

    // Traverse through the array, comparing each element with the pivot
    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            // Swap if the current element is smaller than or equal to the pivot
            i++;
            swap(arr[i], arr[j]);
        }
    }

    // Swap the pivot element with the element at i + 1 to place the pivot in its correct position
    swap(arr[i + 1], arr[high]);

    return i + 1;  // Return the index of the pivot element
}

// Function to implement Quick Sort
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        // Partition the array and get the pivot index
        int pivotIndex = partition(arr, low, high);

        // Recursively sort the two subarrays
        quickSort(arr, low, pivotIndex - 1);
        quickSort(arr, pivotIndex + 1, high);
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

    // Perform Quick Sort
    quickSort(arr, 0, n - 1);

    // Display the array after sorting
    cout << "Array after sorting: ";
    displayArray(arr, n);

    return 0;
}
