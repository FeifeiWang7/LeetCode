public int hammingWeight(int n) {
   int count = 0;
   while(n != 0){
       if((n&1) == 1) count++;
       n >>>= 1;
   }
   return count;
}
///
public int HammingWeight(uint n) {
    int count = 0;
    while(n != 0)
    {
        count += (int)(n & 1);
        n >>= 1;
    }
    return count;
}
////
// method1
// you need to treat n as an unsigned value
public int hammingWeight(int n) {
    int x = 0;
    while (n != 0) {
       x += (n - ((n >>> 1) << 1));
       n = n >>> 1;
    }
    return x;
}
// method2
// you need to treat n as an unsigned value
public int hammingWeight(int n) {
    int x = 0;
    while (n != 0) {
       x += (n & 1);
       n = n >>> 1;
    }
    return x;
}
////////
int hammingWeight(uint32_t n) {

    int bitCount = 0;
    while(n != 0){
        bitCount += (n&1); 
        n = n >> 1;
    }  
    return bitCount;
}
///////////
The first solution clears the bits right to left and counts how many bits were cleared. (The the number n - 1 has all of the trailing 0s from n flipped, and the first 1 before the trailings 0s flipped. So ANDing n with n - 1 effectively zeros out the last set bit in n.)

The good thing about this is the runtime is proportional to the number of set bits, so this is somewhat better than doing something like shifting the number right one bit at a time, selecting each bit, seeing if it's 1 or 0 and counting the 1s. However, if we were processing lots of numbers we wouldn't want to be doing so much recomputing. The second solution here is one way of using a table to store precomputed results for smaller numbers (4 bits in this case) and then computing the overall result one block at a time using the table.

class Solution {
public:
    int hammingWeight(uint32_t n) {
        int result = 0;
        while (n) {
            n &= n - 1, result++;
        }
        return result;
    }    

    int hammingWeight_2(uint32_t n) {

        unsigned long long int table = 0x4332322132212110;
//        0       0       
//        1       1
//        10      1
//        11      2
//        100     1
//        101     2
//        110     2
//        111     3
//        1000    1
//        1001    2
//        1010    2
//        1011    3
//        1100    2
//        1101    3
//        1110    3
//        1111    4
        return  
            ((table >> (4*((n >> 28) & 0xf))) & 0xf) +
            ((table >> (4*((n >> 24) & 0xf))) & 0xf) +
            ((table >> (4*((n >> 20) & 0xf))) & 0xf) +
            ((table >> (4*((n >> 16) & 0xf))) & 0xf) +
            ((table >> (4*((n >> 12) & 0xf))) & 0xf) +
            ((table >> (4*((n >>  8) & 0xf))) & 0xf) +
            ((table >> (4*((n >>  4) & 0xf))) & 0xf) +
            ((table >> (4*((n      ) & 0xf))) & 0xf);
    }
};
//////
int hammingWeight(uint32_t n) {
    return n == 0 ? 0 : 1 + hammingWeight(n & (n - 1));
}
/////
int hammingWeight(uint32_t n) {
    int counter = 0;
    for(int i = 0; i<=31; i++)
        if(((1<<i)&(n)) != 0) counter++;
    return counter;
}
/////
class Solution {
public:
    int hammingWeight(uint32_t n) {
        return (n%2?1:0)+(n==0?0:hammingWeight(n/2));
    }
};
