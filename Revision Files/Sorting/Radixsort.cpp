#include <iostream>
using namespace std;

/**
 * Radix Sort Implementation in C++
 * 
 * This code provides an implementation of the Radix Sort algorithm to sort an array of integers.
 * Radix Sort works by sorting the array digit by digit starting from the least significant digit to the most significant digit.
 * It uses a stable counting sort as a subroutine to sort the digits.
 * 
 * The main function demonstrates the usage of the Radix Sort algorithm by sorting an array of integers.
 */

// Utility function to get the maximum value in an array
int getMax(int arr[], int n) {
    int maxVal = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > maxVal) {
            maxVal = arr[i];
        }
    }
    return maxVal;
}

// Utility function to print an array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " "; // Print each element followed by a space
    }
    cout << endl; // Print a new line at the end
}

// Counting sort for a specific digit represented by exp (10^i where i is the current digit number)
void countingSort(int arr[], int n, int exp) {
    int output[n]; // Output array to store the sorted order
    int count[10] = {0};   // Count array to store count of occurrences of digits (0 to 9)

    // Store count of occurrences of digits
    for (int i = 0; i < n; i++) {
        int index = (arr[i] / exp) % 10;
        count[index]++;
    }

    // Change count[i] so that count[i] now contains the actual position of the digit in the output array
    for (int i = 1; i < 10; i++) {
        count[i] += count[i - 1];
    }

    // Build the output array using the count array
    for (int i = n - 1; i >= 0; i--) {
        int index = (arr[i] / exp) % 10;
        output[count[index] - 1] = arr[i];
        count[index]--;
    }

    // Copy the sorted elements into the original array
    for (int i = 0; i < n; i++) {
        arr[i] = output[i];
    }
}

// Radix Sort algorithm
void radixSort(int arr[], int n) {
    // Find the maximum number to determine the number of digits
    int maxVal = getMax(arr, n);

    // Do counting sort for every digit. Note that exp is 10^i where i is the current digit number
    for (int exp = 1; maxVal / exp > 0; exp *= 10) {
        countingSort(arr, n, exp);
        // Print the array after sorting by each digit place
        cout << "After sorting by digit place " << exp << ": ";
        printArray(arr, n);
    }
}

// Driver code
int main() {

    cout << endl;
    
    int arr[] = {170, 45, 75, 90, 802, 24, 2, 66}; // Define and initialize the array to be sorted
    int size = sizeof(arr) / sizeof(arr[0]); // Calculate the size of the array

    cout << "Original array: ";
    printArray(arr, size); // Print the original array

    radixSort(arr, size); // Sort the array using Radix Sort

    cout << "Sorted array: ";
    printArray(arr, size); // Print the sorted array

    cout << endl;

    return 0; // End of the program
}

/*
Sample Output:
Original array: 170 45 75 90 802 24 2 66 
After sorting by digit place 1: 170 90 802 2 24 45 75 66 
After sorting by digit place 10: 802 2 24 45 66 170 75 90 
After sorting by digit place 100: 2 24 45 66 75 90 170 802 
Sorted array: 2 24 45 66 75 90 170 802 
*/
