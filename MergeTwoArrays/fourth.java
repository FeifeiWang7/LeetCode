public void merge(int[] nums1, int m, int[] nums2, int n) {
    int curr1 = m -1, curr2 = n -1, start = m + n-1;
    while (curr1 >= 0 && curr2 >=0){
        if(nums1[curr1] > nums2[curr2]) nums1[start--] = nums1[curr1--];
        else nums1[start--] = nums2[curr2--];
    }
    if(curr1 <= 0) {
        while(curr2>= 0) nums1[start--] = nums2[curr2--];
    }
}
