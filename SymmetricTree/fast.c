bool check(struct TreeNode *node1, struct TreeNode *node2){

    if(!node1 && !node2) return true;

    if(!(node1 && node2)) return false;

    return (node1->val == node2->val)
        && check(node1->right, node2->left)
        && check(node1->left, node2->right);
} 

bool isSymmetric(struct TreeNode* root) {
    if(!root) return true;
    return check(root->left, root->right);
}
