#include <stdio.h>
#include <stdbool.h>
#include <string.h>
bool isvalid(char c)
{
	if (((c >= 'a') && (c <= 'z')) || ((c >= 'A') && (c<='Z')) || ((c >= '0') && (c <= '9'))) return true;
	else return false;
}
bool isPalindrome(char* s) 
{
	int len = strlen(s);
	int i, j;
	for( i = 0, j = len -1; i < j; i++, j--)
	{

		while((isvalid(*(s+i)) == false) && (i <len)) i++;
                while((isvalid(*(s+j)) == false) && (j >=0)) j--;
                if(i >= j) return true;

		if((*(s+i)>='a') && (*(s+i)<='z') && (*(s+j)>='A') && (*(s+j) <= 'Z'))
		{
			if(*(s+i)-32 != *(s+j)) return false;
		}
		else if((*(s+i)>='A') && (*(s+i)<='Z') && (*(s+j)>='a') && (*(s+j) <= 'z'))
		{
			if(*(s+i) != *(s+j)-32) return false;
		}
		//uppercase+32 = lowercase
		else if(*(s+i) != *(s+j)) return false;
	}   
	return true;
}
int main()
{
	printf("%d\n", isPalindrome("A man, a plan, a canal: Panama"));
	return 0;
}
