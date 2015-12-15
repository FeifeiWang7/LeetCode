#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int *QuickSort(int a[], int left, int right)
{
	if(left < right)
	{
		int i = left, j = right, p = a[i];
		while(i < j)
		{
			while(i < j && a[j] > p) j--;
			if(i < j) a[i++] = a[j];
			while(i < j && a[i] < p) i++;
			if(i < j) a[j--] = a[i];
		}
		a[i] = p;
		QuickSort(a, left, i-1);
		QuickSort(a, i+1, right);
	}
	return a;
}
int* twoSum(int* nums, int numsSize, int target)
{
        int *tmp = (int*)malloc(sizeof(int)*numsSize);
        memcpy(tmp, nums, sizeof(int)*numsSize);
        int *result = (int*)malloc(sizeof(int)*2);
        QuickSort(nums, 0, numsSize-1);
        int i, j;
        for( i = 0; i < numsSize; i++)
        {
                for(j = i + 1; j < numsSize; j++)
                {
                        if(nums[j] + nums[i] == target) break;
                }
                if(nums[j] + nums[i] == target) break;
        }
        int k; int flag = 0;
        for(k = 0; k < numsSize; k++)
        {
                int value;
                if((tmp[k] == nums[i] || tmp[k] == nums[j]) &&  !flag)
                {
                        result[0] = k + 1;
                        flag = 1;
                        value = target - tmp[k];
                        continue;
                }
                if((tmp[k] == value)&& flag)
                {
                        result[1] = k + 1;
                        break;
                }
        }
        return result;
}
//shorter
int* twoSum(int* nums, int numsSize, int target)
{
        int *tmp = (int*)malloc(sizeof(int)*numsSize); int i, j;
        for(i = 0; i < numsSize; i++) tmp[i] = nums[i];
        int *result = (int*)malloc(sizeof(int)*2);
        QuickSort(nums, 0, numsSize-1);
        for( i = 0, j = numsSize - 1; i < j;)
        {
                if(nums[j] + nums[i] == target) break;
                if(nums[j] + nums[i] > target) j--;
                if(nums[j] + nums[i] < target) i++;
        }
        int pos = 0;
        for(int k = 0; k < numsSize; k++)
        {
                if(tmp[k] == nums[i] || tmp[k] == nums[j])
                    result[pos++] = k + 1;
        }
        return result;
}
///////hash map
typedef int hashKeyT;
typedef int hashValueT;
typedef struct 
{
	hashKeyT key;
	hashValueT value;
	UT_hash_handle hh;
}hashEntryT;
int* twoSum(int* nums, int numsSize, int target)
{
	int *result = (int *)malloc(sizeof(int)*2);
	hashEntryT *hashMap = NULL;
	int i;
	for(i = 0; i < numsSize; i++)
	{
		int remain = target - nums[i];
		hashEntryT *s;
		HASH_FIND(hh, hashMap, &remain, sizeof(hashKeyT), s);
		if(s == NULL)
		{
			s = (hashEntryT *)malloc(sizeof(hashEntryT));
			s -> key = nums[i];
			s -> value = i;
			HASH_ADD(hh, hashMap, key, sizeof(hashKeyT), s);
		}
		else
		{
			result[0] = s->value + 1;
			result[1] = i + 1;
			return result;
		}
	}
}
int main()
{
	int a[5] = {-1, -2, -3, -4, -5};
	int *b = twoSum(a, 5, -8);
	printf("%d %d\n",b[0],b[1]);
}
