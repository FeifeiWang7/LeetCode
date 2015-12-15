int missingNumber(int* nums, int numsSize) {
	int sum = n*(n+1)/2;
	int i;
	for(i = 0; i < numsSize; i++)
		sum = sum - nums[i];
	return sum;
}

int missingNumber(int* nums, int n)
{
	int i, result = n;
	for(i = 0; i < n; i ++)
		result = result^(nums[i]^i);
	return result;
}

public int missingNumber(int[] nums) { //binary search
    Arrays.sort(nums);
    int left = 0, right = nums.length, mid= (left + right)/2;
    while(left<right){
        mid = (left + right)/2;
        if(nums[mid]>mid) right = mid;
        else left = mid+1;
    }
    return left;
}
