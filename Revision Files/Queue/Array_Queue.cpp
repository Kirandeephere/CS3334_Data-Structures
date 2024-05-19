#include <iostream>
#define MAX_SIZE 100

using namespace std;

/**
 * Queue Implementation using Array in C++
 * 
 * This code provides a basic implementation of a circular queue using an array with the following functionalities:
 * - Enqueue elements
 * - Dequeue elements
 * - Get the front element
 * - Get the rear element
 * - Check if the queue is empty
 * - Check if the queue is full
 * - Get the size of the queue
 * - Display all elements in the queue
 * - Clear the queue
 * 
 * The main function demonstrates the usage of these functionalities.
 */

class Queue {
private:
    int front;              // Index of the front element
    int rear;               // Index of the rear element
    int arr[MAX_SIZE];      // Array to store the queue elements

public:
    Queue() {
        front = -1;         // Initialize front index
        rear = -1;          // Initialize rear index
    }

    // Function to check if the queue is empty
    bool isEmpty() {
        return (front == -1 && rear == -1);     // Queue is empty if both front and rear are -1
    }

    // Function to check if the queue is full
    bool isFull() {
        return (rear + 1) % MAX_SIZE == front;  // Queue is full if the next index of rear is equal to front
    }

    // Function to add an element to the queue
    void enqueue(int data) {
        if (isFull()) {
            cout << "Queue is full. Cannot enqueue element." << endl;
            return;
        } else if (isEmpty()) {
            front = 0;                          // If the queue is empty, set front to 0
            rear = 0;                           // If the queue is empty, set rear to 0
        } else {
            rear = (rear + 1) % MAX_SIZE;       // Move rear circularly
        }
        arr[rear] = data;                       // Insert the element at the rear
    }

    // Function to remove an element from the queue
    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty. Cannot dequeue element." << endl;
            return;
        } else if (front == rear) {
            front = -1;                         // If there is only one element in the queue, reset front and rear to -1
            rear = -1;
        } else {
            front = (front + 1) % MAX_SIZE;     // Move front circularly
        }
    }

    // Function to get the front element of the queue
    int getFront() {
        if (isEmpty()) {
            cout << "Queue is empty. No front element." << endl;
            return -1;
        }
        return arr[front];                      // Return the element at the front
    }

    // Function to get the rear element of the queue
    int getRear() {
        if (isEmpty()) {
            cout << "Queue is empty. No rear element." << endl;
            return -1;
        }
        return arr[rear];                       // Return the element at the rear
    }

    // Function to get the current size of the queue
    int size() {
        if (isEmpty()) {
            return 0;                           // Return 0 if the queue is empty
        }
        if (rear >= front) {
            return rear - front + 1;            // If rear is ahead of front, return the difference
        }
        return MAX_SIZE - front + rear + 1;     // If front has wrapped around, calculate the size accordingly
    }

    // Function to display all elements in the queue
    void display() {
        if (isEmpty()) {
            cout << "Queue is empty." << endl;
            return;
        }
        int count = size();
        int index = front;
        cout << "Queue elements: [ ";
        for (int i = 0; i < count; i++) {
            cout << arr[index] << " ";
            index = (index + 1) % MAX_SIZE;     // Move index circularly
        }
        cout << "]" << endl;
    }

    // Function to clear the queue
    void clear() {
        front = -1;                             // Reset front index
        rear = -1;                              // Reset rear index
        cout << "Queue has been cleared." << endl;
    }
};

int main() {
    Queue queue;

    cout << endl;

    // Enqueue elements
    queue.enqueue(10);
    queue.enqueue(20);
    queue.enqueue(30);
    queue.enqueue(40);
    queue.enqueue(50);

    // Display queue elements
    queue.display();

    // Print front and rear
    cout << "Front element: " << queue.getFront() << endl;
    cout << "Rear element: " << queue.getRear() << endl;

    // Dequeue elements
    queue.dequeue();
    queue.dequeue();

    // Display queue elements after dequeue
    queue.display();

    // Print front and rear after dequeue
    cout << "Front element: " << queue.getFront() << endl;
    cout << "Rear element: " << queue.getRear() << endl;

    // Get and print the size of the queue
    cout << "Queue size: " << queue.size() << endl;

    // Clear the queue
    queue.clear();

    // Display queue elements after clearing
    queue.display();

    cout << endl;
    
    return 0;
}

/*
Sample Output:
Queue elements: [ 10 20 30 40 50 ]
Front element: 10
Rear element: 50
Queue elements: [ 30 40 50 ]
Front element: 30
Rear element: 50
Queue size: 3
Queue has been cleared.
Queue is empty.
*/
