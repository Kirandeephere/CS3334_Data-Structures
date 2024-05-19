#include <iostream>
using namespace std;

/**
 * QuickSort Implementation in C++
 * 
 * This code provides a basic implementation of the QuickSort algorithm to sort an array of integers.
 * QuickSort works by selecting a 'pivot' element from the array and partitioning the other elements into
 * two sub-arrays, according to whether they are less than or greater than the pivot. The sub-arrays are then sorted recursively.
 * 
 * The main function demonstrates the usage of the QuickSort algorithm by sorting an array of integers.
 */

// Partition the array and return the pivot index
int partition(int arr[], int low, int high) {
    int pivot = arr[high];  // Choose the rightmost element as the pivot
    int i = low - 1;        // Index of smaller element

    // Rearrange elements based on pivot
    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++; // Increment index of smaller element
            swap(arr[i], arr[j]); // Swap current element with the element at index i
        }
    }

    swap(arr[i + 1], arr[high]); // Swap the pivot element with the element at index i+1
    return i + 1; // Return the pivot index
}

// QuickSort algorithm
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        // Partition the array and get the pivot index
        int pivotIndex = partition(arr, low, high);

        // Recursively sort elements before and after partition
        quickSort(arr, low, pivotIndex - 1);  // Sort the left subarray
        quickSort(arr, pivotIndex + 1, high); // Sort the right subarray
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
    
    cout << endl;

    int arr[] = {7, 2, 1, 6, 8, 5, 3, 4}; // Define and initialize the array to be sorted
    int size = sizeof(arr) / sizeof(arr[0]); // Calculate the size of the array

    cout << "Original array: ";
    printArray(arr, size); // Print the original array

    quickSort(arr, 0, size - 1); // Sort the array using QuickSort

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
