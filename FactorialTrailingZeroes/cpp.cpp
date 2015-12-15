class Solution {
public:
    int trailingZeroes(int n) {
        int count = 0;
        while(n /= 5) count += n;
        return count;
    }
};
////
Well, to compute the number of trailing zeros, we need to first think clear about what will generate a trailing 0? Obviously, a number multiplied by 10 will have a trailing 0 added to it. So we only need to find out how many 10's will appear in the expression of the factorial. Since 10 = 2 * 5 and there are a bunch more 2's (each even number will contribute at least one 2), we only need to count the number of 5's.

Now let's see what numbers will contribute a 5. Well, simply the multiples of 5, like 5, 10, 15, 20, 25, 35, .... So is the result simply n / 5? Well, not that easy. Notice that some numbers may contribute more than one 5, like 25 = 5 * 5. Well, what numbers will contribute more than one 5? Ok, you may notice that only multiples of the power of 5 will contribute more than one 5. For example, multiples of 25 will contribute at least two 5's.

Well, how to count them all? If you try some examples, you may finally get the result, which is n / 5 + n / 25 + n / 125 + .... The idea behind this expression is: all the multiples of 5 will contribute one 5, the multiples of 25 will contribute one more 5 and the multiples of 125 will contribute another one more 5... and so on. Now, we can write down the following code, which is pretty short.

class Solution {
public:
    int trailingZeroes(int n) { 
        int count = 0;
        for (long long i = 5; n / i; i *= 5)
            count += n / i;
        return count;
    }
};
///
There are lots of explanations of this online. Briefly, pairs of factors of 2 and 5 in the prime factorization of n! generate trailing zeros. So for every 5 in the prime factorization, we can pair it with a 2 to generate a trailing zero. There are more than enough 2s to go around, the limiting "factor" is the 5s. Clearly there are at least n / 5 factors of 5 in n!. But in addition to being divisible by 5, n! may be divisible by 5^2, 5^3 and so on, which introduce more factors of 5 that pair up with factors of 2 to get more trailing zeros. So at each step of the algorithm we just divide by 5 and add the quotient to our total zero count, until the number isn't divisible by a power of 5.

class Solution {
public:
    int trailingZeroes(int n) {
        int zeros = 0;
        while (n) {
            zeros += n / 5;
            n /= 5;
        }
        return zeros;   
    }
};

