int* getRow(int r, int* rS) {
    int *a; int i;
    int t1,t2;
    *rS=r+1;
    a=(int *)malloc(sizeof(int)*(r+2));
    for(i=0;i<r+2;i++)
    a[i]=0;

    a[0]=1;
    a[1]=1;
    for( i=2;i<=r;i++)
    {
        t1=a[0];
        t2=a[1];
        for(int j=1;j<i+1;j++)
        {
            a[j]=t1+t2;
            t1=t2;
            t2=a[j+1];


        }
        a[i]=1;
    }

    return a;
}
