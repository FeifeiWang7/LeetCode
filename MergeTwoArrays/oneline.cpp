I've seen a few other short ones but they all still had some unnecessary stuff like n>0 instead of just n. And many checked whether the next element comes from the second array, but it's slightly easier to check whether it comes from the first. Here's mine.

while (n) A[m+n-1] = m && A[m-1] > B[n-1] ? A[--m] : B[--n];
And without the spaces:

while(n)A[m+n-1]=m&&A[m-1]>B[n-1]?A[--m]:B[--n];

//////
void merge(int* nums1, int m, int* nums2, int n) {
    while(n)
    {
        nums1[m+n-1] = (m && nums1[m-1] > nums2[n-1]) ? nums1[--m]:nums2[--n];
    }
}
