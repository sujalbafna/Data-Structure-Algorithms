#include <iostream>
#include <vector>
using namespace std;

// Function to perform Counting Sort
void countingSort(int arr[], int n) {
    // Find the maximum element in the array
    int maxElement = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > maxElement) {
            maxElement = arr[i];
        }
    }

    // Create a count array and initialize it to 0
    vector<int> count(maxElement + 1, 0);

    // Store the count of each element in the count array
    for (int i = 0; i < n; i++) {
        count[arr[i]]++;
    }

    // Modify the count array by adding the previous counts
    for (int i = 1; i <= maxElement; i++) {
        count[i] += count[i - 1];
    }

    // Create an output array to store the sorted elements
    vector<int> output(n);

    // Place the elements in the correct position in the output array
    for (int i = n - 1; i >= 0; i--) {
        output[count[arr[i]] - 1] = arr[i];
        count[arr[i]]--;
    }

    // Copy the sorted elements back into the original array
    for (int i = 0; i < n; i++) {
        arr[i] = output[i];
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

    // Perform Counting Sort
    countingSort(arr, n);

    // Display the array after sorting
    cout << "Array after sorting: ";
    displayArray(arr, n);

    return 0;
}
