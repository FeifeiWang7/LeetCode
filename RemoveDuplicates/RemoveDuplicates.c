#include <stdio.h>

int removeDuplicates(int* nums, int numsSize) 
{
	if(numsSize == 0) return 0;
	int i, j;
	for(i = 0; i < numsSize;)
	{
		for(j = i+1; j < numsSize; )
		{
			if( *(nums+i) == *(nums+j)) 
			{
				j++;
			}
			else
			{
				i++;
				*(nums+i) = *(nums+j);
				j++;
			}
		}
		if(j == numsSize) break;
	}	
	return i+1;
}

int main(void)
{
	int a[1] = {};
	int len = removeDuplicates(a, 0);
	printf("%d\n",len);

	int i;
	for(i = 0; i < len; i ++)
		printf("%d\n", a[i]);
}
