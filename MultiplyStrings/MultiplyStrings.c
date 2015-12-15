int d(char c)
{
    return c-'0';
}
char* multiply(char* num1, char* num2) 
{
        int len1= strlen(num1), len2 = strlen(num2);
        char *result = (char *)malloc(sizeof(char)*(len1+len2+1));
        memset(result, '0', len1+len2+1);
        result[len1+len2] = '\0';

        int i, j, k, carry = 0;
        for(j = len2 -1; j>=0; j--)
        {
                for(i = len1-1, k = len1+j; i>=0; i--, k--)
                {
                        int value = d(num1[i]) * d(num2[j]) + carry + d(result[k]);
                        result[k] = value %10 + '0';
                        carry = value / 10;
                }
                while(carry != 0)
                {
                        int value = carry + d(result[k]);
                        result[k] = value%10 + '0';
                        carry = value/10;
                        k--;
                }
        }
        char *p = result;
        while((*p == '0')&&(*p!='\0')) p++;
        if(*p == '\0') p--;
        return p;
}

