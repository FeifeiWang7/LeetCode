class Solution {
public:
    int climbStairs(int n) {
        if(n == 0 || n == 1)
        {
            return n;
        }
        int a = 1;
        int b = 1;
        for(int i = 1; i < n; i++)
        {
            if(i%2 == 0)
            {
                b += a;
            }else
            {
                a += b;
            }
        }
        if(n%2 == 0)
        {
            return a;
        }else
        {
            return b;
        }
    }
};
