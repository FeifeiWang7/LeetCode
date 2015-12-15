uint32_t reverseBits(uint32_t n)
{
   n = ((n<<16) | (n>>16));                         //swap [31:16]<=>[15:0]
   n = ((n&0x00ff00ff)<< 8 | (n&0xff00ff00)>> 8);   //swap [31:24]<=>[23:16] , [15:8]<=>[7:0]
   n = ((n&0x0f0f0f0f)<< 4 | (n&0xf0f0f0f0)>> 4);   //swap ...
   n = ((n&0x33333333)<< 2 | (n&0xcccccccc)>> 2);   //swap ...
   n = ((n&0x55555555)<< 1 | (n&0xaaaaaaaa)>> 1);   //swap ...
   return n;    
}
///////
uint32_t reverseBits(uint32_t n) {
    int rbitTable[256] = {
        #define R2(n) n, n + 2*64, n + 1 * 64, n + 3 * 64
        #define R4(n) R2(n), R2(n + 2 * 16), R2(n + 1 * 16), R2(n + 3 * 16)
        #define R6(n) R4(n), R4(n + 2 * 4), R4(n + 1 * 4), R4(n + 3 * 4)
        R6(0), R6(2), R6(1), R6(3)
    };
    uint32_t v;
    unsigned char *p = (unsigned char*)&n;
    unsigned char *q = (unsigned char*)&v;
    q[0] = rbitTable[p[3]];
    q[1] = rbitTable[p[2]];
    q[2] = rbitTable[p[1]];
    q[3] = rbitTable[p[0]];
    return v;
}
///
uint32_t reverseBits(uint32_t n) {
    int Table[]={0,8,4,12,2,10,6,14,1,9,5,13,3,11,7,15};
    int a1=Table[0xf&n];
    int a2=Table[(0xf0&n)>>4];
    int a3=Table[(0xf00&n)>>8];
    int a4=Table[(0xf000&n)>>12];
    int a5=Table[(0xf0000&n)>>16];
    int a6=Table[(0xf00000&n)>>20];
    int a7=Table[(0xf000000&n)>>24];
    int a8=Table[(0xf0000000&n)>>28];
    return (a1<<28)+(a2<<24)+(a3<<20)+(a4<<16)+(a5<<12)+(a6<<8)+(a7<<4)+a8;
}
///
uint32t reverseBits(uint32t n) {

uint32_t revern;

if (n == 0)
{
    return revern=0;
}
else
{
for(int i =0; i<32; i++)
{
   if (n&(1<<i))
   {
     revern=revern+(0x80000000>>i);
   }
}

return revern;
}
}

////
uint32_t reverseBits(uint32_t n) {
     uint32_t result = 0x0;
     int i = 0;

     for (i = 0; i < 32; i++)
     {
         if (n & (0x1 << (31-i)))
         {
             result |= (0x1 << i);
         }
     }

     return result;
}
/////
uint32_t reverseBits(uint32_t n) {
    uint32_t i, ans=0;
    for(i=0;i<16;i++)
        ans=ans|(1<<i&n)<<(31-2*i)|(1<<(31-i)&n)>>(31-2*i);
    return ans;
}
