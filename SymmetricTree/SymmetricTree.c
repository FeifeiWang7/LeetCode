#include <stdio.h>
#include <stdbool.h>
struct TreeNode {
     int val;
     struct TreeNode *left;
     struct TreeNode *right;
};

bool compare(struct TreeNode* root1, struct TreeNode* root2)
{
	if((root1 == NULL) && (root2 == NULL)) 
		return true;
	if((root1 == NULL) || (root2 == NULL)) 
		return false;
	if(root1->val == root2->val)
	{
		if((compare(root1->left, root2->right) == false) || (compare(root1->right, root2->left) == false)) 
			return false;
		else 
			return true;
	}
	else return false;
}
bool isSymmetric(struct TreeNode* root) 
{
	return compare(root, root);
}

int main()
{
	struct TreeNode root, left, right;
	root.val = 1;
	root.left = &left;
	root.right = &right;
	left.val = 2;
	left.right = NULL;
	left.left = NULL;
	right.val = 2;
	right.right = NULL;
	right.left = NULL;
	
	printf(" %d \n", isSymmetric(&root));
}
