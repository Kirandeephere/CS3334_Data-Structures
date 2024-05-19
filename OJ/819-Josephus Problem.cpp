/*****************************************
 * (This comment block is added by the Judge System)
 * Submission ID: 289991
 * Submitted at:  2024-04-24 13:52:21
 *
 * User ID:       1991
 * Username:      57153680
 * Problem ID:    819
 * Problem Name:  Josephus Problem
 */

#include <iostream>
using namespace std;

class Node {
public:
    int value;
    Node* next;
};

void CreateList(Node*& head, int value) {
    Node* newnode = new Node();
    newnode->value = value;
    newnode->next = NULL;

    if (head == NULL) {
        head = newnode;
        newnode->next = head; 
    } else {
        Node* current = head;
        while (current->next != head) {
            current = current->next;
        }
        current->next = newnode;
        newnode->next = head; 
    }
}

void removeNode(Node*& head, Node* node) {
    if (head == NULL || node == NULL) {
        return;
    }

    Node* current = head;
    while (current->next != node) {
        current = current->next;
    }

    if (node == head) {
        head = head->next;
    }

    current->next = node->next;
}

void printOrder(Node* head, int n, int m) {
    Node* current = head;
    while (n > 0) {
        for (int i = 1; i < m; i++) {
            current = current->next;
        }

        Node* nextNode = current->next;
        
        if (n == 1) {
            cout << current->value<<endl;
        } else {
            cout << current->value << " ";
        }

        removeNode(head, current);
        current = nextNode;
        n--;
    }
}

int main(){
    Node* head;
    head = NULL;

    int n;
    cin >> n;

    for(int i = 1; i < n+1; i++){
        CreateList(head, i);
    }

    int m;
    cin >> m;
    printOrder(head, n, m);

}