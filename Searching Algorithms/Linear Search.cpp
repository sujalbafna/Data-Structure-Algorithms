#include <iostream>
using namespace std;

// Function to perform Linear Search
int linearSearch(int arr[], int n, int target) {
    // Loop through all elements of the array
    for (int i = 0; i < n; i++) {
        // Check if the current element matches the target
        if (arr[i] == target) {
            return i; // Element found, return the index
        }
    }
    return -1; // Element not found, return -1
}

int main() {
    int n, target;

    // Input the number of elements in the array
    cout << "Enter the number of elements: ";
    cin >> n;

    int arr[n];

    // Input the elements of the array
    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // Input the target element to search for
    cout << "Enter the element to search for: ";
    cin >> target;

    // Perform Linear Search
    int index = linearSearch(arr, n, target);

    // Display the result
    if (index != -1) {
        cout << "Element found at index: " << index << endl;
    } else {
        cout << "Element not found!" << endl;
    }

    return 0;
}
