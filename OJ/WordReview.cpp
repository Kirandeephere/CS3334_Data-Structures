#include <iostream>
#include <string>
#include <sstream>

using namespace std;

struct Node {
    string data;
    Node* left;
    Node* right;

    Node(const string& data) : data(data), left(nullptr), right(nullptr) {}
};

class BST {
private:
    Node* root;

    Node* insert(Node* node, const string& data) {
        if (!node) {
            return new Node(data);
        }

        if (data < node->data) {
            node->left = insert(node->left, data);
        } else if (data > node->data) {
            node->right = insert(node->right, data);
        }

        return node;
    }

    bool search(Node* node, const string& data) {
        if (!node) {
            return false;
        }

        if (node->data == data) {
            return true;
        } else if (data < node->data) {
            return search(node->left, data);
        } else {
            return search(node->right, data);
        }
    }

public:
    BST() : root(nullptr) {}

    void insert(const string& data) {
        root = insert(root, data);
    }

    bool search(const string& data) {
        return search(root, data);
    }
};

int main() {
    string line;
    
    while (getline(cin, line)) {
        if (line.empty()) {
            continue; // skip empty lines
        }

        stringstream ss(line);
        int n, m;
        
        ss >> n;

        BST bst;

        for (int i = 0; i < n; ++i) {
            string word;
            getline(cin, word);
            bst.insert(word);
        }

        getline(cin, line);
        ss.clear();
        ss.str(line);
        
        ss >> m;

        int count = 0;
        int totalLength = 0;
        bool firstMatch = true;
    
        for (int i = 0; i < m; ++i) {
            string word;
            getline(cin, word);
        
            if (bst.search(word)) {
                ++count;
                if (firstMatch) {
                    firstMatch = false;
                } else {
                    totalLength += word.length();
                }
            }
        }

        if (totalLength != 0) {
            totalLength += 2;
        }

        cout << count << endl;
        cout << totalLength << endl;
    }

    return 0;
}

