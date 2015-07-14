#include <stdio.h>

int removeElement(int* nums, int numsSize, int val) {
	int i = 0, j = numsSize -1;
	for(i = 0; i < numsSize; i++)
	{
		if(*(nums+i) != val) continue;
		
		for(; j >= i; j--)
		{
			if(*(nums+j) == val) continue;
			*(nums+i) = *(nums+j);
			j--;
			break;
		}
		if(j < i) break;
	}
	return j+1;	
}

int main()
{
	int a[5] = {1,1,1,1,1};
	int len = removeElement(a, 5, 1);
	printf("%d\n",len);
	int i;
	for(i = 0; i < len ; i++) printf("%d\n",a[i]);
}
