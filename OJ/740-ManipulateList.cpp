#include <iostream>
using namespace std;

// Creating a node
class Node {
   public:
   int value;
   Node* next;
};

void print(Node*& head, int position){
    Node* current = head;
    int count = 0;

    while (count != position) {
        current = current->next;
        count++;
    }

    cout << current->value;
}

void insertAtEnd(Node*& head, int value) {
    Node* newnode = new Node(); // Create a new node
    newnode->value = value;     // Assign the value
    newnode->next = NULL;    // Set the next pointer to nullptr

    if (head == NULL) {
        head = newnode;
    } else {
    
        Node* current = head;
        while (current->next != NULL) {
            current = current->next;
        }

        current->next = newnode;
    }
}

void insertAtBeginning(Node*& head, int value) {
    Node* newnode = new Node(); // Create new Node 
    newnode->value = value;
    newnode->next = head;
    head = newnode;
}

void insertAtPosition(Node*& head, int value, int position) {
    Node* newnode = new Node(); // Create new Node
    newnode->value = value; // Assign the value

    if (position == 1) {
        insertAtBeginning(head, value);
    } else {
        Node* previous = head;
        int count = 1;

        while (previous != NULL && count < position) {
            previous = previous->next;
            count++;
        }

        if (previous == NULL) {
            insertAtEnd(head, value); // Insert at the last position
        } else {
            newnode->next = previous->next;
            previous->next = newnode;
        }

    }
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

void reverse(Node*& head, int i, int j) {
    if (i == j || head == NULL) {
        return;
    }

    Node* current = head;
    Node* prev = NULL;
    Node* next = NULL;
    int count = 1;

    while (current != NULL && count < i) {
        prev = current;
        current = current->next;
        count++;
    }

    Node* reverse_start = current;
    Node* reverse_prev = NULL;

    for (int n = 0; n < j - i + 1; n++) {
        next = current->next;
        current->next = reverse_prev;
        reverse_prev = current;
        current = next;
    }

    if (prev != NULL) {
        prev->next = reverse_prev;
    } else {
        head = reverse_prev;
    }

    reverse_start->next = current; 
}

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
        cout<<"]" << endl;
    }

    return 0;
}

int main(){
    //Read 1st line:size
    int size;
    cin >> size;

    Node* head;
    head = NULL;

    // Read and create the list
    for(int i = 0; i < size; i++) {
        int value;
        cin >> value;
        insertAtEnd(head, value);
    }

    int numOperations;
    cin >> numOperations;

    for(int i = 0; i <numOperations; i++){
        int operationType;
        cin >> operationType;

        // 1 i val : insert "val" after the i-th element
        if(operationType == 1){
            int value, position;
            cin >> position;
            cin >> value;
            insertAtPosition(head, value, position);

        }

        // 2 i :delete element at i-th position
        if(operationType == 2){
            int position;
            cin >> position;
            if (position > size){return 0;}
            removeAtPosition(head, position);

        }

        // 3 i j: reverse interval [i,j] of the list
        if (operationType == 3){
            int position1 , position2;
            cin >> position1;
            cin >> position2;
            reverse(head,position1,position2);

        }
        // 4 i: output the i-th element in the list
        if(operationType == 4){
            int position;
            cin >> position;
            print(head,position-1);

            if(i != numOperations){
                cout << endl ;
            }
        }

    }
    
}