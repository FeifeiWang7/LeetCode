public int reverseBits(int x) {
    x = (x & 0x55555555) <<  1 | ((x >> 1) & 0x55555555);
    x = (x & 0x33333333) <<  2 | ((x >> 2) & 0x33333333);
    x = (x & 0x0F0F0F0F) <<  4 | ((x >> 4) & 0x0F0F0F0F);
    x = (x & 0x00FF00FF) <<  8 | ((x >> 8) & 0x00FF00FF);
    x = x << 16 | x >>> 16;
    return x;
}
//////
public int reverseBits(int n) {

    int res=0;
    for(int i=0;i<32;i++){
        res= ( res << 1 ) | ( n & 1 );         
        n = n >> 1;                  
    }
    return res;
}
////////
public class Solution {
// you need treat n as an unsigned value
public int reverseBits(int n) {
    int result = 0;
    for(int i = 0; i < 32; i ++){
        if(isBit1(n, i)){
            result = setBit1(result, 31 - i);
        }
    }
    return result;
}

public int setBit1(int num, int i){
    return num | (1 << i);
}

public boolean isBit1(int num, int i){
    return (num & (1 << i)) != 0;
}
}

//////
public class Solution {
    // you need treat n as an unsigned value
    public int reverseBits(int n) {
        int reverse = 0;
        for(int i = 0; i < 32; i++){
            int temp = n << i;
            temp = temp >>> 31 << i;
            reverse += temp;
        }
        return reverse;
    }
}
////////////
public class Solution {
// you need treat n as an unsigned value
public int reverseBits(int n) {
    String op = String.format("%32s", Integer.toBinaryString(n)).replace(' ', '0');
    op = new StringBuilder(op).reverse().toString();
    int num = Integer.parseUnsignedInt(op,2);
    return num;
}}
