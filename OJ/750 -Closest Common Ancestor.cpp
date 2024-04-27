#include <iostream>

using namespace std;

struct TreeNode {
    int value;
    TreeNode* parent;
    TreeNode* left;
    TreeNode* right;
    
    TreeNode(int val) : value(val), parent(NULL), left(NULL), right(NULL) {}
};

TreeNode* findCommonAncestor(TreeNode* node1, TreeNode* node2) {
    int depth1 = 0, depth2 = 0;
    
    // Calculate depth of node1
    TreeNode* temp1 = node1;
    while (temp1->parent) {
        temp1 = temp1->parent;
        depth1++;
    }
    
    // Calculate depth of node2
    TreeNode* temp2 = node2;
    while (temp2->parent) {
        temp2 = temp2->parent;
        depth2++;
    }
    
    // Move up to the same depth
    while (depth1 > depth2) {
        node1 = node1->parent;
        depth1--;
    }
    
    while (depth2 > depth1) {
        node2 = node2->parent;
        depth2--;
    }
    
    // Move up together until common ancestor is found
    while (node1 != node2) {
        node1 = node1->parent;
        node2 = node2->parent;
    }
    
    return node1;
}

int main() {
    int T;
    cin >> T;
    
    while (T--) {
        int rootValue, N;
        cin >> rootValue >> N;
        
        TreeNode* root = new TreeNode(rootValue);
        TreeNode* nodes[N + 1];
        nodes[rootValue] = root;
        
        // Build the tree
        for (int i = 0; i < N - 1; ++i) {
            int member, parent;
            cin >> member >> parent;
            
            TreeNode* newNode = new TreeNode(member);
            nodes[member] = newNode;
            
            if (nodes[parent]->left == NULL) {
                nodes[parent]->left = newNode;
            } else {
                nodes[parent]->right = newNode;
            }
            
            newNode->parent = nodes[parent];
        }
        
        int member1, member2;
        cin >> member1 >> member2;
        
        TreeNode* commonAncestor = findCommonAncestor(nodes[member1], nodes[member2]);
        
        cout << commonAncestor->value << endl;
        
        // Clean up
        for (int i = 1; i <= N; ++i) {
            delete nodes[i];
        }
    }
    
    return 0;
}