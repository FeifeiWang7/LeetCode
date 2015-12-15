/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int max(int a, int b)
{
	return (a>b)?a:b;
}
int height(struct TreeNode* node)
{
	if(node == NULL) return 0;
	return 1 + max(height(node->left), height(node->right));
}
bool isBalanced(struct TreeNode* root)
{
	if(root == NULL) return true;
	if((abs(height(root->left) - height(root->right)) <=1) && isBalanced(root->left) && isBalanced(root->right))
		return true;
	else return false;
}
