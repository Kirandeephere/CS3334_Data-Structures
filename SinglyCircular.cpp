#include <iostream>
using namespace std;

    class Node {
    public:
    int value;
    Node* next;
    };

    // Other operations
    int getLength(Node*& head) {
        // TO-DO: Implement getting the length of the list
        if(head == NULL){
            return 0;
        }
        else{
            Node* current = head->next;
            int count = 0;
            while(current->next != head){
                count++;
                current = current->next;
            }
            return count;
        }
        
    };

    bool isEmpty(Node*& head) {
        // TO-DO: Implement checking if the list is empty
        if(head == NULL){
            return true;
        }
        else{
            return false;
        }
    };

    void clear(Node*& head) {
        // TO-DO: Implement clearing the list by deleting all elements
        head = NULL;
    };

    // Insertion
    void insertAtBeginning(int value, Node*& head) {
        Node* newnode = new Node();
        newnode->value = value;

        if(head == NULL){
            head = newnode;
            newnode->next = head;
        } else {
            newnode->next = head;
            head = newnode;
        }

        cout << value << " added at the beginning. "<<endl;
    };

    void insertAtEnd(int value, Node*& head) {
        // TO-DO: Implement insertion at the end of the list
        Node* newnode = new Node();
        newnode->value = value;

        if(head == NULL){
            head = newnode;
            newnode->next = head;
        } else {
            Node* current = head->next;
            while(current->next != head){
                current = current->next;
            }

            current->next = newnode;
            newnode->next = head;
        }

        cout << value << " added at the end. " <<endl;
    };

    void insertAtPosition(int value, int position, Node*& head) {
        // TO-DO: Implement insertion at a specific position in the list
        Node* newnode = new Node();
        newnode->value = value;

        if(head == NULL){
            head = newnode;
            newnode->next = head;
        } else {
            Node* current = head;

            for(int i = 1; i < position; i++){
                if (current->next == head){
                    cout << position << " is invalid! "<<endl;
                    return;
                }
                current = current->next;
            }

            newnode->next = current->next->next;
            current->next = newnode;
        }
        
        cout << value << " added at the position "<< position <<" . "<<endl;
    };

    // Deletion
    void deleteAtBeginning(Node*& head) {
        // TO-DO: Implement deletion of the first element in the list
        Node* current = head;
        if (current == head ){
            head = NULL;
        }else{
            head = current->next;
        }

        cout << " first element deleted. " << endl;
    };

    void deleteAtEnd(Node*& head) {
        // TO-DO: Implement deletion of the last element in the list
        Node* current = head;
        if (current == head ){
            head = NULL;
        }else{
            current = current->next;
            while (current->next->next != head){
                current = current->next;
            }
            current->next = head;
        }

        cout << " last element deleted. " << endl;

    };

    void deleteAtPosition(int position, Node*& head) {
        // TO-DO: Implement deletion of an element at a specific position in the list
        Node* current = head;
        int size = getLength(head);
        if (current == head || position == 1 ){
            head = NULL;
        }else if( size < position ){
            cout<<" Invalid Position. "<<endl;
            return;
        }else{
            for(int i = 0; i < position; i++){
                current = current->next;
            }
            current->next = current->next->next;
        }

        cout << "Last element deleted. " << endl;
    };

    // Search
    int search(int value, Node*& head) {
        // TO-DO: Implement searching for the first occurrence of an element in the list
        Node* current = head;
        int count = 0;
        while(current->value != value){
            if (current == head){
                cout<<"Value not found. " <<endl;
                return 0;
            }
            count++;
            current = current->next;
        }
        cout<<"Value found at Key:  " <<value <<" ."<<endl;
        return count;
    };

    // Traversal and Display
    void display(Node*& head) {
        // TO-DO: Implement traversal and display of all the elements in the list
        if (head == NULL){
            cout<<"List is empty! "<<endl;
        }else{

            cout<<"List: [ ";

            Node* current = head;
            while(current->next != head){
                cout<<current->value<<" , ";
            }
            cout<< current->value << " ] "<<endl;
        }
    };


int main() {
    Node* head = NULL;


    // Perform operations on the list
    insertAtBeginning(5,head); // Insert 5 at the beginning
    display(head);
    insertAtEnd(10,head); // Insert 10 at the end
    insertAtPosition(7, 1,head); // Insert 7 at position 1
    deleteAtPosition(2,head); // Delete element at position 2


    // Display the elements of the list
    cout << "Elements in the list: ";
    display(head);

    // Other operations and test cases can be added here

    return 0;
}