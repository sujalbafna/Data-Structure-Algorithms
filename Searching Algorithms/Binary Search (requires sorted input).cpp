#include <iostream>
using namespace std;

// Function to perform Binary Search
int binarySearch(int arr[], int n, int target) {
    int left = 0, right = n - 1;
    
    while (left <= right) {
        int mid = left + (right - left) / 2;  // Find the middle index
        
        // If the target is found at the middle
        if (arr[mid] == target) {
            return mid; // Return the index
        }
        // If the target is smaller than the middle element, search the left half
        else if (arr[mid] > target) {
            right = mid - 1;
        }
        // If the target is larger than the middle element, search the right half
        else {
            left = mid + 1;
        }
    }
    
    return -1; // Target not found
}

int main() {
    int n, target;

    // Input the number of elements in the array
    cout << "Enter the number of elements: ";
    cin >> n;

    int arr[n];

    // Input the elements of the array (the array should be sorted)
    cout << "Enter the sorted elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // Input the target element to search for
    cout << "Enter the element to search for: ";
    cin >> target;

    // Perform Binary Search
    int index = binarySearch(arr, n, target);

    // Display the result
    if (index != -1) {
        cout << "Element found at index: " << index << endl;
    } else {
        cout << "Element not found!" << endl;
    }

    return 0;
}
