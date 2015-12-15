#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int cmpfunc (const void * a, const void * b)
{
   return ( *(int*)a - *(int*)b );
}
int** subsets(int* nums, int numsSize, int** columnSizes, int* returnSize) {
    qsort(nums, numsSize, sizeof(int), cmpfunc);
    *returnSize = pow(2, numsSize);
    *columnSizes = (int*) malloc(sizeof(int) *(*returnSize));
    int **result = (int**) malloc(sizeof(int*)*(*returnSize));
    (*columnSizes)[0] = 0;
    result[0] = (int*)malloc(sizeof(int));
    int sentinent = 1;
    for(int i = 0; i < numsSize; i++)
    {
        int mark = sentinent;
        for(int j = 0; j < sentinent; j++, mark++)
        {
            (*columnSizes)[mark] = (*columnSizes)[j] + 1;

            result[mark] = (int*) malloc(sizeof(int) * (*columnSizes)[mark]);
            for(int k = 0; k < (*columnSizes)[j]; k++)
                result[mark][k] = result[j][k];
            result[mark][(*columnSizes)[j]] = nums[i];
        }
        sentinent = mark;
    }
    return result;
}
int main()
{
	int a[2] = {3,9};
	int *columnSizes;
	int returnSize;
	int ** result;
	result = subsets(a, 2, &columnSizes, &returnSize);
	for(int i = 0; i < returnSize; i++)
	{
		for(int j = 0; j < columnSizes[i]; j++)
			printf("%d ", result[i][j]);
		printf("\n");
	}
	return 0;
}
