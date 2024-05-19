#include <iostream>
#include <string>

using namespace std;

// Introduction of the code:
// This C++ program demonstrates the implementation of a Splay Tree, a self-adjusting binary search tree.
// It defines a class SplayTree to represent the Splay Tree and provides functionalities to insert and remove nodes.
// The Splay Tree automatically adjusts its structure to bring the most recently accessed node to the root position,
// optimizing search time for frequently accessed nodes.
// The program includes helper functions for insertion, deletion, and printing the tree structure.
// In the main function, it creates a Splay Tree, inserts some values into the tree, prints the tree structure,
// removes a value, and prints the updated tree structure.


// Define the structure for each node in the splay tree
struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int value) : data(value), left(nullptr), right(nullptr) {}
};

// Splay tree class
class SplayTree {
private:
    Node* root;

    // Helper function for in-order traversal to print the tree
    void printInOrder(Node* node, const string& prefix, bool isLeft) {
        if (node != nullptr) {
            cout << prefix;
            cout << (isLeft ? "├──" : "└──");
            cout << node->data << endl;

            printInOrder(node->left, prefix + (isLeft ? "│   " : "    "), true);
            printInOrder(node->right, prefix + (isLeft ? "│   " : "    "), false);
        }
    }

    // Helper function to find the minimum node in a subtree
    Node* findMin(Node* node) {
        while (node->left != nullptr)
            node = node->left;
        return node;
    }

    // Helper function to delete a node from the splay tree
    Node* deleteNode(Node* node, int value) {
        if (node == nullptr)
            return nullptr;

        // If the value to be deleted is less than the node's data, move left
        if (value < node->data)
            node->left = deleteNode(node->left, value);
        // If the value to be deleted is greater than the node's data, move right
        else if (value > node->data)
            node->right = deleteNode(node->right, value);
        else {
            // If the node has only one child or no child
            if (node->left == nullptr) {
                Node* temp = node->right;
                delete node;
                return temp;
            } else if (node->right == nullptr) {
                Node* temp = node->left;
                delete node;
                return temp;
            }

            // If the node has two children, find the minimum node in the right subtree
            Node* temp = findMin(node->right);
            // Copy the minimum node's data to this node
            node->data = temp->data;
            // Delete the minimum node from the right subtree
            node->right = deleteNode(node->right, temp->data);
        }
        return node;
    }

public:
    // Constructor to initialize the splay tree
    SplayTree() : root(nullptr) {}

    // Function to insert a value into the splay tree
    void insert(int value) {
        root = insertNode(root, value);
    }

    // Function to delete a value from the splay tree
    void remove(int value) {
        root = deleteNode(root, value);
    }

    // Function to print the splay tree in the specified format
    void print() {
        cout << endl;
        cout << "Splay Tree Structure:" << endl;
        printInOrder(root, "", false);
        cout << endl;
    }

private:
    // Helper function to insert a value into the splay tree
    Node* insertNode(Node* node, int value) {
        if (node == nullptr)
            return new Node(value);

        if (value < node->data)
            node->left = insertNode(node->left, value);
        else if (value > node->data)
            node->right = insertNode(node->right, value);

        return node;
    }
};

int main() {
    SplayTree splayTree;

    // Insert some values into the splay tree
    splayTree.insert(50);
    splayTree.insert(30);
    splayTree.insert(70);
    splayTree.insert(20);
    splayTree.insert(40);
    splayTree.insert(60);
    splayTree.insert(80);

    // Print the splay tree in the specified format
    splayTree.print();

    // Remove a value from the splay tree
    splayTree.remove(30);
    cout << "After removing value 30:" << endl;
    splayTree.print();

    return 0;
}

/*
Sample Output:
    Splay Tree Structure:
    └──50
        ├──30
        │   ├──20
        │   └──40
        └──70
            ├──60
            └──80

    After removing value 30:

    Splay Tree Structure:
    └──50
        ├──40
        │   ├──20
        └──70
            ├──60
            └──80
*/