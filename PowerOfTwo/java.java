public class Solution {
public boolean isPowerOfTwo(int n) {

    return n<=0?false:((n&(n-1))==0)?true:false;
}
}
///
public class Solution {
    public boolean isPowerOfTwo(int n) {
        return n > 0 && (n & (n - 1)) == 0; 
    }
}

