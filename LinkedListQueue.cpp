#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int value) {
        data = value;
        next = NULL;
    }
};

class LinkedQueue {
private:
    Node* front;
    Node* rear;
    int size;

public:
    LinkedQueue() {
        front = NULL;
        rear = NULL;
        size = 0;
    }

    bool IsEmpty() {
        return (front == NULL);
    }

    void Enqueue(int data) {
        Node* newNode = new Node(data);

        if (IsEmpty()) {
            front = rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }

        size++;
        cout << data << " enqueued to the queue." << endl;
    }

    void Dequeue(){
        Node* current = front;
        if (IsEmpty()) {
            cout << "ERROR: Queue Empty" << endl;
        } 
        else if(current->next == NULL){
            front = NULL;
            rear = NULL;
        }
        else{
            front = current->next;
        }
        size--;
        cout << "dequeued from the queue." << endl;
    }

    void print() {
        Node* current = front;
        cout << "Queue: ";
        while (current != NULL) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
};

int main() {
    LinkedQueue queue;

    queue.Enqueue(10);
    queue.Enqueue(20);
    queue.Enqueue(30);

    queue.print();

    queue.Dequeue();
    queue.print();

    queue.Enqueue(40);
    queue.Enqueue(50);
    queue.Enqueue(60);
    queue.print();

    return 0;
}



/* 1. **Boolean IsEmpty()
Postcondition: If the queue is empty, return true, otherwise return false**
2. **Boolean IsFull()
Postcondition: If the queue is full, return true, otherwise return false**
3. **Void Enqueue(ITEM_TYPE e)** // *to append one item to the rear of the queue*
**Precondition: q is not full
Postcondition: e is added to the sequence as the rear one**
4.  **ITEM_TYPE Dequeue()** // *take out the front one and return its value*
**Precondition: q is not empty
Postcondition: The front item in q is removed from the sequence and returned** */
