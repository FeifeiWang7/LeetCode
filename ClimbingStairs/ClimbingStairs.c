#include<stdio.h>

int climbStairs(int n)
{
	int result[100];
	int i;	
	result[0] = 1;
	result[1] = 2;
	for(i = 2; i < 100; i ++)
		result[i] = result[i-1] + result[i-2];
	return result[n-1];
}
