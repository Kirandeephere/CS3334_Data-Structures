#include <iostream>
using namespace std;

/**
 * Single Linked List Implementation in C++
 * 
 * This code provides a basic implementation of a singly linked list with the following functionalities:
 * - Printing the list
 * - Inserting nodes at the start, end, and in order
 * - Counting the number of nodes
 * - Searching for a node by value
 * - Removing a node by value
 * - Reversing the list
 * - Finding the nth node from the end
 * 
 * The main function demonstrates the usage of these functionalities.
 */

class Node {
public:
    int data; // Data part of the node
    Node* next; // Pointer to the next node in the list
};

// Function to print the linked list
void PrintList(Node* head) {
    // Check if the list is empty
    if (head == NULL) {
        cout << "List is Empty!" << endl;
    } else {
        // Traverse the list and print each node's data
        Node* current = head;
        cout << "[ ";
        while (current->next != NULL) {
            cout << current->data << " , "; // Print the current node's data
            current = current->next;
        }
        cout << current->data << " ]" << endl; // Print the last node's data
    }
}

// Function to insert a node at the start of the list
void InsertAtStart(Node*& head, int value) {
    // Create a new node and assign the given value to its data
    Node* newnode = new Node();
    newnode->data = value;

    // Check if the list is empty
    if (head == NULL) {
        // If the list is empty, assign the new node as the head
        head = newnode;
    } else {
        // If the list is not empty, insert the new node at the start
        newnode->next = head; // Make the new node point to the current head
        head = newnode; // Update the head to point to the new node
    }
}

// Function to insert a node at the end of the list
void InsertAtEnd(Node*& head, int value) {
    // Create a new node and assign the given value to its data
    Node* newnode = new Node();
    newnode->data = value;

    // Check if the list is empty
    if (head == NULL) {
        // If the list is empty, assign the new node as the head
        head = newnode;
    } else {
        // Traverse the list to find the last node
        Node* current = head;
        while (current->next != NULL) {
            current = current->next;
        }

        // Append the new node to the end of the list
        current->next = newnode;
        newnode->next = NULL;
    }
}

// Function to insert a node in a sorted order
void InsertInOrder(Node*& head, int value) {
    // Create a new node and assign the given value to its data
    Node* newnode = new Node();
    newnode->data = value;
    newnode->next = NULL;

    // Check if the list is empty
    if (head == NULL) {
        // If the list is empty, make the new node the head
        head = newnode;
    } else if (value < head->data) {
        // If the new value is smaller than the head's data,
        // insert the new node at the beginning of the list
        newnode->next = head;
        head = newnode;
    } else {
        // Traverse the list to find the correct position for the new node
        Node* current = head;
        while (current->next != NULL && current->next->data < value) {
            current = current->next;
        }
        // Insert the new node after the current node
        newnode->next = current->next;
        current->next = newnode;
    }
}

// Function to count the number of nodes in the list
int CountNodes(Node* head) {
    // Initialize a count variable to keep track of the number of nodes
    int count = 0;

    // Check if the list is empty
    if (head == NULL) {
        count = 0; // If the list is empty, set the count to 0
    } else {
        // Traverse the list and increment the count for each node
        Node* current = head;
        while (current != NULL) {
            count++; // Increment the count
            current = current->next; // Move to the next node
        }
    }
    return count; // Return the final count
}

// Function to search for a node with a given value
void SearchNode(Node* head, int value) {
    if (head == NULL) {
        cout << "List is Empty!" << endl;
    } else {
        Node* current = head;
        int count = 0;

        // Traverse the list to find the node with the given value
        while (current != NULL && current->data != value) {
            current = current->next;
            count++;
        }

        // Check if the node was found
        if (current == NULL) {
            cout << "Node not found!" << endl;
        } else {
            cout << "Node with value " << current->data << " found at position " << count << "." << endl;
        }
    }
}

// Function to delete a node with a given value
void DeleteNode(Node*& head, int value) {
    if (head == NULL) {
        cout << "List is empty!" << endl;
    } else {
        Node* current = head;
        Node* previous = NULL;

        // Traverse the list to find the node to be deleted
        while (current != NULL && current->data != value) {
            previous = current;
            current = current->next;
        }

        // Check if the node was found
        if (current == NULL) {
            cout << "Value not found!" << endl;
        } else {
            // If the node to be deleted is the head node
            if (previous == NULL) {
                head = head->next;
            } else {
                // Skip the current node
                previous->next = current->next;
            }
            delete current; // Free the memory of the deleted node
            cout << "Node with value " << value << " has been deleted!" << endl;
        }
    }
}

// Function to reverse the linked list
void ReverseList(Node*& head) {
    Node* prev = NULL;
    Node* current = head;
    Node* next = NULL;

    while (current != NULL) {
        next = current->next; // Store the next node
        current->next = prev; // Reverse the current node's pointer
        prev = current; // Move pointers one position ahead
        current = next;
    }
    head = prev; // Update head to the new front
}

// Function to find the nth node from the end
void FindNthFromEnd(Node* head, int n) {
    int length = 0;
    Node* temp = head;

    // Count the number of nodes in the list
    while (temp != NULL) {
        temp = temp->next;
        length++;
    }

    // Check if the value of n is within the length of the list
    if (n > length) {
        cout << "The list is shorter than " << n << " nodes." << endl;
        return;
    }

    temp = head;
    // Get the (length-n+1)th node from the start
    for (int i = 1; i < length - n + 1; i++) {
        temp = temp->next;
    }

    cout << "The " << n << "th node from the end has the value " << temp->data << "." << endl;
}

int main() {
    Node* head;
    head = NULL;

    cout << endl;
    
    PrintList(head); // Print the empty list
    SearchNode(head, 0); // Search for a value in the empty list

    // Insert nodes in order
    InsertInOrder(head, 1);
    InsertInOrder(head, 2);
    InsertInOrder(head, 4);
    InsertInOrder(head, 5);
    InsertInOrder(head, 3);

    // Print the list after inserting nodes
    PrintList(head);
    // Print the number of nodes in the list
    cout << CountNodes(head) << endl;

    // Search for nodes with specific values
    SearchNode(head, 0);
    SearchNode(head, 2);

    // Delete nodes with specific values
    DeleteNode(head, 3);
    DeleteNode(head, 7);

    // Print the list after deleting nodes
    PrintList(head);

    // Reverse the list
    ReverseList(head);
    PrintList(head);

    // Find the nth node from the end
    FindNthFromEnd(head, 2);
    FindNthFromEnd(head, 5);

    cout << endl;
    return 0;
}


/*
Sample Output:

List is Empty!
List is Empty!
[ 1 , 2 , 3 , 4 , 5 ]
5
Node not found!
Node with value 2 found at position 1.
Node with value 3 has been deleted!
Value not found!
[ 1 , 2 , 4 , 5 ]
[ 5 , 4 , 2 , 1 ]
The 2th node from the end has the value 2.
The list is shorter than 5 nodes.

*/
