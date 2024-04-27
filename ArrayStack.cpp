#include <iostream>
using namespace std;

class MyStack {
private: 
    int* data;
    int top;
    int MAXSize;

public: 
    MyStack(int size) {
        data = new int[size];
        top = -1;
        MAXSize = size;
    }

    bool IsEmpty() {
        return (top == -1);
    }

    bool IsFull() {
        return (top == MAXSize - 1);
    }

    void push(int value) {
        if (IsFull()) {
            //cout << "Stack overflow!" << endl;
            return;
        }
        top++;
        data[top] = value;
    }

    int pop() {
        if (IsEmpty()) {
            //cout << "Stack underflow!" << endl;
            return -1; // Return a default value
        }
        int value = data[top];
        top--;
        return value;
    }

    int peek() {
        if (IsEmpty()) {
            //cout << "Stack underflow!" << endl;
            return -1; // Return a default value
        }
        return data[top];
    }

    void print() {
        if (IsEmpty()) {
            cout << "Stack underflow!" << endl;
            return;
        }

        cout << "Stack from top to bottom:" << endl;
        for (int i = top; i >= 0; i--) {
            cout << data[i] << endl;
        }
    }
};

int main() {
    MyStack stack(100);
    cout<<endl;
    stack.print();  // Stack underflow!
    cout<<endl;
    stack.push(10);
    stack.push(20);
    stack.print(); // 20, 10
    cout<<endl;
    stack.push(30);
    stack.push(40);
    stack.print(); // 40, 30, 20, 10
    cout<<endl;
    stack.pop();
    stack.print(); // 30, 20, 10
    cout<<endl;
    stack.push(40);
    stack.push(50);
    cout<<"Top of stack is: " << stack.peek() <<endl;

    return 0;
}