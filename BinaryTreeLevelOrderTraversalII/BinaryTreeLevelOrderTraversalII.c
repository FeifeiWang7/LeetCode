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
int** levelOrderBottom(struct TreeNode* root, int** columnSizes, int* returnSize) 
{
	if(root == NULL)
        {
                columnSizes = NULL;
                *returnSize = 0;
                return NULL;
        }
        int** result = (int**)malloc(sizeof(int*)*1000);
	int* columnSizes_test  = (int *)malloc(sizeof(int)*1000);
        struct TreeNode **current = (struct TreeNode **)malloc(sizeof(struct TreeNode*) * 1000);
        columnSizes_test[999] = 1;
        result[999] = (int*)malloc(sizeof(int)*(columnSizes_test[999]));
        result[999][0] = root->val;
        current[0] = root;
        int layer = Traversal(result, &columnSizes_test, current, 0);
        *returnSize = layer;
	
	int **result_test = (int **) malloc(sizeof(int*)*layer);
	(*columnSizes) = (int*)malloc(sizeof(int)*layer);
	int i, j;

	for(i = *returnSize, j = 0; i >0; i--, j++)
	{
		(*columnSizes)[j] = columnSizes_test[1000-i];
	}
        for(i = *returnSize, j = 0; i >0 ; i--, j ++)
        {
		result_test[j] = result[999-i+1];
        }
	free(result_test); free(columnSizes_test);
        return result_test;
}
int Traversal(int** result, int **columnSizes, struct TreeNode **current, int layer)
{
        if((*columnSizes)[999-layer] == 0) return layer;
        int i = 0, j = 0;
        result[999 - layer - 1] = (int*)malloc(sizeof(int)*1000);
        struct TreeNode **next = (struct TreeNode **)malloc(sizeof(struct TreeNode *)*1000);
        for(i = 0; i < (*columnSizes)[999 - layer]; i++)
        {
                if(current[i]->left != NULL)
                {
                        result[999 - layer - 1][j] = current[i]->left->val;
                        next[j++] = current[i] -> left;
                }
                if(current[i]->right != NULL)
                {
                        result[999 - layer - 1][j] = current[i]->right->val;
                        next[j++] = current[i] -> right;
                }
        }
        (*columnSizes)[999 - layer - 1] = j;
        free(current);
        return Traversal(result, columnSizes, next, layer+1);
}
int main()
{
        struct TreeNode root, left, right;
        root.val = 1;
        root.left = &left;
        root.right= &right;
	left.val = 5;
	left.left = NULL;
	left.right = NULL;
	right.val = 4;
	right.left = NULL;
	right.right = NULL;
        int* columnSizes;
        int returnSize;
        int **tmp = levelOrderBottom(&root, &columnSizes, &returnSize);
	int i, j;
	for(i = 0; i < returnSize; i++)
	{
		for(j = 0; j < *(columnSizes + i); j ++)
		{
			printf("%d ", tmp[i][j]);
		}
		printf("\n");
	}
}
