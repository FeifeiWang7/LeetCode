bool isPowerOfTwo(int n) {
    int ct=0;
    int i=0;
    if(n == 0)
        return false;
    while(n){
        if(n & 1)
            ct++;
        n = n >> 1;
        if(ct>1)
            return false;
    }
    return true;
}
//////
I submitted two solutions to powerOfTwo problem.

First:

bool isPowerOfTwo(int n) {
        if(n == 0)              return false;
        if(n == 2 || n == 1)    return true;
        if(n%2 != 0)            return false;
        else                    return isPowerOfTwo(n>>1);
    }
Second:

bool isPowerOfTwo(int n) {
        if(n <= 0)              return false;
        else                    return !(n & (n-1));
    }
How come the first solution has a runtime of 4ms and the second one has 8ms?

The first solution is recursive, has two division operations in each recursive call. It should be way slower than just a bit operation.
