#include <stdio.h>
/* You may assume that nums1 has enough space (size that is greater or equal to m + n) to hold additional elements from nums2. The number of elements initialized in nums1 and nums2 are m and n respectively. */
void merge(int* nums1, int m, int* nums2, int n) 
{
	int i, j, k;
	for(i = m-1, j = n-1, k = m+n-1; j >= 0;)
	{
		if(i<0)
		{
			*(nums1+k) = *(nums2+j);
			j--;
			k--;
		}
		else if( *(nums1 + i) >= *(nums2 + j))
		{
			*(nums1+k) = *(nums1+i);
			i--;
			k--;
		}
		else
		{
			*(nums1+k) = *(nums2+j);
			j--;
			k--;
		}
	}
}
int main()
{
	int a[9] = {0,0,3,0,0,0,0,0,0};
	int b[6] = {-1,1,1,1,2,3};
	merge(a, 3, b, 6);
	int i;
	for(i = 0; i < 9; i ++)
		printf("%d ", a[i]);
}
