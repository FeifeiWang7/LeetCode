int kthMin(int* nums1, int nums1Size, int* nums2, int nums2Size, int k)
{
    if(nums1Size <= 0) return nums2[k-1];
    int l= 0, r = nums1Size-1, mid;
    while(1)
    {
        if(l+r >= 0) mid = (l+r+1)/2;
        else mid = (l + r - 1 )/2;
        //  mid, k-mid-2
        int a = k-mid-1 >= nums2Size ? INT_MAX : nums2[k-mid-1];
            a = k-mid-1 < 0 ? INT_MIN: a;
        int b = mid+1 >= nums1Size ? INT_MAX : nums1[mid+1];
            b = mid+1 < 0 ? INT_MIN: b;
        int c = k-mid-2 >= nums2Size ? INT_MAX : nums2[k-mid-2];
            c = k-mid-2 < 0 ? INT_MIN: c;
        if(nums1[mid] > a) r = mid -1;
        else if(b < c) l = mid + 1;
        else 
        {
            int ret = nums1[mid] > nums2[k-mid-2] ? nums1[mid] : nums2[k-mid-2];
            printf("%d\n",ret);
            return ret;
        }
    }
}
double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size)
{
        if(nums1Size > nums2Size) findMedianSortedArrays(nums2, nums2Size, nums1, nums1Size);
        int size = nums1Size + nums2Size;
        if(size & 1)
                return kthMin(nums1, nums1Size, nums2, nums2Size, size/2+1);
        else return (0.0 + kthMin(nums1, nums1Size, nums2, nums2Size, size/2) + kthMin(nums1, nums1Size, nums2, nums2Size, (size/2)+1))*0.5;
}
