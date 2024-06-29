/*****************************************
 * (This comment block is added by the Judge System)
 * Submission ID: 293067
 * Submitted at:  2024-06-24 17:19:27
 *
 * User ID:       1991
 * Username:      57153680
 * Problem ID:    166
 * Problem Name:  Tree Recovery (UVa 536)
 */

#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

// Define a structure for the tree node
struct TreeNode {
    char val;
    TreeNode *left, *right;
    TreeNode(char x) : val(x), left(NULL), right(NULL) {}
};

// Function to build the tree from preorder and inorder traversal
TreeNode* buildTree(string& preorder, int preStart, int preEnd, string& inorder, int inStart, int inEnd, unordered_map<char, int>& inMap) {
    if (preStart > preEnd || inStart > inEnd) return NULL;

    char rootVal = preorder[preStart];
    TreeNode* root = new TreeNode(rootVal);

    int inRoot = inMap[rootVal];
    int numsLeft = inRoot - inStart;

    root->left = buildTree(preorder, preStart + 1, preStart + numsLeft, inorder, inStart, inRoot - 1, inMap);
    root->right = buildTree(preorder, preStart + numsLeft + 1, preEnd, inorder, inRoot + 1, inEnd, inMap);

    return root;
}

// Function to generate the postorder traversal from the tree
void postorderTraversal(TreeNode* root, string& result) {
    if (!root) return;
    postorderTraversal(root->left, result);
    postorderTraversal(root->right, result);
    result += root->val;
}

int main() {
    string preorder, inorder;

    while (cin >> preorder >> inorder) {
        int len = preorder.length();
        unordered_map<char, int> inMap;

        for (int i = 0; i < len; i++) {
            inMap[inorder[i]] = i;
        }

        TreeNode* root = buildTree(preorder, 0, len - 1, inorder, 0, len - 1, inMap);
        
        string result;
        postorderTraversal(root, result);

        cout << result << endl;
    }

    return 0;
}