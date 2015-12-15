#include <stdio.h>
#include <string.h>
#include <stdlib.h>
char* convertToTitle(int n) {
        char *result = (char *)malloc(sizeof(char)*1000);
        int i = 0;
        int reminder;
        while(n/27 != 0)
        {
            reminder = n % 27;
            result[i] = reminder + 'A';
	printf("%c\n",result[i]);
            n = n /27;
            i++;
        }
    
        result[i] = n + 'A' - 1;
 
        result[++i] = '\0';
        int j = strlen(result);
        for(i = 0, j = j-1; i < j; i++, j--)
        {
                char tmp;
                tmp = result[j];
                result[j] = result[i];
                result[i] = tmp;
        }
        return result;
}
int main()
{
	printf("%s\n", convertToTitle(100));
	return 0;
}
