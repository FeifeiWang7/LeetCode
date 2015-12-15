int minDepth(struct TreeNode* root) 
{
	if(root == NULL) return 0;
	if((root->left== NULL) && (root->right == NULL)) return 1;
	else if(root->left == NULL) return minDepth(root->right) + 1;
	else if(root->right == NULL) return minDepth(root->left) + 1;
	else
	{
		int l = minDepth(root->left);
		int r = minDepth(root->right);
		return (l < r?l:r ) + 1;
	}
}
