int hammingWeight(uint32_t n) {
int result = 0;

for (int i = 0; i < 8; i++) {
    result += n & 0x01010101;
    n >>= 1;
}

result += (result >> 16);
result += (result >> 8);
return result & 0xFF;
} // the point is, it only requires 8 iterations, rather than the more typical 32; not sure it's better or worse

///////
int hammingWeight(uint32_t n) {
    return n > 0 ? n % 2 + hammingWeight(n/2) : 0; 
}
///////
int hammingWeight(uint32_t n) {
    n = (n & 0x55555555) + ((n >> 1) & 0x55555555);
    n = (n & 0x33333333) + ((n >> 2) & 0x33333333);
    n = (n & 0x0f0f0f0f) + ((n >> 4) & 0x0f0f0f0f);
    n *= 0x01010101;
    return n >> 24;
}
The code is from "Bit Twiddling Hacks" by Sean Eron Anderson.

int hammingWeight(uint32_t n) {
    int bitsSetTable[256] = {
        // B2(n): n means n 1s from 2nd bit(0 based) to MSB.
        #define B2(n) n, n + 1, n + 1, n + 2
        #define B4(n) B2(n), B2(n + 1), B2(n + 1), B2(n + 2)
        #define B6(n) B4(n), B4(n + 1), B4(n + 1), B4(n + 2)
        B6(0), B6(1), B6(1), B6(2)
    };
    /*
    bitsSetTable[0] = 0;
    for (int i = 0; i < 256; i++) {
        bitsSetTable[i] = (i & 1) + bitsSetTable[i / 2];
    }*/
    unsigned char *p = (unsigned char*)&n;
    int c = bitsSetTable[p[0]] 
            + bitsSetTable[p[1]] 
            + bitsSetTable[p[2]] 
            + bitsSetTable[p[3]];
    return c;
}
////
int hammingWeight(uint32_t n) {
    int count = n ? 1 : 0;
    while(n &= (n-1)) count++;
    return count;
}
/////
int hammingWeight(uint32_t n) {
    int cnt = 0;
    while(n){
        cnt ++;
        n -= (n & -n);
    }
    return cnt; 
}
///////
int hammingWeight(uint32_t n) {
    int m1=0x55555555;
    int m2=0x33333333;
    int m3=0x0f0f0f0f;
    int m4=0x00ff00ff;
    int m5=0x0000ffff;
    n = (n&m1) + ((n >> 1)&m1);
    n = (n&m2) + ((n >> 2)&m2);
    n = (n&m3) + ((n >> 4)&m3);
    n = (n&m4) + ((n >> 8)&m4);
    n = (n&m5) + ((n >> 16)&m5);
    return n;
}
////
int hammingWeight(uint32_t n) {
  if(n==0) return 0;
  return (n%2) + hammingWeight(n/2); 
}
