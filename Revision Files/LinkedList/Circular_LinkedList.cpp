#include <iostream>
using namespace std;

/**
 * Circular Linked List Implementation in C++
 * 
 * This code provides a basic implementation of a circular linked list with the following functionalities:
 * - Printing the list
 * - Inserting nodes at the start and in order
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

// Function to print the circular linked list
void PrintList(Node* head) {
    if (head == NULL) {
        cout << "List is Empty!" << endl;
    } else {
        Node* current = head;
        cout << "[ ";
        do {
            cout << current->data << " , "; // Print the current node's data
            current = current->next;
        } while (current != head); // Continue printing until we reach the starting point again
        cout << "]" << endl;
    }
}

// Function to insert a node at the start of the list
void InsertAtStart(Node*& head, int value) {
    Node* newnode = new Node();
    newnode->data = value;

    if (head == NULL) {
        newnode->next = newnode;
    } else {
        Node* current = head;
        while (current->next != head) {
            current = current->next;
        }
        newnode->next = head;
        current->next = newnode;
    }
    head = newnode;
}

// Function to insert a node in a sorted order
void InsertInOrder(Node*& head, int value) {
    Node* newnode = new Node();
    newnode->data = value;
    newnode->next = NULL;

    if (head == NULL) {
        newnode->next = newnode;
        head = newnode;
    } else if (value < head->data) {
        Node* current = head;
        while (current->next != head) {
            current = current->next;
        }
        newnode->next = head;
        current->next = newnode;
        head = newnode;
    } else {
        Node* current = head;
        while (current->next != head && current->next->data < value) {
            current = current->next;
        }
        newnode->next = current->next;
        current->next = newnode;
    }
}

// Function to count the number of nodes in the list
int CountNodes(Node* head) {
    int count = 0;
    if (head != NULL) {
        Node* current = head;
        do {
            count++;
            current = current->next;
        } while (current != head);
    }
    return count;
}

// Function to search for a node with a given value
void SearchNode(Node* head, int value) {
    if (head == NULL) {
        cout << "List is empty!" << endl;
    } else {
        Node* current = head;
        int count = 0;
        do {
            if (current->data == value) {
                cout << "Node with value " << current->data << " found at position " << count << "." << endl;
                return;
            }
            current = current->next;
            count++;
        } while (current != head);
        cout << "Node not found!" << endl;
    }
}

// Function to remove a node with a given value
void RemoveNode(Node*& head, int value) {
    if (head == NULL) {
        cout << "List is empty!" << endl;
        return;
    }

    Node* current = head;
    Node* prev = NULL;

    do {
        if (current->data == value) {
            if (current == head) {
                if (current->next == head) {
                    delete current;
                    head = NULL;
                    return;
                }
                Node* temp = head;
                while (temp->next != head) {
                    temp = temp->next;
                }
                temp->next = head->next;
                head = head->next;
            } else {
                prev->next = current->next;
                delete current;
            }
            cout << "Value " << value << " has been removed!" << endl;
            return;
        }
        prev = current;
        current = current->next;
    } while (current != head);

    cout << "Value not found!" << endl;
}

// Function to reverse the circular linked list
void ReverseList(Node*& head) {
    if (head == NULL || head->next == head) {
        return;
    }

    Node* prev = NULL;
    Node* current = head;
    Node* next = NULL;
    Node* tail = head;

    do {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    } while (current != head);

    tail->next = prev;
    head = prev;
}

// Function to find the nth node from the end
void FindNthFromEnd(Node* head, int n) {
    int length = 0;
    Node* temp = head;

    if (head == NULL) {
        cout << "The list is empty." << endl;
        return;
    }

    do {
        temp = temp->next;
        length++;
    } while (temp != head);

    if (n > length) {
        cout << "The list is shorter than " << n << " nodes." << endl;
        return;
    }

    temp = head;
    for (int i = 0; i < length - n; i++) {
        temp = temp->next;
    }

    cout << "The " << n << "th node from the end has the value " << temp->data << "." << endl;
}

int main() {
    Node* head = NULL;

    cout << endl;

    PrintList(head); // Print the empty list

    // Insert nodes in order
    InsertInOrder(head, 1);
    InsertInOrder(head, 2);
    InsertInOrder(head, 4);
    InsertInOrder(head, 5);
    InsertInOrder(head, 3);

    PrintList(head); // Print the list after inserting nodes
    cout << "Number of nodes: " << CountNodes(head) << endl; // Print the number of nodes in the list

    // Search for nodes with specific values
    SearchNode(head, 0);
    SearchNode(head, 2);

    // Remove nodes with specific values
    RemoveNode(head, 3);
    RemoveNode(head, 7);

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
Node not found!
Node with value 2 found at position 1.
Value 3 has been removed!
Value not found!
[ 1 , 2 , 4 , 5 , ]
[ 5 , 4 , 2 , 1 , ]
The 2th node from the end has the value 4.
The list is shorter than 5 nodes.
*/
