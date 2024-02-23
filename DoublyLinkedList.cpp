#include <iostream>
using namespace std;

class Node {
    public:
    int value;
    Node* next;
    Node* prev;
};

int traverseLinkedList(Node* head, bool returnCount) {
    Node* current = head;
    if (!returnCount){cout << "Doubly Linked List: [";}
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
        cout<<"]"<<endl;
    }

    return 0;
}

void insertAtBeginning(Node*& head, int value) {
    Node* newnode = new Node(); // Create new Node 
    newnode->value = value;
    if (head == NULL){
      newnode->prev = NULL;
      newnode->next = NULL;
      head = newnode;
    } else{
      newnode->prev = NULL;
      newnode->next = head;
      head = newnode;
    }
}

void insertAtEnd(Node*& head, int value) {
    Node* newnode = new Node(); // Create new Node 
    newnode->value = value;
    
    if (head == NULL) {
      // If the list is empty, set the head to the new node
      head = newnode;
      newnode->prev = NULL;
      newnode->next = NULL;
    } else {
      // Traverse to the last node
      Node* current = head;
      while (current->next != NULL) {
        current = current->next;
      }

      // Reset the pointers
      newnode->prev = current;
      current->next = newnode;
      newnode->next = NULL;
    }
}

void insertAtPosition(Node*& head, int position, int value) {
    // Create a new node
    Node* newNode = new Node();
    newNode->value = value;
    newNode->next = NULL;
    newNode->prev = NULL;

    // If the list is empty or position is 1, make the new node the head
    if (head == NULL || position == 1) {
        newNode->next = head;
        if (head != NULL) {
            head->prev = newNode;
        }
        head = newNode;
        return;
    }

    // Traverse to the given position or the end of the list
    Node* current = head;
    int currentPosition = 1;
    while (currentPosition < position - 1 && current->next != NULL) {
        current = current->next;
        currentPosition++;
    }

    // Insert the new node at the given position
    newNode->next = current->next;
    if (current->next != NULL) {
        current->next->prev = newNode;
    }
    current->next = newNode;
    newNode->prev = current;
}

void removeAtBeginning(Node*& head) {
  Node* current = head->next;
  current->prev = NULL;
  head = current;
}

void removeAtEnd(Node*& head) {
  Node* current = head;

  if(current == NULL){
    return;
  }
  else if (current->next == NULL){
    head = NULL;
    return;
  }
  else {
    while(current->next->next != NULL){
      current = current->next;
    }
    current->next = NULL;
  }

}

void removeAtPosition(Node*& head, int position){
  Node* current = head;

  if(position == 1){
    head = NULL;
  }
  else {
    int currentPosition = 1;

    while (current != NULL && currentPosition < position) {
        current = current->next;
        currentPosition++;
    }

    if (current == NULL) {
        cout << "No such position found!" << endl;
        return;
    }

    current->next->next->prev = current;
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

int main() {
  Node* head;
  head = NULL;

  traverseLinkedList(head, false);
  cout << traverseLinkedList(head, true) <<endl;

  insertAtBeginning(head, 20);
  insertAtBeginning(head, 10);
  traverseLinkedList(head, false); 
  cout << traverseLinkedList(head, true) <<endl;

  insertAtEnd(head, 30);
  traverseLinkedList(head, false); 
  cout << traverseLinkedList(head, true) <<endl;

  insertAtPosition(head, 2, 15);
  traverseLinkedList(head, false); 

  insertAtPosition(head, 1, 5);
  traverseLinkedList(head, false); 

  insertAtPosition(head, 7, 35);
  traverseLinkedList(head, false); 

  removeAtBeginning(head);
  traverseLinkedList(head, false); 

  removeAtEnd(head);
  traverseLinkedList(head, false); 

  removeAtPosition(head,2);
  traverseLinkedList(head, false); 

  removeAtPosition(head,4);
  traverseLinkedList(head, false); 

}