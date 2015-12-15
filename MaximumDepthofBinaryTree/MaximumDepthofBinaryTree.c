/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int maxDepth(struct TreeNode* root) 
{
	if(root == NULL) return 0;
	int left, right;
	if((root->left == NULL) && (root->right == NULL)) return 1;
	if(root->left != NULL)
		left = maxDepth(root->left);
	else left = 0;
	if(root->right != NULL)
		right = maxDepth(root->right);
	else right = 0;
	return left>right?left+1:right+1;
}
