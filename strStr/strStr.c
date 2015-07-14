#include <stdio.h>
#include <string.h>
int strStr(char* haystack, char* needle) {
	int h_len = strlen(haystack), n_len = strlen(needle);
	int i, j;
	for(i = 0; i < h_len-n_len+1; i++)
	{
		int k = i;
		for(j = 0; j < n_len; j++)
		{
			if(haystack[k] != needle[j]) break;
			else k++;
		}
		if(j==n_len) return i;
	}
	return -1;
}

int main()
{
	char haystack[] = "abcdedf";
	char needle[] = "f";
	int val = strStr(haystack, needle);
	printf("%d\n",val);
	return 0;
}
