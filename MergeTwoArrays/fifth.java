/*
* Similar with merge sorted linked list but insert from the end in this problem.
* The end is actually the last item position m+n-1, not the last item in nums1[].
*/
public void merge(int[] nums1, int m, int[] nums2, int n) {
    int index=m+n-1, i=m-1, j=n-1;
    while(i>=0 || j>=0){
        if(i>=0 && j>=0){
            nums1[index--]=(nums1[i]>=nums2[j]) ? nums1[i--] : nums2[j--];
        }else{
            while(j>=0){
                nums1[index--]=nums2[j--];
            }
            while(i>=0){
                nums1[index--]=nums1[i--];
            }
        }
    }
}
