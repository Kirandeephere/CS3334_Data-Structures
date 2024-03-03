#include <iostream>
using namespace std;

#define TOTAL_SLOTS 20

class MyQueue {
    private: 
        int front; //the index of the front slot that contains the front item
        int rear; //the index of the first empty slot at the rear of queue
        int items[TOTAL_SLOTS];

    public:
    MyQueue() {
        front = 0;
        rear = 0;
    }

    bool IsEmpty() {
        return (front == 0 && rear == 0);
    }

    bool IsFull(){
        return ((rear+1) % TOTAL_SLOTS == front);
    }

    void Enqueue(int value) {
        if (IsFull()) {
            cout << "Queue overflow!" << endl;
            return;
        }
        items[rear]=value; // Insert the element at the rear index
        rear=(rear+1) %TOTAL_SLOTS; // Update the rear index
    }

    int Dequeue() {
        int ret_val;
        if (IsEmpty()) {
            cout << "Queue underflow!" << endl;
            return 0;
        }
        ret_val=items[front]; // Store the element at the front index
        front=(front+1)%TOTAL_SLOTS; // Update the front index
        return ret_val; // Return the dequeued element
    }

    void print(){
        if (IsEmpty()){
            cout << "Queue Empty!" << endl;
        }
    
        for (int i = front; i != rear ; i = (i+1) %TOTAL_SLOTS ){
            
            cout << items[i] << endl;
        }
    }

};

int main(){
    MyQueue q;
    bool res = q.IsEmpty();
    cout << res <<endl;
    q.Enqueue(0);
    res = q.IsEmpty();
    cout << res <<endl;
    q.Enqueue(2);
    q.Enqueue(3);
    q.Enqueue(4);
    q.Dequeue();
    //q.print();
}