#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
int myAtoi(char* num) {
        char *p = num;
        while((*p == ' ') || (*p == '\t') || (*p == '\n')) p++;
        int result = 0;
        int positive = 1;
        if( *p == '-')
        {
                positive = 0;
                p++;
        }
        else if( *p == '+')
        {
                positive = 1;
                p++;
        }
        while(*p >= '0' && *p <= '9')
        {
//              if((tmp >> 31 != result >> 31) || (tmp + '0' - *p)/10 != result)
                if(result > (INT_MAX - *p + '0')/10)
                        return positive?2147483647:-2147483648;
                result = result * 10 + *p - '0';
                p++;
        }
        return positive?result:-result;
}
int main()
{
	printf("%d\n", myAtoi("  10522545459"));
	return 0;
}
