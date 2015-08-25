/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int *reverseArray(int *digits, int digitsSize)
{
	int i;
	int *result = (int *)malloc(digitsSize * sizeof(int));
	for(i = 0; i < digitsSize; i ++)
		result[i] = digits[digitsSize - i - 1];
	return result;
}
int* plusOne(int* digits, int digitsSize, int* returnSize) 
{
	int *result = (int *)malloc(sizeof(int)*(digitsSize+1));
	int i;
	int plus = 1;
	for(i = 0; i < digitsSize; i ++)
	{
		result[i] = (digits[digitsSize - 1 - i] + plus) % 10;
		plus = (digits[digitsSize - 1 - i] + plus) / 10;
	}
	if(plus != 0) 
	{
		result[i] = plus;
		*returnSize = digitsSize + 1;
		return reverseArray(result, digitsSize + 1);
	}
	else 
	{
		*returnSize = digitsSize;
		return reverseArray(result, digitsSize);
	}
}
int main()
{
	int a[] = {9,9,9};
	int tmp;
	int *b = plusOne(a, 3, &tmp);
	int i;
	printf("%d\n", tmp);
	for(i = 0; i < tmp; i ++)
	{
		printf("%d", b[i]);
	}
	printf("\n");
}
