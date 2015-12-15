int rob(int* nums, int numsSize) 
{
	int result[numsSize]; 
	int i;
	result[0] = nums[0];
	result[1] = nums[0] > nums[1] ? nums[0] : nums[1];
	for(i = 2; i < numsSize; i++)
	{
		int a = nums[i] + result[i-2];
		int b = result[i-1];
		result[i] = a > b ? a : b;
	}  
	return result[numsSize - 1];
}
