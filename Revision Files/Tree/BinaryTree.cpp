#include <iostream>
#include <string>
using namespace std;

// Introduction of the code:
// This C++ program demonstrates the implementation of a binary tree. 
// It defines a class BinaryTree to represent the binary tree and provides functionalities to insert, search, delete nodes,
// calculate the height, count the number of leaf nodes, compare for equality, and perform traversals (in-order, pre-order, post-order).
// The program includes helper functions for these operations, such as recursive insertion, search, deletion, and traversal.
// In the main function, it creates two binary trees, inserts some values into the first tree, performs operations like traversals,
// search, and deletion, calculates the height and counts the number of leaf nodes of the first tree, inserts values into the second tree,
// and compares the equality of the two trees.

// Define the structure for each node in the binary tree
struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int value) : data(value), left(nullptr), right(nullptr) {}
};

// Define the binary tree class
class BinaryTree {
private:
    TreeNode* root;

    // Helper function to recursively insert a value into the binary tree
    TreeNode* insertRec(TreeNode* root, int value) {
        if (root == nullptr) {
            return new TreeNode(value);
        }

        if (value < root->data) {
            root->left = insertRec(root->left, value);
        } else if (value > root->data) {
            root->right = insertRec(root->right, value);
        }

        return root;
    }

    // Helper function to recursively search for a value in the binary tree
    bool searchRec(TreeNode* root, int value) {
        if (root == nullptr) {
            return false;
        }

        if (root->data == value) {
            return true;
        } else if (value < root->data) {
            return searchRec(root->left, value);
        } else {
            return searchRec(root->right, value);
        }
    }

    // Helper function to find the minimum value node in a binary tree
    TreeNode* findMin(TreeNode* root) {
        while (root->left != nullptr) {
            root = root->left;
        }
        return root;
    }

    // Helper function to recursively delete a value from the binary tree
    TreeNode* deleteRec(TreeNode* root, int value) {
        if (root == nullptr) {
            return root;
        }

        if (value < root->data) {
            root->left = deleteRec(root->left, value);
        } else if (value > root->data) {
            root->right = deleteRec(root->right, value);
        } else {
            // Case 1: No child or only one child
            if (root->left == nullptr) {
                TreeNode* temp = root->right;
                delete root;
                return temp;
            } else if (root->right == nullptr) {
                TreeNode* temp = root->left;
                delete root;
                return temp;
            }

            // Case 2: Two children
            TreeNode* temp = findMin(root->right);
            root->data = temp->data;
            root->right = deleteRec(root->right, temp->data);
        }
        return root;
    }

    // Helper function to recursively calculate the height of a binary tree
    int heightRec(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }

        int leftHeight = heightRec(root->left);
        int rightHeight = heightRec(root->right);

        return 1 + max(leftHeight, rightHeight);
    }

    // Helper function to recursively count the number of leaf nodes in a binary tree
    int countLeavesRec(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }

        if (root->left == nullptr && root->right == nullptr) {
            return 1;
        }

        return countLeavesRec(root->left) + countLeavesRec(root->right);
    }

    // Helper function to recursively compare two binary trees for equality
    bool equalRec(TreeNode* root1, TreeNode* root2) {
        if (root1 == nullptr && root2 == nullptr) {
            return true;
        }

        if (root1 != nullptr && root2 != nullptr) {
            return (root1->data == root2->data) && equalRec(root1->left, root2->left) && equalRec(root1->right, root2->right);
        }

        return false;
    }

    // Helper function to print the binary tree in the specified format
    void printTreeRec(TreeNode* root, const string& prefix, bool isLeft) {
        if (root != nullptr) {
            cout << prefix;
            cout << (isLeft ? "├──" : "└──");
            cout << root->data << endl;

            printTreeRec(root->left, prefix + (isLeft ? "│   " : "    "), true);
            printTreeRec(root->right, prefix + (isLeft ? "│   " : "    "), false);
        }
    }

public:
    // Constructor to initialize the binary tree
    BinaryTree() : root(nullptr) {}

    // Function to insert a value into the binary tree
    void insert(int value) {
        root = insertRec(root, value);
    }

    // Function to search for a value in the binary tree
    bool search(int value) {
        return searchRec(root, value);
    }

    // Function to delete a value from the binary tree
    void remove(int value) {
        root = deleteRec(root, value);
    }

    // Function to calculate the height of the binary tree
    int height() {
        return heightRec(root);
    }

    // Function to count the number of leaf nodes in the binary tree
    int countLeaves() {
        return countLeavesRec(root);
    }

    // Function to compare two binary trees for equality
    bool equal(BinaryTree& otherTree) {
        return equalRec(root, otherTree.root);
    }

    // Function to perform in-order traversal of the binary tree
    void inOrderTraversal() {
        cout << "In-order traversal: ";
        inOrderRec(root);
        cout << endl;
    }

    // Function to perform pre-order traversal of the binary tree
    void preOrderTraversal() {
        cout << "Pre-order traversal: ";
        preOrderRec(root);
        cout << endl;
    }

    // Function to perform post-order traversal of the binary tree
    void postOrderTraversal() {
        cout << "Post-order traversal: ";
        postOrderRec(root);
        cout << endl;
    }

    // Function to print the binary tree in the specified format
    void printTree() {
        cout << endl;
        cout << "Tree Structure: " << endl;
        printTreeRec(root, "", false);
        cout << endl;
    }

private:
    // Helper function for in-order traversal
    void inOrderRec(TreeNode* root) {
        if (root != nullptr) {
            inOrderRec(root->left);
            cout << root->data << " ";
            inOrderRec(root->right);
        }
    }

    // Helper function for pre-order traversal
    void preOrderRec(TreeNode* root) {
        if (root != nullptr) {
            cout << root->data << " ";
            preOrderRec(root->left);
            preOrderRec(root->right);
        }
    }

    // Helper function for post-order traversal
    void postOrderRec(TreeNode* root) {
        if (root != nullptr) {
            postOrderRec(root->left);
            postOrderRec(root->right);
            cout << root->data << " ";
        }
    }
};

int main() {
    BinaryTree tree1;
    BinaryTree tree2;

    cout << endl;

    // Insert some values into the first binary tree
    tree1.insert(50);
    tree1.insert(30);
    tree1.insert(70);
    tree1.insert(20);
    tree1.insert(40);

    // Print the binary tree in the specified format
    cout << "Tree 01:" << endl;
    tree1.printTree();

     // Perform traversals
    tree1.inOrderTraversal();
    tree1.preOrderTraversal();
    tree1.postOrderTraversal();

    // Search for a value
    cout << "Search for value 40: " << (tree1.search(40) ? "Found" : "Not found") << endl;

    // Delete a value
    tree1.remove(30);
    cout << endl << "After deleting value 30:\n";

    // Print the binary tree in the specified format
    tree1.printTree();

    // Perform traversals
    tree1.inOrderTraversal();
    tree1.preOrderTraversal();
    tree1.postOrderTraversal();

    // Print the height of the first binary tree
    cout << "Height of Binary Tree 1: " << tree1.height() << endl;

    // Count the number of leaf nodes in the second binary tree
    cout << "Number of leaf nodes in Binary Tree 1: " << tree1.countLeaves() << endl;

    // Insert some values into the second binary tree
    tree2.insert(50);
    tree2.insert(30);
    tree2.insert(70);
    tree2.insert(20);
    tree2.insert(40);

    // Print the binary tree in the specified format
    cout << endl << "Tree 02:" << endl;
    tree2.printTree();

    // Print the height of the first binary tree
    cout << "Height of Binary Tree 2: " << tree2.height() << endl;

    // Count the number of leaf nodes in the second binary tree
    cout << "Number of leaf nodes in Binary Tree 2: " << tree2.countLeaves() << endl;

    // Compare the two binary trees for equality
    cout << "Binary Tree 1 and Binary Tree 2 are " << (tree1.equal(tree2) ? "equal." : "not equal.") << endl;

    cout << endl;
    return 0;
}

/*
Sample Output:
    Tree 01:

    Tree Structure: 
    └──50
        ├──30
        │   ├──20
        │   └──40
        └──70

    In-order traversal: 20 30 40 50 70 
    Pre-order traversal: 50 30 20 40 70 
    Post-order traversal: 20 40 30 70 50 
    Search for value 40: Found

    After deleting value 30:

    Tree Structure: 
    └──50
        ├──40
        │   ├──20
        └──70

    In-order traversal: 20 40 50 70 
    Pre-order traversal: 50 40 20 70 
    Post-order traversal: 20 40 70 50 
    Height of Binary Tree 1: 3
    Number of leaf nodes in Binary Tree 1: 2

    Tree 02:

    Tree Structure: 
    └──50
        ├──30
        │   ├──20
        │   └──40
        └──70

    Height of Binary Tree 2: 3
    Number of leaf nodes in Binary Tree 2: 3
    Binary Tree 1 and Binary Tree 2 are not equal.
*/