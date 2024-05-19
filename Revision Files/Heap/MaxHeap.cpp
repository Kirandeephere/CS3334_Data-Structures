#include <iostream>
#include <string>

using namespace std;

/**
 * Max Heap Implementation in C++
 * 
 * This code provides a simple implementation of a max heap data structure.
 * A max heap is a complete binary tree where the value of each parent node is greater than or equal to the values of its children.
 * The MaxHeap class supports basic operations like insertion, extraction of the maximum element, and printing the heap.
 */

#define MAX_HEAP_SIZE 100

// MaxHeap class to implement a max heap data structure
class MaxHeap {
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
        while (index > 0 && heap[(index - 1) / 2] < heap[index]) {
            swap(heap[index], heap[(index - 1) / 2]);
            index = (index - 1) / 2;
        }
    }

    // Helper function to heapify down (percolate down)
    void heapifyDown(int index) {
        int largest = index;
        int left = 2 * index + 1;
        int right = 2 * index + 2;

        if (left < size && heap[left] > heap[largest]) {
            largest = left;
        }

        if (right < size && heap[right] > heap[largest]) {
            largest = right;
        }

        if (largest != index) {
            swap(heap[index], heap[largest]);
            heapifyDown(largest);
        }
    }

public:
    // Constructor to initialize an empty heap
    MaxHeap() {
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

    // Function to extract the maximum element from the heap
    int extractMax() {
        if (isEmpty()) {
            cout << "Heap is empty. Cannot extract maximum element." << endl;
            return -1;
        }
        int maxElement = heap[0];
        heap[0] = heap[--size];
        heapifyDown(0);
        return maxElement;
    }

    // Function to get the maximum element from the heap without extracting it
    int getMax() {
        if (isEmpty()) {
            cout << "Heap is empty. No maximum element." << endl;
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
    MaxHeap maxHeap;
    
    cout << endl;

    // Insert elements into the heap
    maxHeap.insert(10);
    maxHeap.insert(7);
    maxHeap.insert(15);
    maxHeap.insert(3);
    maxHeap.insert(8);

    // Print the heap
    maxHeap.printHeap();

    // Print the maximum element
    cout << "Maximum element: " << maxHeap.getMax() << endl;

    // Extract and print the maximum element
    cout << "Extracted maximum element: " << maxHeap.extractMax() << endl;

    // Print the maximum element again
    cout << "Maximum element after extraction: " << maxHeap.getMax() << endl;

    // Insert a new element
    maxHeap.insert(20);

    // Print the maximum element
    cout << "Maximum element after insertion: " << maxHeap.getMax() << endl;

    cout << endl;

    return 0;
}

/*
Sample Output:
├──15
│   ├──8
│   │   ├──3
│   │   └──7
│   └──10
Maximum element: 15
Extracted maximum element: 15
Maximum element after extraction: 10
Maximum element after insertion: 20
*/
