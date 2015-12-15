#include <stdio.h>
struct TreeNode
{
	int val;
	struct TreeNode *right;
	struct TreeNode *left;
};
struct TreeNode* lowestCommonAncestor(struct TreeNode* root, struct TreeNode* p, struct TreeNode* q) 
{
	if(root == NULL) return NULL;
	while(( root->val - p -> val )	* (root->val - q->val) > 0)
	{
		if(root->val - p -> val > 0) 
		{	
			if(root -> right != NULL)
				root = root -> left;
			else return NULL;
		}
		else 
		{
			if(root->left != NULL)
				root = root -> right;
			else return NULL;
		}	
	}
	return root;
}
int main()
{
	struct TreeNode root,right, left;
	root.val = 6;
	root.right = &right;
	root.left= &left;
	right.val = 2;
	right.right = NULL;
	right.left = NULL;
	left.val = 8;
	left.right = NULL;
	left.left = NULL;
	
	struct TreeNode *tmp = lowestCommonAncestor(&root, &right, &root);
	printf("%d \n", tmp->val);
	return 0;
}
