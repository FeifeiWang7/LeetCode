char* convert(char* s, int numRows)
{
        if(numRows == 1) return s;
        int len = strlen(s);
        if(len == 0) return s;
        char *t = (char *)malloc((len+1) * sizeof(char));
        int i = 0, j = 0;
        int m,n;
        for(i = 0; i < numRows; i++)
        {
                m = 0; n = i;
                t[j] = s[n];
                j++;
                while(m < len)
                {
                        m = m + numRows - 1;
                        if( m*2 - n != n)
                        {
                                n = m * 2 - n;
                                if(n < len)
                                {
                                        t[j] = s[n];
                                        j++;
                                }
                        }
                }
        }
        t[j] = '\0';
        return t;
}
