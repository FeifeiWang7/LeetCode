char* convertToTitle(int n) 
{
    char* ans =(char*)malloc(sizeof(char)* 10);
    char ans2[10];
    int i =0;int x;int j;
    while(n)
    {
        x=n%26;
        if(x==0) x=26;
        ans[i]= x+'A'-1;
        i++;
        if(n%26==0) n--;
        n/=26;
    }
    int dig=i;
    for(j=0;j<dig;j++)
    {
        ans2[j] = ans[i-1-j] ;
    }
    ans2[j]='\0';

    return ans2;
