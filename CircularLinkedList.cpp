#include <iostream>
using namespace std;

class Node {
    public:
    int value;
    Node* next;
    Node* prev;
};

void traverseList(Node*& last){
    if (last == NULL){
        cout<<"List is empty"<<endl;
    }else{
        Node* current = last->next;
        cout<<"List: [ ";
        while (current != last){
            cout<< current->value << ", ";
            current = current->next;
        }
        cout << current->value << " ]" <<endl;
    }
}

void insertAtBeginning(Node*& last, int value){
    Node* newnode = new Node;
    newnode->value = value;

    if (last == NULL){
        newnode->prev = newnode;
        newnode->next = newnode;
        last = newnode;
    }else{
        Node* current = last->next;
        newnode->prev = last;
        newnode->next = current;
        current->prev = newnode;
        last->next = newnode;
    }
}

void insertAtEnd(Node*& last, int value){
    Node* newnode = new Node;
    newnode->value = value;

    if (last == NULL){
        newnode->prev = newnode;
        newnode->next = newnode;
        last = newnode;
    } else {
        Node* current = last; 
        Node* first = last->next; // Get the first node

        current->next = newnode;
        newnode->prev = current;
        newnode->next = first;
        first->prev = newnode;
        last = newnode;
    }
}

// Function to insert a node at a specific position
void insertAtPosition(Node*& last, int value, int position) {
    Node* newnode = new Node;
    newnode->value = value;

    if (last == NULL){
        newnode->prev = newnode;
        newnode->next = newnode;
        last = newnode;
    }else{
        Node* current = last->next; // set start to first node of the list
        int count = 1;

        while(count!= position-1){
            count++;
            current = current->next;
        }

        if(current->next == last){
            last = newnode; // If the position is the last node, update the last pointer to the new node
        }
        
        newnode->next = current->next;
        newnode->prev = current; 
        current->next = newnode;
    }
}

void removeAtBeginning(Node*& last){
    if(last == NULL){
        return;
    }else{
        Node* current = last;
        Node* second = last->next->next;

        second->prev= last;
        current->next = second;
    }

}

void removeAtEnd(Node*& last){
    if(last == NULL){
        return;
    }else{
        Node* current = last->prev;
        Node* first = last->next;

        current->next = first;
        first->prev = current;
        last = current;
    }

}

int main(){
    Node* last = new Node;
    last = NULL;

    traverseList(last);
    insertAtBeginning(last,1);
    traverseList(last);
    insertAtEnd(last, 2);
    insertAtEnd(last, 3);
    insertAtEnd(last, 4);
    traverseList(last);
    removeAtBeginning(last);
    traverseList(last);
    removeAtEnd(last);
    traverseList(last);
    insertAtPosition(last,1,1);
    traverseList(last);
    insertAtPosition(last,4,4);
    traverseList(last);
    insertAtPosition(last,5,5);
    traverseList(last);
    insertAtPosition(last,6,6);
    traverseList(last);

}