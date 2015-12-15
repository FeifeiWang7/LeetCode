#include <stdio.h>
#include <stdlib.h>
struct TreeNode {
     int val;
     struct TreeNode *left;
     struct TreeNode *right;
};
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *columnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** levelOrder(struct TreeNode* root, int** columnSizes, int* returnSize) 
{
	if(root == NULL)
	{
		columnSizes = NULL;
		*returnSize = 0;
		return NULL;
	}
	int** result = (int**)malloc(sizeof(int*)*1000);	   
	(*columnSizes) = (int *)malloc(sizeof(int)*1000);
	struct TreeNode **current = (struct TreeNode **)malloc(sizeof(struct TreeNode*) * 1000);
	(*columnSizes)[0] = 1;
	result[0] = (int*)malloc(sizeof(int)*((*columnSizes)[0]));
	result[0][0] = root->val;
	current[0] = root;
	int layer = Traversal(result, columnSizes, current, 0);
	*returnSize = layer;
	return result;
}

int Traversal(int** result, int **columnSizes, struct TreeNode **current, int layer)
{	
	if((*columnSizes)[layer] == 0) return layer;
	int i = 0, j = 0;
	result[layer+1] = (int*)malloc(sizeof(int)*1000);
	struct TreeNode **next = (struct TreeNode **)malloc(sizeof(struct TreeNode *)*1000);
	for(i = 0; i < (*columnSizes)[layer]; i++)
	{
		if(current[i]->left != NULL)
		{
			result[layer+1][j] = current[i]->left->val;	
			next[j++] = current[i] -> left;
		} 
		if(current[i]->right != NULL)
		{
			result[layer+1][j] = current[i]->right->val;	
			next[j++] = current[i] -> right;
		} 
	}
	(*columnSizes)[layer+1] = j;
	free(current);
	return Traversal(result, columnSizes, next, layer+1);
}
int main()
{	
	struct TreeNode root;
	root.val = 3;
	root.left = NULL;
	root.right=NULL;
	int* columnSizes;
	int returnSize;
	levelOrder(&root, &columnSizes, &returnSize);
}

