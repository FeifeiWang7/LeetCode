bool isPalindrome(int x) {
    if (x < 0) return false;
    int probe=1;
    while (x/probe>=10) probe*=10;
    while (probe>1)
    {
        int left=x/probe;
        int right=x%10;
        if (left!=right) return false;
        x=(x-left*probe)/10;
        probe/=100;
    }
    return true;
}
