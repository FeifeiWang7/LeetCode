Hi,

Following is my solution in C, this solution gives run time error for input [1] but locally when I run it works perfectly, I am using VC++ 2010, Can anybody please point out what I am missing.

#include<stdio.h>
#include<string.h>
#include<stdlib.h>


#define MAX 100

char **result = NULL;
char tempResult[MAX][MAX];
char path[MAX];
int numPath = 0;

/*struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};*/

/**
* Definition for a binary tree node.
* struct TreeNode {
*     int val;
*     struct TreeNode *left;
*     struct TreeNode *right;
* };
*/
/**
* Return an array of size *returnSize.
* Note: The returned array must be malloced, assume caller calls free().
*/

void display(char *a, int n)
{
    int i = 0;
    while(i <= n)
    {
        printf("%c ",a[i]);
        i++;
    }
    printf("\n");
}

void store(int returnSize)
{
    int i = 0;
    result = (char**)malloc(sizeof(char*)*returnSize);
    if(!result)
    {
        exit(1);
    }
    while(i < returnSize)
    {
        result[i] = (char*)malloc(strlen(tempResult[i])+1);
        if(!result[i])
        {
            exit(1);
        }
        strcpy(result[i], tempResult[i]);
        ++i;
    }
}
void helper(struct TreeNode* root, int index)
{
    if(!root)
    {
        return;
    }
    if(root->left == NULL &&
        root->right == NULL
        )
    {
        path[index] = root->val+'0';
        //display(path, index);
        //store(path, index+1);
        tempResult[numPath][index+1] = '\0';
        strncpy(tempResult[numPath], path, index+1);
        numPath++;
        return;
    }
    path[index] = root->val+'0';
    if(root->left)
    {
        helper(root->left, index+1);
    }
    if(root->right)
    {
        helper(root->right, index+1);
    }
}

char** binaryTreePaths(struct TreeNode* root, int* returnSize) {
    int i;
    helper(root, 0);
    *returnSize = numPath;
    if(*returnSize > 0)
    {
        store(*returnSize);
    }
    numPath = 0;

    /*for(i=0; i<*returnSize; ++i)
        display(result[i], strlen(result[i]));*/
}

/////
HI Everyone: I am solving this problem using C, but I have problem. When the input is [], the OJ expect the output is []. But my output always is [Null]. Can anyone tell me how to fix it??

By the way, what is the meaning of returnSize? I consider it as the number of output strings.

Here are part of my C code, the rest of the code still constructing

 /**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
void PathRecorder(struct TreeNode* root, char** result) {
    if (!root){
        return;
    }
    else if (!root->left && !root->right ){
        result[0] = "1";
    }
    else if (!root->left && root->right){
        result[0] = "2";
    }
    else if (root->left && !root->right){
        result[0] = "3";
    }
    else {
        result[0] = "4";
    }
} 

char** binaryTreePaths(struct TreeNode* root, int* returnSize) {

    char **result = malloc(sizeof(char*));;
    *returnSize = 1;
    PathRecorder(root, result);
    return result;
}
Yes, like the specification says, *returnSize shall be the size of the array, i.e., the number of output strings. You set it to 1, meaning you say there is one element in the array. Input [] means root is null, so you don't do anything and that one element is whatever was in there from malloc, which apparently happens to be a null pointer. To get output [], you need to set *returnSize to 0.
