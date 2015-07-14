#include <stdio.h>
#include <string.h>

int lengthOfLastWord(char *s)
{
	int len = strlen(s);
	int i = len -1, count = 0;
	for(i = len -1 ; i >= 0; i--)
	{
		if((s[i] == ' ')&&(count == 0)) continue;
		else if((s[i] == ' ')&&(count != 0)) break;
		else count++;
	}
	return count; 
}

int main()
{
	printf("%d\n", lengthOfLastWord("a bc"));
}
