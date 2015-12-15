/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

int checkBalanceAndDepth(struct TreeNode* node, bool *isBalanced)
{
    int leftDepth = node->left == NULL? 0 : checkBalanceAndDepth(node->left, isBalanced);
    if(!*isBalanced)
    {
        return -1;
    }
    int rightDepth = node->right == NULL? 0 :checkBalanceAndDepth(node->right, isBalanced);
    if(!*isBalanced)
    {
        return -1;
    }
    int diff = leftDepth - rightDepth;
    *isBalanced = (diff == -1 || diff == 0 || diff == 1);
    return leftDepth > rightDepth? leftDepth + 1 : rightDepth + 1;
}
bool isBalanced(struct TreeNode* root) {
    if(root == NULL) return true;
    bool balanced = true;
    checkBalanceAndDepth(root, &balanced);
    return balanced;
}
