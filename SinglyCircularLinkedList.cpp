#include <iostream>
using namespace std;

// Creating a node
class Node {
   public:
   int value;
   Node* next;
};

void traverseList(Node*& last){
    if(last == NULL){
        cout<< "List is Empty" << endl;
    }else{
        Node* current = last->next;
        cout<< "List: [ ";
        while(current != last){
            cout<< current->value << ", ";
            current = current->next;
        }

        cout<< last->value << " ]" <<endl;
    }
}

void insertAtEnd(Node*& last, int value){
    Node* newnode = new Node();
		newnode->value = value;

    if (last == NULL){
        newnode->next = newnode; 
        last = newnode;
    }else{
        Node* current = last;
        newnode->next = current->next; 
        current->next = newnode; 
     last = newnode;
    }
}

void insertAtBeginning(Node*& last, int value){
    Node* newnode = new Node();
    newnode->value = value;

    if (last == NULL){
        newnode->next = newnode;
        last = newnode;
    }else{
        Node* start = last->next; // set start to first node of the list
        newnode->next = start;
        last->next = newnode;
    }
}

void insertAtPosition(Node*& last, int value, int position){
    Node* newnode = new Node();
    newnode->value = value;

    if (last == NULL){
        newnode->next = newnode;
        last = newnode;
    }else{
        Node* current = last->next; // set start to first node of the list
        int count = 1;

        while(count!= position-1){
            if (current == last ){
                cout << "Position invalid";
                return;
            }else{
                count++;
                current = current->next;
            }
        }

        if(current->next == last){
            last = newnode; // If the position is the last node, update the last pointer to the new node
        }

        newnode->next = current->next; // Connect the new node to the next node in the list
        current->next = newnode; // Connect the current node to the new node
    }

}

void removeAtPosition(Node*& last, int key){
    Node* current = last->next; 

    if (current->next == last){
        last = NULL;
    }else{
        int count = 1;

        while(count!= key-1){
            count++;
            current= current->next;
        }

        if(current->next == last){
            last = current;
        }

        current->next = current->next->next;
    }

}

void removeAtBeginning(Node*& last){
    Node* current = last->next; 
    last->next = current->next;
}

void removeAtEnd(Node*& last){
    Node* current = last->next; 
    
    while(current->next != last){
        current = current->next;
    }

    current->next = last->next;
    last = current;
}

void searchValue(Node*& last, int key){
    if(last == NULL){
        cout<< "List is Empty" << endl;
    }else{
        Node* current = last->next;
        int count = 1;

        while(count!= key){
            count++;
            current= current->next;
            if (current== last && count!= key){
                cout<< "Invalid Key" << endl;
                return;
            }
        }

        int value = current->value;
        cout<< "Value found: " << value << endl;
    }
}

void searchKey(Node*& last, int value){
    if(last == NULL){
        cout<< "List is Empty" << endl;
    }else{
        Node* current = last->next;
        int count = 1;

        while(current->value != value){
            count++;
            current= current->next;
            if (current== last && current->value != value){
                cout<< "Value not Found" << endl;
                return;
            }
        }

        cout<< "Value found at key : " << count << endl;
    }
}

int main() {
  Node* last = NULL; // last points to the last node of the list

  traverseList(last);
  insertAtBeginning(last,3);
  insertAtEnd(last,4);
  insertAtEnd(last,5);
  traverseList(last);
  insertAtBeginning(last,1);
  traverseList(last);
  insertAtPosition(last,2,2);
  traverseList(last);
  removeAtPosition(last,3);
  traverseList(last);
  removeAtBeginning(last);
  traverseList(last);
  removeAtEnd(last);
  traverseList(last);
  searchValue(last,2);
  searchValue(last,3);
  searchKey(last,2);
  searchKey(last,34);
  searchKey(last,4);
}