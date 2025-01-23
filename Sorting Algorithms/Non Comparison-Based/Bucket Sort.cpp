#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Function to perform Insertion Sort on a bucket
void insertionSort(vector<int>& bucket) {
    int n = bucket.size();
    for (int i = 1; i < n; i++) {
        int key = bucket[i];
        int j = i - 1;
        while (j >= 0 && bucket[j] > key) {
            bucket[j + 1] = bucket[j];
            j--;
        }
        bucket[j + 1] = key;
    }
}

// Function to perform Bucket Sort
void bucketSort(int arr[], int n) {
    // Find the maximum value in the array
    int maxElement = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > maxElement) {
            maxElement = arr[i];
        }
    }

    // Create 'n' empty buckets
    vector<vector<int>> buckets(n);

    // Put array elements in different buckets
    for (int i = 0; i < n; i++) {
        int index = arr[i] * n / (maxElement + 1);
        buckets[index].push_back(arr[i]);
    }

    // Sort each bucket and concatenate the results
    int index = 0;
    for (int i = 0; i < n; i++) {
        insertionSort(buckets[i]);
        for (int j = 0; j < buckets[i].size(); j++) {
            arr[index++] = buckets[i][j];
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

    // Perform Bucket Sort
    bucketSort(arr, n);

    // Display the array after sorting
    cout << "Array after sorting: ";
    displayArray(arr, n);

    return 0;
}
