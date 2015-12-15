void rotate(int* nums, int numsSize, int k) 
{
	int *tmp = (int*)malloc(sizeof(int)*numsSize);
	int i;
	for(i = 0; i < numsSize; i++)
        {
		tmp[(i+k)%numsSize] = nums[i];
        }
	memcpy(nums, tmp, sizeof(int)*numsSize);
	free(tmp);
}

