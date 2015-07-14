#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char *count(char tmp[])
{
	int i, len = strlen(tmp);
	char chr = tmp[0];
	int count = 1;
	int j = 0;
	char *result = (char *)malloc(sizeof(char)*5000);
	for(i = 1; i < len; i ++)
	{
		if(chr == tmp[i])
		{
			count ++;
		}
		else
		{
			result[j++] = count + '0';
			result[j++] = chr;
			count = 1; 
			chr = tmp[i];
		}
	}
	result[j++] = count + '0';
        result[j++] = chr;
	result[j++] = '\0';
	return result;
}

char* countAndSay(int n) 
{
	char *result = (char *)malloc(sizeof(char)*5000);
	strcpy(result, "1");
	while(--n)
	{
		result = count(result);
	}    
	return result;
}
int main()
{
	printf("%s\n", countAndSay(3));
	return 0;
}
