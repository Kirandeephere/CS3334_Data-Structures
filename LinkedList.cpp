#include <iostream>
using namespace std;

// Creating a node
class Node {
   public:
   int value;
   Node* next;
};

int traverseLinkedList(Node* head, bool returnCount) {
    Node* current = head;
    if (!returnCount){cout << "Linked List: [";}
    int count = 0;

    while (current != NULL) {
        count++;
        if (!returnCount){
            if (current->next == NULL){
                cout << current->value;
            }else {
                cout << current->value <<",";
            }
        }
        current = current->next;
    }

    if (returnCount) {
        return count;
    } 
    else {
        cout<<"]";
    }

    return 0;
}

void insertAtBeginning(Node*& head, int value) {
    Node* newnode = new Node(); // Create new Node 
    newnode->value = value;
    newnode->next = head;
    head = newnode;
}

void insertAtEnd(Node*& head, int value) {
    Node* newnode = new Node(); // Create a new node
    newnode->value = value;     // Assign the value
    newnode->next = NULL;    // Set the next pointer to nullptr

    if (head == NULL) {
        // If the linked list is empty, set the head to the new node
        head = newnode;
    } else {
        // Traverse to the last node
        Node* current = head;
        while (current->next != NULL) {
            current = current->next;
        }

        // Set the next pointer of the last node to the new node
        current->next = newnode;
    }
}

void insertAtPosition(Node*& head, int value, int position) {
    Node* newnode = new Node(); // Create new Node
    newnode->value = value; // Assign the value

    if (position == 1) {
        insertAtBeginning(head, value);
    } else {
        Node* previous = head;
        int count = 1;

        while (previous != NULL && count < position - 1) {
            previous = previous->next;
            count++;
        }

        if (previous == NULL) {
            cout << "Invalid position for " << value << ". will be added at last" << endl;
            insertAtEnd(head, value); // Insert at the last position
        } else {
            newnode->next = previous->next;
            previous->next = newnode;
        }

    }
}

void insertAtMiddle(Node*& head, int value) {
    Node* newnode = new Node(); // Create a new node
    newnode->value = value;     // Assign the value
    
    int count = traverseLinkedList(head, true);
    int mid = count / 2 + 1; // Calculate the middle position
    insertAtPosition(head, value, mid);
    
}

void removeAtBeginning(Node*& head) {
    head = head->next;
}

void removeAtEnd(Node*& head) {
    Node* current = head;
    while (current->next->next != nullptr) {
        current = current->next;
    }
    current->next = NULL;
}

void removeAtPosition(Node*& head, int position) {
    Node* current = head;
    int count = 1;

    if (position == 1){
        head = current->next;
    }
    else{
        while (current != NULL && count < position - 1) {
            current = current->next;
            count++;
        }
        current->next = current->next->next;
    }
    
}

Node* searchNode(Node* head, int key) {
    Node* current = head;
    while (current != NULL) {
        if (current->value == key) {
            return current;  // Return the pointer to the found node
        }
        current = current->next;
    }
    return NULL;  // Return NULL if the key is not found
}

void reverse (Node* head, int i, int j){
    if (i == j || head == NULL) {
        return;
    }

    // Initialize current, previous, and next pointers
    Node* current = head;
    Node* prev = nullptr;
    Node* next = nullptr;
    int count = 1;

    // Traverse the list to reach the i-th node
    while (current != nullptr && count < i) {
        prev = current;
        current = current->next;
        count++;
    }

    Node* reverse_start = current;  // Node at position i
    Node* reverse_prev = nullptr;   // Previous node in the reversed portion

    // Reverse the pointers for the portion of the list from i to j
    for (int n = 0; n < j - i + 1; n++) {
        next = current->next;
        current->next = reverse_prev;
        reverse_prev = current;
            current = next;
    }

    // Update the pointers to reconnect the reversed portion with the rest of the list
    if (prev != Null) {
        prev->next = reverse_prev;
    }
    else {
        head = reverse_prev;
    }

}

int main() {
  Node* head;
  head = NULL;

  /* insertAtBeginning(head, 0);
  insertAtEnd(head,1);
  insertAtEnd(head,2);
  insertAtEnd(head,3);
  insertAtEnd(head,4);
  insertAtEnd(head,5);
  insertAtPosition(head, 10, 2);
  insertAtMiddle(head, 20);
  insertAtPosition(head, 30, 15);
  removeAtBeginning(head);
  removeAtEnd(head);
  removeAtPosition(head,1);
  searchNode(head, 5);
  traverseLinkedList(head,false);
  reverse(head, 1 , 4);
  cout<<endl;
  traverseLinkedList(head,false);
  */

    insertAtEnd(head, 1);
    insertAtEnd(head, 2);
    insertAtEnd(head, 3);
    insertAtEnd(head, 4);
    insertAtEnd(head, 5);
    insertAtEnd(head, 6);
    insertAtEnd(head, 7);
    insertAtEnd(head, 8);
    insertAtEnd(head, 9);
    insertAtEnd(head, 10);
    traverseLinkedList(head,false);
    cout<<endl;

    reverse(head, 3, 8);
    traverseLinkedList(head,false);
    cout<<endl;

}