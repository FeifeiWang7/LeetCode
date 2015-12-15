#include <stdio.h>
#include <stdbool.h>
#include <string.h>
bool wordPattern(char* pattern, char* str)
{
        int i, j, len = strlen(pattern);
        int search[len];
        char *token, *saveptr; char strtmp[strlen(str)];
        for(i = 0; i < len; i++) search[i] = -1;

        strcpy(strtmp, str);
        token = strtok_r(strtmp, " ", &saveptr);
        for(i = 0; i < len; i++)
        {
                int a = strchr(pattern, pattern[i]) - pattern;

                if(token == NULL) break;
                int b = strstr(str, token) - str;

                for(j = 0; j < a; j++)
                        if(search[j] == b) return false;
                if(search[a] == -1) search[a] = b;
                else if(search[a]!= b) return false;
                token = strtok_r(NULL, " ", &saveptr);
        }
        if((token == NULL) ^ (i== len)) return false;
        return true;
}
int main()
{
	printf("%d\n", wordPattern("abba", "dog cat cat dog"));
	return 0;
}
