#include <iostream>
using namespace std;

/**
 * Double Linked List Implementation in C++
 * 
 * This code provides a basic implementation of a doubly linked list with the following functionalities:
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
    Node* prev; // Pointer to the previous node in the list
    Node* next; // Pointer to the next node in the list
};

// Function to print the linked list
void PrintList(Node* head) {
    if (head == NULL) {
        cout << "List is Empty!" << endl;
    } else {
        Node* current = head;
        cout << "[ ";
        while (current != NULL) {
            cout << current->data << " , ";
            current = current->next;
        }
        cout << "]" << endl;
    }
}

// Function to insert a node at the start of the list
void InsertAtStart(Node*& head, int value) {
    Node* newnode = new Node();
    newnode->data = value;
    newnode->prev = NULL;

    if (head == NULL) {
        newnode->next = NULL;
    } else {
        newnode->next = head;
        head->prev = newnode;
    }

    head = newnode;
}

// Function to insert a node at the end of the list
void InsertAtEnd(Node*& head, int value) {
    Node* newnode = new Node();
    newnode->data = value;
    newnode->next = NULL;

    if (head == NULL) {
        newnode->prev = NULL;
        head = newnode;
    } else {
        Node* current = head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newnode;
        newnode->prev = current;
    }
}

// Function to insert a node in a sorted order
void InsertInOrder(Node*& head, int value) {
    Node* newnode = new Node();
    newnode->data = value;

    if (head == NULL || value <= head->data) {
        newnode->next = head;
        if (head != NULL)
            head->prev = newnode;
        head = newnode;
        newnode->prev = NULL;
    } else {
        Node* current = head;
        while (current->next != NULL && current->next->data < value) {
            current = current->next;
        }
        newnode->next = current->next;
        if (current->next != NULL)
            current->next->prev = newnode;
        current->next = newnode;
        newnode->prev = current;
    }
}

// Function to remove a node with a given value
void RemoveNode(Node*& head, int value) {
    if (head == NULL) {
        cout << "List is empty!" << endl;
        return;
    }

    Node* current = head;
    while (current != NULL && current->data != value) {
        current = current->next;
    }

    if (current == NULL) {
        cout << "Value not found!" << endl;
        return;
    }

    if (current->prev != NULL) {
        current->prev->next = current->next;
    } else {
        head = current->next;
    }

    if (current->next != NULL) {
        current->next->prev = current->prev;
    }

    delete current;
    cout << "Value " << value << " has been removed!" << endl;
}

// Function to count the number of nodes in the list
int CountNodes(Node* head) {
    int count = 0;
    Node* current = head;
    while (current != NULL) {
        count++;
        current = current->next;
    }
    return count;
}

// Function to search for a node with a given value
void SearchNode(Node* head, int value) {
    if (head == NULL) {
        cout << "List is empty!" << endl;
        return;
    }

    Node* current = head;
    int position = 1;
    while (current != NULL && current->data != value) {
        current = current->next;
        position++;
    }

    if (current == NULL) {
        cout << "Node not found!" << endl;
    } else {
        cout << "Node with value " << value << " found at position " << position << "." << endl;
    }
}

// Function to reverse the linked list
void ReverseList(Node*& head) {
    Node* temp = NULL;
    Node* current = head;

    while (current != NULL) {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        current = current->prev;
    }

    if (temp != NULL) {
        head = temp->prev;
    }
}

// Function to find the nth node from the end
void FindNthFromEnd(Node* head, int n) {
    int length = 0;
    Node* temp = head;

    while (temp != NULL) {
        temp = temp->next;
        length++;
    }

    if (n > length) {
        cout << "The list is shorter than " << n << " nodes." << endl;
        return;
    }

    temp = head;
    for (int i = 1; i < length - n + 1; i++) {
        temp = temp->next;
    }

    cout << "The " << n << "th node from the end has the value " << temp->data << "." << endl;
}

int main() {
    Node* head = NULL;

    cout << endl;

    PrintList(head); // Print the empty list

    // Insert nodes in order
    InsertInOrder(head, 2);
    InsertInOrder(head, 5);
    InsertInOrder(head, 3);
    InsertInOrder(head, 1);
    InsertInOrder(head, 4);

    PrintList(head); // Print the list after inserting nodes
    cout << "Number of nodes: " << CountNodes(head) << endl; // Print the number of nodes in the list

    // Search for nodes with specific values
    SearchNode(head, 3);
    SearchNode(head, 6);

    // Remove nodes with specific values
    RemoveNode(head, 3);
    RemoveNode(head, 6);

    PrintList(head); // Print the list after removing nodes

    // Reverse the list
    ReverseList(head);
    PrintList(head); // Print the reversed list

    // Find the nth node from the end
    FindNthFromEnd(head, 2);
    FindNthFromEnd(head, 5);

    cout << endl;

    return 0;
}

/*
Sample Output:
List is Empty!
[ 1 , 2 , 3 , 4 , 5 , ]
Number of nodes: 5
Node with value 3 found at position 3.
Node not found!
Value 3 has been removed!
Value not found!
[ 1 , 2 , 4 , 5 , ]
[ 5 , 4 , 2 , 1 , ]
The 2th node from the end has the value 4.
The list is shorter than 5 nodes.
*/
