bool isValid(char* s) 
{
        char *a;
        int topofstack;
        int i;
    size_t n= strlen(s);
    a=(char*)malloc(sizeof(char)*(n+1));
    topofstack=-1;

    for(i=0;i<n;i++)
    {
        if (s[i]=='{' || s[i]== '[' || s[i] == '(')
        a[++topofstack]=s[i];
        else if (topofstack==-1 && (s[i]=='}' || s[i]== ']' || s[i] == ')'))
        return 0;
        else if ( (s[i]==')'&& a[topofstack]!='(') || (s[i]=='}'&& a[topofstack]!='{')  
                     ||(s[i]==']'&&a[topofstack]!='[') ) 
            return 0;
        else if( (s[i]==')'&& a[topofstack]=='(')  || (s[i]=='}'&& a[topofstack]=='{') 
                     || (s[i]==']'&& a[topofstack]=='[') )                 
            topofstack--;

    }

    if(topofstack==-1) return 1;
    else return 0;

}
