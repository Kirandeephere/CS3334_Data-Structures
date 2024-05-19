#include <iostream>
#include <string>

using namespace std;

/**
 * Min Heap Implementation in C++
 * 
 * This code provides a simple implementation of a min heap data structure.
 * A min heap is a complete binary tree where the value of each parent node is less than or equal to the values of its children.
 * The MinHeap class supports basic operations like insertion, extraction of the minimum element, and printing the heap.
 */

#define MAX_HEAP_SIZE 100

// MinHeap class to implement a min heap data structure
class MinHeap {
private:
    int heap[MAX_HEAP_SIZE]; // Array to store the heap elements
    int size; // Current size of the heap

    // Helper function to swap two elements in the heap
    void swap(int& a, int& b) {
        int temp = a;
        a = b;
        b = temp;
    }

    // Helper function to heapify up (percolate up)
    void heapifyUp(int index) {
        while (index > 0 && heap[(index - 1) / 2] > heap[index]) {
            swap(heap[index], heap[(index - 1) / 2]);
            index = (index - 1) / 2;
        }
    }

    // Helper function to heapify down (percolate down)
    void heapifyDown(int index) {
        int smallest = index;
        int left = 2 * index + 1;
        int right = 2 * index + 2;

        if (left < size && heap[left] < heap[smallest]) {
            smallest = left;
        }

        if (right < size && heap[right] < heap[smallest]) {
            smallest = right;
        }

        if (smallest != index) {
            swap(heap[index], heap[smallest]);
            heapifyDown(smallest);
        }
    }

public:
    // Constructor to initialize an empty heap
    MinHeap() {
        size = 0;
    }

    // Function to check if the heap is empty
    bool isEmpty() {
        return size == 0;
    }

    // Function to check if the heap is full
    bool isFull() {
        return size == MAX_HEAP_SIZE;
    }

    // Function to insert a new element into the heap
    void insert(int value) {
        if (isFull()) {
            cout << "Heap is full. Cannot insert element." << endl;
            return;
        }
        heap[size++] = value;
        heapifyUp(size - 1);
    }

    // Function to extract the minimum element from the heap
    int extractMin() {
        if (isEmpty()) {
            cout << "Heap is empty. Cannot extract minimum element." << endl;
            return -1;
        }
        int minElement = heap[0];
        heap[0] = heap[--size];
        heapifyDown(0);
        return minElement;
    }

    // Function to get the minimum element from the heap without extracting it
    int getMin() {
        if (isEmpty()) {
            cout << "Heap is empty. No minimum element." << endl;
            return -1;
        }
        return heap[0];
    }

    // Helper function to print the heap in the desired format recursively
    void printHeapUtil(int index, string prefix, bool isLeft) {
        if (index >= size)
            return;

        cout << prefix;
        cout << (isLeft ? "├──" : "└──");
        cout << heap[index] << endl;

        // Recursively print the left and right children
        printHeapUtil(2 * index + 1, prefix + (isLeft ? "│   " : "    "), true);
        printHeapUtil(2 * index + 2, prefix + (isLeft ? "│   " : "    "), false);
    }

    // Function to print the heap in the desired format
    void printHeap() {
        printHeapUtil(0, "", true);
    }
};


int main() {
    MinHeap minHeap;

    cout << endl;

    // Insert elements into the heap
    minHeap.insert(10);
    minHeap.insert(7);
    minHeap.insert(15);
    minHeap.insert(3);
    minHeap.insert(8);

    // Print the heap
    minHeap.printHeap();

    // Print the minimum element
    cout << "Minimum element: " << minHeap.getMin() << endl;

    // Extract and print the minimum element
    cout << "Extracted minimum element: " << minHeap.extractMin() << endl;

    // Print the minimum element again
    cout << "Minimum element after extraction: " << minHeap.getMin() << endl;

    // Insert a new element
    minHeap.insert(5);

    // Print the minimum element
    cout << "Minimum element after insertion: " << minHeap.getMin() << endl;

    cout << endl;
    
    return 0;
}

/*
Sample Output:
├──3
│   ├──7
│   │   ├──10
│   │   └──8
│   └──15
Minimum element: 3
Extracted minimum element: 3
Minimum element after extraction: 7
Minimum element after insertion: 5
*/
