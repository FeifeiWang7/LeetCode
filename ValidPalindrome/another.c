bool isPalindrome(char* s) {
    int len = strlen(s);
    if(!len) return true;
    char *p1 = s, *p2 = s + len - 1;
    while(p1 < p2){
        if(!isalnum(*p1)){p1++;continue;}
        if(!isalnum(*p2)){p2--;continue;}
        if(tolower(*p1++) != tolower(*p2--)) return false;
    }
    return true;
}

///
bool isPalindrome(char* s)
{
  if(s==NULL || !strcmp(s,"")) return true;

  for(char* p = s + strlen(s) -1; p>s;)
    if(isalnum(*s) && isalnum(*p) && tolower(*(s++)) != tolower(*(p--))) return false;            
    else if(!isalnum(*s))  s++;
    else if(!isalnum(*p))  p--;

  return true;
}

///
bool isPalindrome(char *s)
{
    if (s == NULL || *s == '\0')
        return true;
    int length = strlen(s);
    char *start = s;
    char *end = s;
    for (int i = 1; i < length; i++)
        end ++;
    while (start < end)
    {
        while(!isalphanumeric(start) && start < end)
            start++;
        while (!isalphanumeric(end) && start < end)
            end--;
        if (!isEqual(start, end))
            return false;
        start ++;
        end--;
    }
    return true;
}

bool isalphanumeric(char *p)
{
    if ((48 <= *p && *p <= 57) ||   //0<=*p<=9
        (65 <= *p && *p <= 90) ||   //A<=*p<=Z
        (97 <= *p && *p <= 122))    //a<=*p<=z
        return true;
    else
        return false;
}
bool isEqual(char *c1, char *c2)
{
    if ((*c1 == *c2) || (32 == *c1 - *c2) || (32 == *c2 - *c1))
        return true;
    else
        return false;
}
