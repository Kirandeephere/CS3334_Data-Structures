#include <iostream>
#include <string>

using namespace std;

// Introduction of the code:
// This C++ program demonstrates the implementation of an AVL (Adelson-Velsky and Landis) tree.
// It defines a class AVLTree to represent the AVL tree and provides functionalities to insert and delete nodes,
// as well as to print the tree structure in a specified format and perform in-order traversal.
// The program includes helper functions for rotation, height calculation, balancing, and printing the tree structure.
// In the main function, it creates a sample AVL tree, inserts some values, prints the tree structure, performs in-order traversal,
// deletes some values, and again prints the tree structure and in-order traversal to demonstrate the AVL tree operations.

// Define the structure for each node in the AVL tree
struct Node {
    int data;
    Node* left;
    Node* right;
    int height;

    Node(int value) : data(value), left(nullptr), right(nullptr), height(1) {}
};

// AVL Tree class
class AVLTree {
private:
    Node* root;

    // Helper function to get the height of a node
    int getHeight(Node* node) {
        if (node == nullptr)
            return 0;
        return node->height;
    }

    // Helper function to get the balance factor of a node
    int getBalance(Node* node) {
        if (node == nullptr)
            return 0;
        return getHeight(node->left) - getHeight(node->right);
    }

    // Helper function to perform a right rotation
    Node* rightRotate(Node* y) {
        Node* x = y->left;
        Node* T2 = x->right;

        // Perform rotation
        x->right = y;
        y->left = T2;

        // Update heights
        y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
        x->height = max(getHeight(x->left), getHeight(x->right)) + 1;

        return x;
    }

    // Helper function to perform a left rotation
    Node* leftRotate(Node* x) {
        Node* y = x->right;
        Node* T2 = y->left;

        // Perform rotation
        y->left = x;
        x->right = T2;

        // Update heights
        x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
        y->height = max(getHeight(y->left), getHeight(y->right)) + 1;

        return y;
    }

    // Helper function to print the AVL tree in-order
    void inOrderTraversal(Node* node) {
        if (node == nullptr)
            return;

        inOrderTraversal(node->left);
        cout << node->data << " ";
        inOrderTraversal(node->right);
    }

    // Helper function to insert a node into the AVL tree
    Node* insertNode(Node* node, int value) {
        // Perform standard BST insertion
        if (node == nullptr)
            return new Node(value);

        if (value < node->data)
            node->left = insertNode(node->left, value);
        else if (value > node->data)
            node->right = insertNode(node->right, value);
        else // Equal keys not allowed in AVL
            return node;

        // Update height of this ancestor node
        node->height = 1 + max(getHeight(node->left), getHeight(node->right));

        // Get the balance factor to check whether this node became unbalanced
        int balance = getBalance(node);

        // If this node becomes unbalanced, then there are 4 cases

        // Left Left Case
        if (balance > 1 && value < node->left->data)
            return rightRotate(node);

        // Right Right Case
        if (balance < -1 && value > node->right->data)
            return leftRotate(node);

        // Left Right Case
        if (balance > 1 && value > node->left->data) {
            node->left = leftRotate(node->left);
            return rightRotate(node);
        }

        // Right Left Case
        if (balance < -1 && value < node->right->data) {
            node->right = rightRotate(node->right);
            return leftRotate(node);
        }

        // Return the unchanged node pointer
        return node;
    }

    // Helper function to find the node with minimum value in a subtree
    Node* minValueNode(Node* node) {
        Node* current = node;

        // Find the leftmost leaf node
        while (current->left != nullptr)
            current = current->left;

        return current;
    }

    // Helper function to delete a node from the AVL tree
    Node* deleteNode(Node* root, int value) {
        // Perform standard BST deletion
        if (root == nullptr)
            return root;

        // If the value to be deleted is smaller than the root's value, then it lies in the left subtree
        if (value < root->data)
            root->left = deleteNode(root->left, value);

        // If the value to be deleted is greater than the root's value, then it lies in the right subtree
        else if (value > root->data)
            root->right = deleteNode(root->right, value);

        // If the value is the same as root's value, then this is the node to be deleted
        else {
            // Node with only one child or no child
            if ((root->left == nullptr) || (root->right == nullptr)) {
                Node* temp = root->left ? root->left : root->right;

                // No child case
                if (temp == nullptr) {
                    temp = root;
                    root = nullptr;
                } else // One child case
                    *root = *temp; // Copy the contents of the non-empty child

                delete temp;
            } else {
                // Node with two children: Get the inorder successor (smallest in the right subtree)
                Node* temp = minValueNode(root->right);

                // Copy the inorder successor's data to this node
                root->data = temp->data;

                // Delete the inorder successor
                root->right = deleteNode(root->right, temp->data);
            }
        }

        // If the tree had only one node then return
        if (root == nullptr)
            return root;

        // Update height of the current node
        root->height = 1 + max(getHeight(root->left), getHeight(root->right));

        // Get the balance factor to check whether this node became unbalanced
        int balance = getBalance(root);

        // If this node becomes unbalanced, then there are 4 cases

        // Left Left Case
        if (balance > 1 && getBalance(root->left) >= 0)
            return rightRotate(root);

        // Left Right Case
        if (balance > 1 && getBalance(root->left) < 0) {
            root->left = leftRotate(root->left);
            return rightRotate(root);
        }

        // Right Right Case
        if (balance < -1 && getBalance(root->right) <= 0)
            return leftRotate(root);

                // Right Left Case
        if (balance < -1 && getBalance(root->right) > 0) {
            root->right = rightRotate(root->right);
            return leftRotate(root);
        }

        return root;
    }

    // Helper function to print the AVL tree in the specified format
    void printTreeRec(Node* root, const string& prefix, bool isLeft) {
        if (root != nullptr) {
            cout << prefix;
            cout << (isLeft ? "├──" : "└──");
            cout << root->data << endl;

            printTreeRec(root->left, prefix + (isLeft ? "│   " : "    "), true);
            printTreeRec(root->right, prefix + (isLeft ? "│   " : "    "), false);
        }
    }

public:
    // Constructor to initialize the AVL tree
    AVLTree() : root(nullptr) {}

    // Function to insert a value into the AVL tree
    void insert(int value) {
        root = insertNode(root, value);
    }

    // Function to delete a value from the AVL tree
    void remove(int value) {
        root = deleteNode(root, value);
    }

    // Function to print the AVL tree in the specified format
    void printTree() {
        cout << endl;
        cout << "AVL Tree Structure: " << endl;
        printTreeRec(root, "", false);
        cout << endl;
    }

    // Function to perform in-order traversal of the AVL tree
    void inOrderTraversal() {
        inOrderTraversal(root);
    }
};

int main() {
    AVLTree avlTree;

    // Insert some values into the AVL tree
    avlTree.insert(10);
    avlTree.insert(20);
    avlTree.insert(30);
    avlTree.insert(40);
    avlTree.insert(50);
    avlTree.insert(25);
    avlTree.insert(75);

    // Print the AVL tree in the specified format
    avlTree.printTree();

    // Print the AVL tree in-order
    cout << "In-order traversal of AVL tree: ";
    avlTree.inOrderTraversal();
    cout << endl;


    // Delete a value from the AVL tree
    avlTree.remove(30);
    avlTree.remove(50);

    cout << endl << "After deleting value 30 & 50 :";

    // Print the AVL tree after deletion
    avlTree.printTree();

    // Print the AVL tree in-order
    cout << "In-order traversal of AVL tree: ";
    avlTree.inOrderTraversal();
    cout << endl;

    cout << endl;
    return 0;
}

/*
Sample Output:
    AVL Tree Structure: 
    └──30
        ├──20
        │   ├──10
        │   └──25
        └──50
            ├──40
            └──75

    In-order traversal of AVL tree: 10 20 25 30 40 50 75 

    After deleting value 30 & 50 :
    AVL Tree Structure: 
    └──40
        ├──20
        │   ├──10
        │   └──25
        └──75

    In-order traversal of AVL tree: 10 20 25 40 75 
*/