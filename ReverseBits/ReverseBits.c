#include <stdio.h>
unsigned int reverseBits(unsigned int n) 
{
	unsigned int i, result = 0;
	for(i = 0; i < 32; i ++)
	{
		int tmp1 = (n >> i) << 31 >> i;
		//int tmp2 = n >> (i+1);
		//int tmp3 = (tmp1 | tmp2) >> i;
		result = result | tmp1;
	}
	return result;
}
int main()
{
	printf("%ud\n", reverseBits(43261596));
	return 0;
}
