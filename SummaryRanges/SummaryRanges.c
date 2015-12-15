char** summaryRanges(int* nums, int numsSize, int* returnSize) {
        char **result = (char **)malloc(sizeof(char*)*numsSize);
        int i, j = 0;
        for(i = 0; i < numsSize;i++ )
        {
                result[j] = (char *)malloc(sizeof(char)*15);
                int start = nums[i];

                while( ((i+1) < numsSize) && (nums[i+1] == nums[i] + 1)) i++;
                if((nums[i] - start == 0))
                {
			sprintf(result[j], "%d", start);
                        j++;
                }
                else
                {
			sprintf(result[j], "%d->%d", start, nums[i]);
                        j++;
                }
        }
        *returnSize = j;
        return result;
}

//// My first soluiton below only works for positive 个位数 I should use sprintf instead
/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
char** summaryRanges(int* nums, int numsSize, int* returnSize) {
	char **result = (char **)malloc(sizeof(char*)*numsSize);
	int i, j = 0;
	for(i = 0; i < numsSize;i++ )
	{
		result[j] = (char *)malloc(sizeof(char)*6);
		result[j][0] = nums[i] + '0' - 0; 
	
		while( ((i+1) < numsSize) && (nums[i+1] == nums[i] + 1)) i++;
		if((nums[i] + '0' - 0  - result[j][0]) == 0)
		{
			result[j][1] = '\0';
			j++;
		}
		else
		{
			result[j][1] = '-';
			result[j][2] = '>';
			result[j][3] = nums[i] + '0' - 0;
			result[j][4] = '\0';
			j++;
		}
	}	
	*returnSize = j;
	return result;  
}
int main()
{
	int a[6] = {0,1,2,4,5,7};
	int size;
	char **result = summaryRanges(a, 6, &size);
	int i; char *p;
	for(i = 0; i < size; i++)
	{
		p = result[i];
///		while( *p != '\0') printf("%c",*p);
//		printf("\n");
	}
	return 0;
}
