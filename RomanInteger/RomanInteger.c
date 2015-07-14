#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int getValue(char c)
{
	switch(c)
	{
		case 'I': return 1;
		case 'V': return 5;
		case 'X': return 10;
		case 'L': return 50;
		case 'C': return 100;
		case 'D': return 500;
		case 'M': return 1000;
		default: printf("unkown character.\n"); return 0;
	}
}
int romanToInt(char* s) {
	int len = strlen(s);
	int i = 0;
	int num = getValue(s[len-1]);
	for(i = len-2; i >= 0; i --)
	{
		if(getValue(s[i]) < getValue(s[i+1])) num = num - getValue(s[i]);
		else num = num + getValue(s[i]);
	}
	return num;
}
int main()
{
	printf("%d\n", romanToInt("XCIX"));
}
		
