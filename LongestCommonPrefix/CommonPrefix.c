#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

char* longestCommonPrefix(char** strs, int strsSize) {
        char *common;
        if(strsSize <2)
        {
                common = *strs;
                if(common == NULL) return "";
                return common;
        }
        int i, j, longest = INT_MAX;
        for(i = 0; i < strsSize; i ++)
        {
                longest = strlen(strs[i]) > longest ? longest : strlen(strs[i]);
        }
	printf("%d\n",longest);
	if(longest == 0) return "";
        common = (char *)malloc((longest+1) * sizeof(char));
        for(j = 0; j < longest; j++)
        {
                int flag = 0;
                for(i = 0; i < strsSize-1; i++)
                {	
                        if((strs[i][j] == '\0') || (strs[i+1][j] == '\0'))
                        {
                                flag = 0; break;
                        }
                        if( strs[i][j] != strs[i+1][j]) 
                        {
                                flag = 0; break;
                        }
                        flag = 1;
                }
                if(flag == 1) common[j] = strs[i][j];
		else break;
        }
	common[j] = '\0';
        if(common == NULL) return "";
        return common;
}

int main()
{
	char *p[3];
	char a[10][10] = {"cc","cc"};
	p[0] = &a[0][0];
	p[1] = a[1];
	p[2] = a[2];
	printf("%s\n",longestCommonPrefix(p, 2));
	return 0;
}
