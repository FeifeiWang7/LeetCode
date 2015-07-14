bool isValid(char* s) {
    int len = strlen(s);
    if( len%2 != 0 )
    {
        return false;
    }

    int limit = len / 2;
    char *stack = malloc(limit);
    int idx = 0;
    char cur, peek;
    for(int i = 0; i < len; ++i)
    {
        cur = s[i];
        if(cur == '(' || cur == '[' || cur =='{')
        {
            if(idx == limit)
            {
                return false;
            }
            else
            {
                stack[idx++] = cur;
            }
        }
        else
        {
            if(idx == 0)
            {
                return false;
            }
            peek = stack[idx -1];
            if( (peek == '(' && cur == ')')
                || (peek == '[' && cur == ']')
                || (peek == '{' && cur == '}') )
            {
                idx--;
            }
        }
    }
    return idx == 0;
}
