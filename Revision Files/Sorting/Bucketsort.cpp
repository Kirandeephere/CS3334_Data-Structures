#include <iostream>
using namespace std;

/**
 * Bucket Sort Implementation in C++
 * 
 * This code provides a basic implementation of the Bucket Sort algorithm to sort an array of integers.
 * Bucket Sort works by dividing the input array into several buckets, each of which is then sorted individually.
 * Finally, the sorted buckets are concatenated to obtain the sorted array.
 * 
 * The main function demonstrates the usage of the Bucket Sort algorithm by sorting an array of integers.
 */

// Insertion sort for individual buckets
void insertionSort(int arr[], int n) {
    // Loop through each element in the bucket
    for (int i = 1; i < n; i++) {
        int key = arr[i]; // The current element to be positioned
        int j = i - 1; // The previous element's index

        // Shift elements of arr[0..i-1], that are greater than key, to one position ahead of their current position
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key; // Place the key element after the last shifted element
    }
}

// Bucket Sort algorithm
void bucketSort(int arr[], int n) {
    // Find the maximum element to determine the range of values
    int maxVal = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] > maxVal) {
            maxVal = arr[i];
        }
    }

    // Create buckets
    const int numBuckets = 10; // Number of buckets to use
    int buckets[numBuckets][n]; // 2D array to hold the buckets

    // Initialize bucket sizes to 0
    int bucketSizes[numBuckets] = {0};

    // Distribute elements into buckets
    for (int i = 0; i < n; i++) {
        // Calculate the bucket index for the current element
        int bucketIndex = (numBuckets * arr[i]) / (maxVal + 1);
        // Add the element to the appropriate bucket
        buckets[bucketIndex][bucketSizes[bucketIndex]] = arr[i];
        bucketSizes[bucketIndex]++; // Increment the size of the current bucket
    }

    // Sort individual buckets using insertion sort
    for (int i = 0; i < numBuckets; i++) {
        insertionSort(buckets[i], bucketSizes[i]);
    }

    // Concatenate the sorted buckets back into the original array
    int index = 0;
    for (int i = 0; i < numBuckets; i++) {
        for (int j = 0; j < bucketSizes[i]; j++) {
            arr[index++] = buckets[i][j]; // Copy each element from the buckets back to the original array
        }
    }
}

// Utility function to print an array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " "; // Print each element followed by a space
    }
    cout << endl; // Print a new line at the end
}

// Driver code
int main() {
    int arr[] = {7, 2, 1, 6, 8, 5, 3, 4}; // Define and initialize the array to be sorted
    int size = sizeof(arr) / sizeof(arr[0]); // Calculate the size of the array

    cout << endl;
    cout << "Original array: ";
    printArray(arr, size); // Print the original array

    bucketSort(arr, size); // Sort the array using Bucket Sort

    cout << "Sorted array: ";
    printArray(arr, size); // Print the sorted array

    cout << endl;

    return 0; // End of the program
}

/*
Sample Output:
Original array: 7 2 1 6 8 5 3 4 
Sorted array: 1 2 3 4 5 6 7 8 
*/
