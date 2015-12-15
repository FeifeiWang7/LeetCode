#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int cmpfunc (const void * a, const void * b)
{
   return ( *(int*)a - *(int*)b );
}
int** subsetsWithDup(int* nums, int numsSize, int** columnSizes, int* returnSize) {
    qsort(nums, numsSize, sizeof(int), cmpfunc);
    *returnSize = pow(2, numsSize);
    *columnSizes = (int*) malloc(sizeof(int) *(*returnSize));
    int **result = (int**) malloc(sizeof(int*)*(*returnSize));
    (*columnSizes)[0] = 0;
    result[0] = (int*)malloc(sizeof(int));
    int sentinent = 1;
    for(int i = 0; i < numsSize;i++)
    {
	int count = 1;
	while((i+1 < numsSize) && (nums[i] == nums[i+1])) 
	{
		count++;
		i++;
	}
        int mark = sentinent;
        for(int j = 0; j < sentinent; j++)
        {
		int tmp = count;
		while(tmp)
		{
            		(*columnSizes)[mark] = (*columnSizes)[j] + tmp;
            		result[mark] = (int*) malloc(sizeof(int) * (*columnSizes)[mark]);
			int k;
            		for(k = 0; k < (*columnSizes)[j]; k++)
                		result[mark][k] = result[j][k];
			for(; k < (*columnSizes)[mark]; k++)
				result[mark][k] = nums[i];
	    		mark++; tmp--;
		}
        }
        sentinent = mark;
    }
    *returnSize = sentinent;
    return result;
}
int main()
{
	int a[3] = {0,2,2};
	int *columnSizes;
	int returnSize;
	int ** result;
	result = subsetsWithDup(a, 3, &columnSizes, &returnSize);
	for(int i = 0; i < returnSize; i++)
	{
		for(int j = 0; j < columnSizes[i]; j++)
			printf("%d ", result[i][j]);
		printf("\n");
	}
	return 0;
}
