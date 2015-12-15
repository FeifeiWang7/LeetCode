///
#define SIZE 3000
struct stackT
{
	int *contents;
	int top;
	int maxSize;
};
void StackInit(struct stackT *stackP, int maxSize)
{
	stackP->contents = (int *)malloc(sizeof(int)*maxSize);
	stackP->maxSize = maxSize;
	stackP->top = -1;	
}
void StackDestroy(struct stackT *stackP)
{
	free(stackP->contents);
	stackP->maxSize = 0;
	stackP->top = -1;
}
int StackIsEmpty(struct stackT *stackP)
{
	return stackP->top<0;
}
int StackIsFull(struct stackT *stackP)
{
	return stackP->top >= stackP->maxSize -1;
}
void StackPush(struct stackT *stackP, int element)
{
	if(StackIsFull(stackP)) exit(1);
	stackP->contents[++stackP->top] = element;
}
int StackPop(struct stackT *stackP)
{
	if(StackIsEmpty(stackP)) exit(1);
	return stackP->contents[stackP->top--];
}
struct stackT path;
int count; // cannot use static here as count is not cleared for each test case.
int dfs(struct TreeNode *root, char** result)
{
	if(root == NULL) return 0;
	
	StackPush(&path, root->val);
	if(root->left != NULL) dfs(root->left, result);
	if(root->right != NULL) dfs(root -> right, result);
	
	if((root->left == NULL) && (root->right == NULL))
	{
	    result[count] = (char*)malloc(sizeof(char)*SIZE); //sprintf uses buffer, so must be allocated first
		int j = 0; int i = 0;
		for(j = 0; j < path.top; j++)
		{
			i = i + sprintf(result[count]+ i, "%d->",path.contents[j]);
		}
		sprintf(result[count]+i, "%d", path.contents[j]); 
		StackPop(&path);
		count++;
	}
	else StackPop(&path);
	return count;
}
char** binaryTreePaths(struct TreeNode* root, int* returnSize) 
{
    count = 0;
	StackInit(&path, SIZE);
    char **result = (char**)malloc(sizeof(char*)*SIZE);
	*returnSize = dfs(root, result);
	StackDestroy(&path);
	return result;
}
//////////
/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
#include <stdio.h>
#include <stdlib.h>
#define SIZE 1000
struct TreeNode {
     int val;
     struct TreeNode *left;
     struct TreeNode *right;
};
struct stackT
{
	int *contents;
	int top;
	int maxSize;
};
void StackInit(struct stackT *stackP, int maxSize)
{
	stackP->contents = (int *)malloc(sizeof(int)*maxSize);
	stackP->maxSize = maxSize;
	stackP->top = -1;	
}
void StackDestroy(struct stackT *stackP)
{
	free(stackP->contents);
	stackP->maxSize = 0;
	stackP->top = -1;
}
int StackIsEmpty(struct stackT *stackP)
{
	return stackP->top<0;
}
int StackIsFull(struct stackT *stackP)
{
	return stackP->top >= stackP->maxSize -1;
}
void StackPush(struct stackT *stackP, int element)
{
	if(StackIsFull(stackP)) exit(1);
	stackP->contents[++stackP->top] = element;
}
int StackPop(struct stackT *stackP)
{
	if(StackIsEmpty(stackP)) exit(1);
	return stackP->contents[stackP->top--];
}
struct stackT path;
int dfs(struct TreeNode *root, char** result)
{
	static int count = 0;
	if(root == NULL) return 0;
	
	StackPush(&path, root->val);
	if(root->left != NULL) dfs(root->left, result);
	if(root->right != NULL) dfs(root -> right, result);
	
	if((root->left == NULL) && (root->right == NULL))
	{
		count++;
		int j = 0;
		for(j = 0; j < path.top; j++)
		{
			sprintf(result[count], "%d->",path.contents[j]);
		}
		sprintf(result[count]+j-1, "%d", path.contents[j]);
		StackPop(&path);
	}
	else StackPop(&path);
}
char** binaryTreePaths(struct TreeNode* root, int* returnSize) 
{
	StackInit(&path, SIZE);
	char **result = (char**)malloc(sizeof(char*)*SIZE);
	*returnSize = dfs(root, result);
	StackDestroy(&path);
	return result;
}
int main()
{
	struct TreeNode root, right, left;
	root.val = 1;
	root.right = &right;
	root.left = &left;
	left.val = 2;
	left.right = NULL;
	left.left = NULL;
	right.val = 3;
	right.right = NULL;
	right.left = NULL;
	//dfs(&root);
	return 0;
}

