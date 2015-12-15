class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        decltype(n) res = 0;
        for (int i = 0; i < 32; i++, n >>= 1) res = (res << 1) | (n & 1);
        return res;
    }
};
///
class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t result = 0;
        int i = 32;
        while(n) {
            result <<= 1;
            result |= (n&0x01);
            n >>= 1;
            i--;
        }
        result <<= i;
        return result;
    }
};
////
class Solution {
public:
    uint32_t reverseBits( uint32_t n ) {
        uint32_t result = 0;
        for( int i = 0; i < 32; i++, n >>= 1 )
            if( n & 1 )
                result |=  1 << ( 31 - i );

        return result;
    }
};
////
class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t result = 0;
        for(int i = 0;i<32;i++){
            result = result | ((((n & (0b1<<i)))>>i)<<(31-i));
        }
        return result;
    }
};
////
class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t result = 0;

        for (int i=0; i < 32; i++ ) {
            if(i != 0) {
                n >>= 1;
                result <<= 1;
            }
            result |= n & 1U;
        }
        return result;
    }
};
////////
class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        for(int i=0; i<16; i++)
        {
            uint32_t mask1 = 1<<i;
            uint32_t mask2 = 1<<31-i;

            uint32_t i1 = mask1 & n;
            uint32_t i2 = mask2 & n;

            i2 >>= 31-2*i; 
            if(i1 == i2) continue;

            i1 <<= 31-2*i; 
            if(i1)
                n += i1;
            else 
                n -= mask2;

            if(i2)
                n += i2;
            else 
                n -= mask1;
        }
        return n;
    }
};
///
class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t i,high,low,tmp=0;
    for(i=0;i<16;i++)
    {
        high=(n>>(31-i))&0x1;
        low=(n>>i)&0x1;
        //
        if(low)
        {
            tmp=tmp|(1<<(31-i));
        }
        //
        if(high)
            tmp=tmp|(1<<i);
    }

    return tmp;
    }
};
/////
uint32_t reverseBits(uint32_t n) {
    uint32_t m = 0;
    for (int i = 0; i< 32 ; i++,n/=2)
        m = (m<<1) + (n%2);
    return m;
}
////
class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        if(n == 0) return n;
        uint32_t res = 0;
        for(int i = 31; i >= 0; i--) {
            if((1<<i)&n) res += (1<<(31 - i));
        }
        return res;
    }
};
///
class Solution {
public:
uint32_t reverseBits(uint32_t n) {
    n = (n & 0x55555555) << 1 | (n & 0xAAAAAAAA) >> 1;
    n = (n & 0x33333333) << 2 | (n & 0xCCCCCCCC) >> 2;
    n = (n & 0x0F0F0F0F) << 4 | (n & 0xF0F0F0F0) >> 4;
    n = (n & 0x00FF00FF) << 8 | (n & 0xFF00FF00) >> 8;
    n = (n & 0x0000FFFF) << 16| (n & 0xFFFF0000) >> 16;
    return n;
}
};

/////
   //reverse pattern
    //0000 => 0000 = 0
    //0001 => 1000 = 8
    //0010 => 0100 = 4
    //0011 => 1100 = C
    //0100 => 0010 = 2
    //0101 => 1010 = A
    //0110 => 0110 = 6
    //0111 => 1110 = E
    //1000 => 0001 = 1
    //1001 => 1001 = 9
    //1010 => 0101 = 5
    //1011 => 1101 = D
    //1100 => 0011 = 3
    //1101 => 1011 = B
    //1110 => 0111 = 7
    //1111 => 1111 = F
We create a 64 bits number that contains all the transformation for the 16 hex signs, then we take the 4 last bits of n (lsb), multiply the value by 4 to find the offset to look at in the reference number, and shift the result to the first place ( << 28). Repeat than 8 times with a 4 bits shift and a logic OR each time to get the 32 bits correctly reversed.

This is to avoid reversing each single bit each time a number has to be reversed.

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint64_t reverseTable = 0xF7B3D591E6A2C480;
        uint32_t result = 0;
        for(int i = 0; i < 32 ; i+=4)
            result |= (reverseTable >> (4 * (n >> i & 0x0f)) & 0x0f) << 28-i;
        return result;
    }
};
///
class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        if(!n) return n;

        uint32_t new_n;
        for(int i = 0; i < 32; i++) {
            new_n = (new_n << 1) ^ (n & 1);
            n >>= 1;
            if(!n) {
                new_n <<= 32 - (i + 1);
                break;
            }
        }
        return new_n;
    }
};
///
class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        int rst=0;

        for(int ii=0; ii<32; ++ii)
            if((1<<ii)&n)
                rst += (1<<(31-ii));

        return rst;
    }
};
///
class Solution { public: uint32t reverseBits(uint32t n) {

    uint32_t res = 0;

    for( int i = 0; i < 32; i++ )
    {
        if( n )
        {
            res <<= 1;
            res += n % 2;
            n >>= 1;
        }
        else
        {
            res <<= ( 32 - i );
            break;
        }
    }

    return res;
}
};
///
uint32_t reverseBits(uint32_t n) {
    uint32_t result=0;
    uint32_t p=1,rest=0,i=1;
    while(i<32){
        p*=2;
        i++;
    }
    if(n==1) return n*p;
    while(n>1){
        result+=(n%2)*p;
        n=n/2;
        p=p/2;
    }

    return result+n*p;
}
//////
This does literally what the problem asks, it swaps each pair of bits from the outside in. The swap operation looks at the pair of bits to see if they're different, and if so, flips each bit. For each pair of indices i and j, we can select the ith bit and the jth bit with the expressions ((n >> i) & 1) and (n >> j) & 1). We then compare the two bits. If they are equal, we don't need to do anything because swapping them would have no effect. If they're not equal, we flip each bit by XORing it with 1. This has the effect of "swapping" the bits even though we're really just flipping each one. So the pair (0, 1) would get changed to (1, 0) and (1, 0) would get changed to (0, 1). To XOR the ith and jth bits each with ones, we form a number with 1's in the ith and jth places using OR: ((1U << i) | (1U << j)). Then we can just XOR this with our number to flip the bits in the ith and jth places.

If we needed to process lots of numbers, a faster way to do this would be to build up a table of preprocessed answers for numbers up to some bit count, and then reverse the overall number block by block.

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        int i = 0, j = 31;
        while (i < j) {
            if (((n >> i) & 1) != ((n >> j) & 1)) {
                n ^= ((1U << i) | (1U << j));
            }
            i++, j--;
        }
        return n;
    }
};
