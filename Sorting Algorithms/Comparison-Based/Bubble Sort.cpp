#include <iostream>
using namespace std;

// Function to perform Bubble Sort
void bubbleSort(int arr[], int n) {
    bool swapped;
    
    // Outer loop for each pass through the array
    for (int i = 0; i < n - 1; i++) {
        swapped = false; // To check if any swap happened in this pass
        
        // Inner loop for comparing adjacent elements
        for (int j = 0; j < n - i - 1; j++) {
            // Swap if the element is greater than the next element
            if (arr[j] > arr[j + 1]) {
                // Swap elements
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swapped = true; // Set swapped to true if a swap happened
            }
        }
        
        // If no two elements were swapped in the inner loop, then the array is sorted
        if (!swapped) {
            break;
        }
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

    // Perform Bubble Sort
    bubbleSort(arr, n);

    // Display the array after sorting
    cout << "Array after sorting: ";
    displayArray(arr, n);

    return 0;
}
