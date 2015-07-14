int removeDuplicates(int* a, int n) 
{   int i;
    if(n==0) return 0;
    if(n==1) return 1;
    int*p =a+1;
    int cur;
    cur=a[0];
    for(i=1;i<n;i++)
    {
        if(a[i]!=cur){ cur=a[i]; *p=a[i]; p++;}
    }

    return p-a;
}
