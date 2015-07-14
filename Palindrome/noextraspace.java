public boolean isPalindrome(int x) {
    if(x < 0) return false;
    if(x == 0) return true;

    int size = 0;
    int tmp = x;
    while(tmp > 0)
    {
        size++;
        tmp /= 10;
    }
    int i = 0,j = size - 1;
    for(;i < j;i++,j--)
    {
        int h = x/(int)Math.pow(10, j)%10;
        int l = x/(int)Math.pow(10, i)%10;
        if(h != l) return false;
    }
    return true;       
}
