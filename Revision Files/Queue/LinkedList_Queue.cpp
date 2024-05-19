#include <iostream>

using namespace std;

/**
 * Queue Implementation using Linked List in C++
 * 
 * This code provides a basic implementation of a queue using a linked list with the following functionalities:
 * - Enqueue elements
 * - Dequeue elements
 * - Get the front element
 * - Get the rear element
 * - Check if the queue is empty
 * - Get the size of the queue
 * - Display all elements in the queue
 * - Clear the queue
 * 
 * The main function demonstrates the usage of these functionalities.
 */

class Node {
public:
    int data;
    Node* next;

    Node(int value) {
        data = value;
        next = nullptr;
    }
};

class Queue {
private:
    Node* front;   // Pointer to the front element
    Node* rear;    // Pointer to the rear element
    int count;     // Number of elements in the queue

public:
    Queue() {
        front = nullptr;
        rear = nullptr;
        count = 0;
    }

    // Function to check if the queue is empty
    bool isEmpty() {
        return front == nullptr;
    }

    // Function to add an element to the queue
    void enqueue(int value) {
        Node* newNode = new Node(value);

        if (isEmpty()) {
            front = newNode;
            rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
        count++;
    }

    // Function to remove an element from the queue
    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty. Cannot dequeue element." << endl;
            return;
        }

        Node* temp = front;
        front = front->next;

        if (front == nullptr) {
            rear = nullptr;
        }

        delete temp;
        count--;
    }

    // Function to get the front element of the queue
    int getFront() {
        if (isEmpty()) {
            cout << "Queue is empty. No front element." << endl;
            return -1;
        }
        return front->data;
    }

    // Function to get the rear element of the queue
    int getRear() {
        if (isEmpty()) {
            cout << "Queue is empty. No rear element." << endl;
            return -1;
        }
        return rear->data;
    }

    // Function to get the current size of the queue
    int size() {
        return count;
    }

    // Function to display all elements in the queue
    void display() {
        if (isEmpty()) {
            cout << "Queue is empty." << endl;
            return;
        }

        Node* current = front;
        cout << "Queue elements: [ ";
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << "]" << endl;
    }

    // Function to clear the queue
    void clear() {
        while (!isEmpty()) {
            dequeue();
        }
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
