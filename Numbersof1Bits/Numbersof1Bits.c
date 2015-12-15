#include <stdio.h>
int hammingWeight(unsigned int n) 
{
	int count = 0;
	while(n/2 != 0)
	{
		if(n%2 == 1) count++;
		n = n/2;
	}    
	if(n == 1) count++;
	return count;
}
int main()
{
	printf("%d\n", hammingWeight(11));
	return 0;
}
