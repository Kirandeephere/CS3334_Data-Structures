#include <iostream>
#define MAX_SIZE 100

using namespace std;

/**
 * Stack Implementation in C++
 * 
 * This code provides a simple implementation of a stack data structure using an array.
 * The Stack class supports basic operations like push, pop, isEmpty, isFull, getTop, getSize, printStack, and clear.
 * 
 * The main function demonstrates the usage of the Stack class by performing various operations on a stack of integers.
 */

// Stack class to implement a stack data structure
class Stack {
private:
    int top;                // Index of the top element
    int arr[MAX_SIZE];      // Array to store the stack elements

public:
    // Constructor to initialize the stack
    Stack() {
        top = -1;           // Initialize top index to -1 indicating an empty stack
    }

    // Function to check if the stack is empty
    bool isEmpty() {
        return (top == -1); // Stack is empty if top is -1
    }

    // Function to check if the stack is full
    bool isFull() {
        return (top == MAX_SIZE - 1);  // Stack is full if top is equal to the maximum index
    }

    // Function to push an element onto the stack
    void push(int data) {
        if (isFull()) {
            cout << "Stack is full. Cannot push element." << endl;
            return;
        }
        arr[++top] = data;  // Increment top and insert the element at the new top index
    }

    // Function to pop an element from the stack
    void pop() {
        if (isEmpty()) {
            cout << "Stack is empty. Cannot pop element." << endl;
            return;
        }
        --top;              // Decrement top to remove the top element
    }

    // Function to get the top element of the stack
    int getTop() {
        if (isEmpty()) {
            cout << "Stack is empty. No top element." << endl;
            return -1;
        }
        return arr[top];    // Return the element at the top
    }

    // Function to get the current size of the stack
    int getSize() {
        return top + 1;     // Size of the stack is top + 1
    }

    // Function to print all elements of the stack
    void printStack() {
        if (isEmpty()) {
            cout << "Stack is empty." << endl;
            return;
        }
        cout << "Stack elements: ";
        for (int i = top; i >= 0; --i) {
            cout << arr[i] << " "; // Print elements from top to bottom
        }
        cout << endl;
    }

    // Function to clear all elements from the stack
    void clear() {
        top = -1; // Reset top index to clear all elements
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
