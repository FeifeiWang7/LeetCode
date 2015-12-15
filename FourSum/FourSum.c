void QuickSort(int a[], int left, int right)
{
        if(left < right)
        {
                int i = left, j = right, p = a[i];
                while(i < j)
                {
                        while(i < j && p < a[j]) j--;
                        if(i < j) a[i++] = a[j];
                        while(i < j && p > a[i]) i++;
                        if(i < j) a[j--] = a[i];
                }
                a[i] = p;
                QuickSort(a, left, i-1);
                QuickSort(a, i+1, right);
        }
}
int** fourSum(int* nums, int numsSize, int target, int* returnSize) {
        QuickSort(nums, 0, numsSize-1);
        int **result = (int **)malloc(sizeof(int*)*1000); int i, j, k = 0;
        for(i = 0; i < numsSize; i++)
        {
		if(! (i == 0 || i > 0 && nums[i] != nums[i-1])) continue;
		for(j = i + 1; j < numsSize; j++)
		{
			if(nums[j] == nums[j-1] && j-1 != i) continue;
                	int remain = target - nums[i] - nums[j];
			if(remain > target/2) break; ////
                	int head = j + 1, rear = numsSize-1;
                	while(head < rear)
                	{
                        	if(nums[head] + nums[rear] == remain)
                        	{
                                	if(k == 0)
                                	{
                                    		result[k] = (int *)malloc(sizeof(int) * 4);
                                    		result[k][0] = nums[i];
                                    		result[k][1] = nums[j];
                                    		result[k][2] = nums[head];
                                    		result[k][3] = nums[rear];
                                    		k++;
                                    		head++;
                                	}
                                	else
                                	{
                                    		if(nums[i] == result[k-1][0] && nums[j] == result[k-1][1] && nums[head] == result[k-1][2]) head++;
                                    		else
                                    		{
                                        		result[k] = (int *)malloc(sizeof(int) * 3);
                                        		result[k][0] = nums[i];
                                        		result[k][1] = nums[j];
                                        		result[k][2] = nums[head];
                                        		result[k][3] = nums[rear];
                                        		k++;
                                        		head++;
                                    		}
                                	}
                        	}
                        	else if(nums[head] + nums[rear] > remain) rear--;
                        	else head++;
                	}
        	}
	}
        *returnSize = k;
        return result;
}
