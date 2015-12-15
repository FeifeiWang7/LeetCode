The key point of this problem is to ignore half part of A and B each step recursively by comparing the median of remaining A and B:

if (aMid < bMid) Keep [aRight + bLeft]

else Keep [bRight + aLeft]
As the following: time=O(log(m + n))

public double findMedianSortedArrays(int[] A, int[] B) {
        int m = A.length, n = B.length;
        int l = (m + n + 1) / 2;
        int r = (m + n + 2) / 2;
        return (getkth(A, 0, B, 0, l) + getkth(A, 0, B, 0, r)) / 2.0;
    }

public double getkth(int[] A, int aStart, int[] B, int bStart, int k) {
    if (aStart > A.length - 1) return B[bStart + k - 1];            
    if (bStart > B.length - 1) return A[aStart + k - 1];                
    if (k == 1) return Math.min(A[aStart], B[bStart]);

    int aMid = Integer.MAX_VALUE, bMid = Integer.MAX_VALUE;
    if (aStart + k/2 - 1 < A.length) aMid = A[aStart + k/2 - 1]; 
    if (bStart + k/2 - 1 < B.length) bMid = B[bStart + k/2 - 1];        

    if (aMid < bMid) 
        return getkth(A, aStart + k/2, B, bStart,       k - k/2);// Check: aRight + bLeft 
    else 
        return getkth(A, aStart,       B, bStart + k/2, k - k/2);// Check: bRight + aLeft
}
///
public class Solution {
public double findMedianSortedArrays(int[] nums1, int[] nums2) {
    double now=0;
    double pre=0;
    int n = (nums1.length+nums2.length)/2+1;
    int i=0;
    int j=0;
    int k=0;
    while(k<n){
        pre = now;
        if(i==nums1.length){
            now = nums2[j++];
        }
        else if(j==nums2.length){
            now = nums1[i++];
        }
        else now = nums1[i]<nums2[j]?nums1[i++]:nums2[j++];
        k++;
    }
    return (nums1.length+nums2.length)%2==1?now:(pre+now)/2;
}
}


