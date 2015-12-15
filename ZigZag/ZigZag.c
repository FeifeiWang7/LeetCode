#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char* convert(char* s, int numRows) 
{
	if(numRows == 1 || numRows >= strlen(s)) return s;
	int distance = (numRows-1)*2, i = 0, len = strlen(s), index = i;
	char *result = (char *)malloc(sizeof(char)*(len+1));
	while(j < len)
	{
		if((i == 0) || (i == numRows-1))
		{
			result[j++] = s[index];
			index = index + distance;
		}
		else
		{
			result[j++] = s[index];
			index = index + distance - 2*i;
			if(index < len)
			{
				result[j++] = s[index];
				index = index + 2*i;
			}
		}
		if(index >= len)  index = ++i;
	}
	result[len] = '\0';
	return result;
}
int main()
{
	printf("%s\n", convert("0123456", 5));
	return 0;
}
