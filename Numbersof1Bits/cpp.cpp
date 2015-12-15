class Solution {
public:
    int hammingWeight(uint32_t n) {
        bitset<32> t;
        t=n;
        return t.count();
    }
};
////
int hammingWeight(uint32_t n) {
        unsigned int count = 0;
        while(n)
        {
                count += n & 1;
                n >>= 1;
        }
        return count;
    }
//////
int hammingWeight(uint32_t n) {
    int res =0;
    while (n!=0)
    {
        n = n & (n-1);
        res++;
    }
    return res;
}
///
class Solution {
public:
    int hammingWeight(uint32_t n) {
        if (!n) return 0;
        return (n % 2) + hammingWeight(n >> 1);
    }
};
////
int hammingWeight(uint32_t n) {
    int count = 0;

    while (n) {
        n &= (n - 1);
        count++;
    }

    return count;
}
///////
class Solution {
public:
    int hammingWeight(uint32_t n) {
        int count = 0;

        while(n){
            ++count;
            n = (n - 1) & n;
        }
        return count;
    }
};
//////
public int hammingWeight(int n) {
     int c;
    for (c = 0; n != 0; ++c)
        n = n & (n - 1);
    return c;
}
///
public class Solution {
// you need to treat n as an unsigned value
public int hammingWeight(int n) {
    int val = 0;
    for (int i = 0; i < 32; ++i){
        if((n & 1) == 1){
            val++;
        }
        n >>>= 1;
    }
    return val;
}}
//////
long nl = n;
if(n < 0){
    nl = n & 0x7fffffff; 
    nl |= 0x80000000L;
}

int count = 0;
long tmp = nl;
while(tmp != 0){
    long lowerXor = tmp ^ (tmp-1);
    if(lowerXor > 0){
        tmp -= (lowerXor + 1) >> 1;
        count++;
    }else{
        break;   
    }
}
return count;
