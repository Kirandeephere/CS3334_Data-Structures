#include <iostream>

using namespace std;

/**
 * Stack Implementation Using Linked List in C++
 * 
 * This code provides a simple implementation of a stack data structure using a linked list.
 * The Stack class supports basic operations like push, pop, isEmpty, getTop, getSize, printStack, and clear.
 * 
 * The main function demonstrates the usage of the Stack class by performing various operations on a stack of integers.
 */

// Node class to represent a node in the linked list
class Node {
public:
    int data;   // Data stored in the node
    Node* next; // Pointer to the next node

    // Constructor to initialize a node with a given value
    Node(int value) {
        data = value;
        next = nullptr; // Initialize next pointer to null
    }
};

// Stack class to implement a stack data structure using a linked list
class Stack {
private:
    Node* top;   // Pointer to the top element of the stack

public:
    // Constructor to initialize an empty stack
    Stack() {
        top = nullptr; // Initialize top pointer to null indicating an empty stack
    }

    // Function to check if the stack is empty
    bool isEmpty() {
        return top == nullptr; // Stack is empty if top pointer is null
    }

    // Function to push an element onto the stack
    void push(int value) {
        Node* newNode = new Node(value); // Create a new node with the given value
        newNode->next = top; // Link the new node to the current top element
        top = newNode; // Update top pointer to point to the new node
    }

    // Function to pop an element from the stack
    void pop() {
        if (isEmpty()) {
            cout << "Stack is empty. Cannot pop element." << endl;
            return;
        }

        Node* temp = top; // Store the current top node in a temporary variable
        top = top->next; // Move the top pointer to the next node
        delete temp; // Delete the previous top node
    }

    // Function to get the top element of the stack
    int getTop() {
        if (isEmpty()) {
            cout << "Stack is empty. No top element." << endl;
            return -1;
        }
        return top->data; // Return the data of the top node
    }

    // Function to get the current size of the stack
    int getSize() {
        int size = 0;
        Node* current = top; // Start from the top node
        while (current != nullptr) {
            size++; // Increment size for each node
            current = current->next; // Move to the next node
        }
        return size; // Return the size of the stack
    }

    // Function to print all elements of the stack
    void printStack() {
        if (isEmpty()) {
            cout << "Stack is empty." << endl;
            return;
        }
        cout << "Stack elements: ";
        Node* current = top; // Start from the top node
        while (current != nullptr) {
            cout << current->data << " "; // Print data of each node
            current = current->next; // Move to the next node
        }
        cout << endl;
    }

    // Function to clear all elements from the stack
    void clear() {
        while (!isEmpty()) {
            pop(); // Pop all elements until the stack becomes empty
        }
    }
};

int main() {
    Stack stack;

    cout << endl;

    // Push elements onto the stack
    stack.push(10);
    stack.push(20);
    stack.push(30);
    stack.push(40);
    stack.push(50);

    // Print the stack size
    cout << "Stack size: " << stack.getSize() << endl;

    // Print all elements of the stack
    stack.printStack();

    // Pop elements from the stack
    stack.pop();
    stack.pop();

    // Print all elements of the stack after popping
    stack.printStack();

    // Clear the stack
    stack.clear();

    // Print all elements of the stack after clearing
    stack.printStack();

    cout << endl;

    return 0;
}

/*
Sample Output:
Stack size: 5
Stack elements: 50 40 30 20 10 
Stack elements: 30 20 10 
Stack is empty.
*/
