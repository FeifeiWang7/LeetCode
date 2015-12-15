int QuickSort(int a[], int left, int right)
{
    if (left < right)
    {
        int i = left, j = right, p = a[i];
        while (i < j)
        {
            while (i < j && p < a[j])
                j--;
            if (i < j)
                a[i++] = a[j];

            while (i < j && p > a[i])
                i++;
            if (i < j)
                a[j--] = a[i];
        }
        a[i] = p;

        QuickSort(a, left, i - 1);
        QuickSort(a, i + 1, right);
    }
}
int majorityElement(int* nums, int numsSize)
{       
        QuickSort(nums,0,numsSize-1);

        int count = 1, i; int element = nums[0];
        for(i = 0; i < numsSize-1; i++)
        {
                element = nums[i];
                if(nums[i] == nums[i+1]) count ++;
                else
                {
                        if( count > numsSize/2) return element;
                        else count = 1;
                }
        }
        return element;
}

