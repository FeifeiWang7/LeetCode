void moveZeroes(int* nums, int numsSize) 
{
	int num, zero, tmp;
	for( num = 0, zero = 0;  (num <numsSize)&&(zero<numsSize) ;)
	{
		while((nums[num] == 0) && (num < numsSize)) num++;
		while((nums[zero] != 0) && (zero < numsSize)) zero++;
		if((nums[num] != 0) && (nums[zero] == 0))
		{
			tmp = nums[num];
			nums[num] = nums[zero];
			nums[zero] = tmp;
		}
	} 
}
