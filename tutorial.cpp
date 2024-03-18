bool isMirror(Node* root1, Node* root2) {
    if (root1 == NULL) && (root2 == NULL){
        return true;
    }

    if (root1 == NULL) || (root2 == NULL){
        return false;
    }

    if(root1->key != root2->key){
        return false;
    }

    leftSubtreeIsMirror = isMirror(root1->left, root2->right)
    rightSubtreeIsMirror = isMirror(root1->right, root2->left)

    return leftSubtreeIsMirror and rightSubtreeIsMirror;

}


bool isSumEqual(Node* node) {
    if (node == NULL){
        return true;
    }
    
    int leftvalue, rightvalue; 

    if (node->left != NULL) {
        leftvalue = node->left->key;
    } else {
        leftvalue = 0;
    }

    if (node->right != NULL) {
        rightvalue = node->right->key;
    } else {
        rightvalue = 0;
    }

    if (node->key == (leftvalue + rightvalue) &&
        isSumEqual(node->left) &&
        isSumEqual(node->right)) {
        return true;
    }

    return false;
}