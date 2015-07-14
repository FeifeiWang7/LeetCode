int reverse(int x)
{
        char* digit = (char *)malloc(sizeof(char)*12);
        char *p = digit;
        if(x < 0)
        {
                *p++ = '-';
                x = -x;
                if(x < 0) return 0;
        }
        int shifter = x;
        do{
                p++;
                shifter = shifter/10;
        }while(shifter);
        *p = '\0';
        p = digit;
        if(*p == '-') p++;
        do{
                *p++ = x%10 + 48;
                x = x/10;
        }while(x);

        if((digit[0] == '-') && (strlen(digit) == strlen("-2147483648")) && (strcmp (digit, "-2147483648") > 0)) return 0;
        else if( (strlen(digit) == strlen("2147483647")) && (strcmp(digit, "2147483647") > 0)) return 0;

        int len = strlen(digit);
        int result = 0;
        int i = 0;
        if(digit[0] == '-') i = 1;
        for(; i < len; i ++)
        {
                result = result * 10 + (digit[i] - '0');
        }
        if(digit[0] == '-') result = -result;
        return result;
}
