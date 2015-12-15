int majorityElement(int* nums, int numsSize) 
{
	int i,j,k,count=0;
    	j=nums[0];
	for(i=0;i<numsSize;i++)
	{
    		if(count==0)
    			j=nums[i];
    		if(nums[i]==j)
    			count++;
    		else
    			count--;
	}
	return j;
}
