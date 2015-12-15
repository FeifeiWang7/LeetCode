struct TreeNode* invertTree(struct TreeNode* root) {
	if(root == NULL) return root;
	struct TreeNode *tmp;
	tmp = root->right;
	root->right = root->left;
	root->left = tmp;
	if(root->right != NULL) invertTree(root->right);
	if(root->left != NULL) invertTree(root->left);
	return root;   
}
