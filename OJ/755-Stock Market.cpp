/*****************************************
 * (This comment block is added by the Judge System)
 * Submission ID: 289952
 * Submitted at:  2024-04-24 12:34:36
 *
 * User ID:       1991
 * Username:      57153680
 * Problem ID:    755
 * Problem Name:  Stock Market
 */

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
};

long long int MaxArea(long long int stockprices[], int n) {
    MyStack st(n);
    long long int maxArea = 0;
    int i = 0;

    while (i < n) {
        if (st.IsEmpty() || stockprices[i] >= stockprices[st.peek()]) {
            st.push(i);
            i++;
        } else {
            int top = st.peek();
            st.pop();
            long long int area;

            if (st.IsEmpty()) {
                area = stockprices[top] * i;
            } else {
                area = stockprices[top] * (i - st.peek() - 1);
            }
            maxArea = max(maxArea, area);
        }
    }

    while (!st.IsEmpty()) {
        int top = st.peek();
        st.pop();
        long long int area;
        if (st.IsEmpty()) {
            area = stockprices[top] * i;
        } else {
            area = stockprices[top] * (i - st.peek() - 1);
        }
        maxArea = max(maxArea, area);
    }

    return maxArea;
}

int main() {
    int testcases;
    cin >> testcases;

    while (testcases != 0) {
        int n; // number of days
        cin >> n;

        long long int stockprices[n];

        for (int i = 0; i < n; i++) {
            cin >> stockprices[i];
        }

        long long int maxArea = MaxArea(stockprices, n);

        cout << maxArea<<endl;

        testcases--;
    }

    return 0;
}