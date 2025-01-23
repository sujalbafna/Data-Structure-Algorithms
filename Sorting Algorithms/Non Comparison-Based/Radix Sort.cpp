#include <iostream>
#include <vector>
using namespace std;

// Function to perform Counting Sort on the basis of the digit represented by exp
void countingSort(int arr[], int n, int exp) {
    vector<int> output(n); // Output array to store the sorted elements
    vector<int> count(10, 0); // Count array for digits 0 to 9

    // Store count of occurrences in count[]
    for (int i = 0; i < n; i++) {
        count[(arr[i] / exp) % 10]++;
    }

    // Change count[i] so that it now contains the actual position of this digit in output[]
    for (int i = 1; i < 10; i++) {
        count[i] += count[i - 1];
    }

    // Build the output array using count[]
    for (int i = n - 1; i >= 0; i--) {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }

    // Copy the sorted elements into the original array
    for (int i = 0; i < n; i++) {
        arr[i] = output[i];
    }
}

// Function to perform Radix Sort
void radixSort(int arr[], int n) {
    // Find the maximum number to know the number of digits
    int maxElement = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > maxElement) {
            maxElement = arr[i];
        }
    }

    // Perform counting sort for every digit (exp is 10^i where i is the current digit index)
    for (int exp = 1; maxElement / exp > 0; exp *= 10) {
        countingSort(arr, n, exp);
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

    // Perform Radix Sort
    radixSort(arr, n);

    // Display the array after sorting
    cout << "Array after sorting: ";
    displayArray(arr, n);

    return 0;
}
