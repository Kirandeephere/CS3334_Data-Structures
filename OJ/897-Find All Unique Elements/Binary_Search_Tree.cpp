#include <iostream>
#include <sstream>

using namespace std;

const int MAX_SIZE = 10000; 

class Node {
public:
    int data;
    int count;
    Node* left;
    Node* right;
    int index;

    Node(int value, int idx) : data(value), count(1), left(NULL), right(NULL), index(idx) {}
};

class BST {
private:
    Node* root;
    int currentIndex;

    Node* insert(Node* node, int value, int& index) {
        if (node == NULL) {
            return new Node(value, index);
        }

        if (value < node->data) {
            node->left = insert(node->left, value, index);
        } else if (value > node->data) {
            node->right = insert(node->right, value, index);
        } else {
            node->count++;
        }

        return node;
    }

public:
    BST() : root(NULL), currentIndex(0) {}

    void insert(int value) {
        currentIndex++;
        root = insert(root, value, currentIndex);
    }

    Node* getNodeByIndex(int index) {
        return getNodeByIndex(root, index);
    }

private:
    Node* getNodeByIndex(Node* node, int index) {
        if (node == NULL) {
            return NULL;
        }

        if (node->index == index) {
            return node;
        }

        Node* foundNode = getNodeByIndex(node->left, index);
        if (foundNode == NULL) {
            foundNode = getNodeByIndex(node->right, index);
        }

        return foundNode;
    }
};

void findUnique(int numbers[], int size, int unique[], int& uniqueSize) {
    BST bst;

    for (int i = 0; i < size; ++i) {
        bst.insert(numbers[i]);
    }

    uniqueSize = 0;
    for (int i = 1; i <= size; ++i) {
        Node* node = bst.getNodeByIndex(i);
        if (node != NULL && node->count == 1) {
            unique[uniqueSize] = node->data;
            ++uniqueSize;
        }
    }
}

int main() {
    int numbers[MAX_SIZE] = {0};
    int size = 0; 

    string line;
    while (getline(cin, line)) {
        istringstream iss(line);
        int num;

        while (iss >> num && size < MAX_SIZE) {
            numbers[size] = num;
            ++size;
        }

        int unique[MAX_SIZE] = {0};
        int uniqueSize = 0;

        findUnique(numbers, size, unique, uniqueSize);

        for (int i = 0; i < uniqueSize; ++i) {
            if (i == uniqueSize - 1) {
                cout << unique[i];
            } else {
                cout << unique[i] << " ";
            }
        }
        cout << endl;

        size = 0;
    }

    return 0;
}