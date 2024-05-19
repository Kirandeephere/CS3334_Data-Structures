
#include <iostream>
using namespace std;

/**
 * Priority Queue Implementation using Linked List in C++
 * 
 * This code provides a basic implementation of a priority queue using a linked list with the following functionalities:
 * - Enqueue elements with priority
 * - Dequeue elements
 * - Get the element with the highest priority (peek)
 * - Get the current size of the priority queue
 * - Display all elements in the priority queue
 * - Clear the priority queue
 * 
 * The main function demonstrates the usage of these functionalities.
 */

// Node class to represent elements in the priority queue
class Node {
public:
    int data;       // Data of the node
    int priority;   // Priority of the node
    Node* next;     // Pointer to the next node

    // Constructor to initialize node with data and priority
    Node(int value, int p) {
        data = value;
        priority = p;
        next = nullptr;
    }
};

// Priority Queue implementation
class PriorityQueue {
private:
    Node* front;    // Pointer to the front of the priority queue
    int count;      // Number of elements in the priority queue

public:
    // Constructor to initialize the priority queue
    PriorityQueue() {
        front = nullptr;
        count = 0;
    }

    // Function to check if the priority queue is empty
    bool isEmpty() {
        return front == nullptr;
    }

    // Function to insert an element with priority into the priority queue
    void enqueue(int value, int priority) {
        Node* newNode = new Node(value, priority);

        // If the priority queue is empty or the new element has higher priority than the front element
        if (isEmpty() || priority < front->priority) {
            newNode->next = front;
            front = newNode;
        } else {
            Node* current = front;

            // Traverse the list to find the appropriate position to insert the new node
            while (current->next != nullptr && current->next->priority <= priority) {
                current = current->next;
            }

            newNode->next = current->next;
            current->next = newNode;
        }
        count++; // Increment the count of elements
    }

    // Function to remove and return the element with the highest priority
    int dequeue() {
        if (isEmpty()) {
            cout << "Priority queue is empty. Cannot dequeue element." << endl;
            return -1;
        }

        Node* temp = front;
        int value = front->data;
        front = front->next;
        delete temp;
        count--; // Decrement the count of elements
        return value;
    }

    // Function to get the element with the highest priority without removing it
    int peek() {
        if (isEmpty()) {
            cout << "Priority queue is empty. No front element." << endl;
            return -1;
        }
        return front->data;
    }

    // Function to get the current size of the priority queue
    int size() {
        return count;
    }

    // Function to display all elements in the priority queue
    void display() {
        if (isEmpty()) {
            cout << "Priority queue is empty." << endl;
            return;
        }

        Node* current = front;
        cout << "Priority Queue elements: ";
        while (current != nullptr) {
            cout << "(" << current->data << ", " << current->priority << ") ";
            current = current->next;
        }
        cout << endl;
    }

    // Function to clear the priority queue
    void clear() {
        while (!isEmpty()) {
            dequeue();
        }
        cout << "Priority queue has been cleared." << endl;
    }
};

int main() {
    PriorityQueue pq;

    cout << endl;

    // Enqueue elements with priority
    pq.enqueue(10, 2);
    pq.enqueue(20, 1);
    pq.enqueue(30, 3);
    pq.enqueue(40, 2);
    pq.enqueue(50, 1);

    // Display all elements in the priority queue
    pq.display();

    // Dequeue and print elements with the highest priority
    cout << "Dequeued element: " << pq.dequeue() << endl;
    cout << "Dequeued element: " << pq.dequeue() << endl;

    // Print the element with the highest priority without removing it
    cout << "Front element: " << pq.peek() << endl;

    // Get and print the size of the priority queue
    cout << "Priority queue size: " << pq.size() << endl;

    // Clear the priority queue
    pq.clear();

    cout << endl;

    return 0;
}

/*
Sample Output:
Priority Queue elements: (20, 1) (50, 1) (10, 2) (40, 2) (30, 3) 
Dequeued element: 20
Dequeued element: 50
Front element: 10
Priority queue size: 3
Priority queue has been cleared.
*/
