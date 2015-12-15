Suppose the majority number exist as n,

If we sum the count of occurrence of 1 s for all the number in num at each bit position.

The number will either exceed half because n contributed more than half of 1 at that position,

or the number will be less-equal than half because n has 0 here then contributed nothing.

class Solution {

public:
    int majorityElement(vector<int> &num) {
        int len = num.size();
        if (len < 3) return num[0];
        int half = len/2;
        int bit_ct[32];
        for (int i=0; i<32; ++i)  bit_ct[i] = 0;
        for (auto n:num){ // count the number of 1 occured on each bit position
            for (int i=0; i<32; ++i){
                if (n%2) ++bit_ct[i];
                n >>= 1;
            }
        }
        int ans = 0;
        for(int i=31; i>=0; --i){
            ans <<= 1;
            if (bit_ct[i]>half) ++ans;
        }
        return ans;
    }
};
/////
int bitCount[32];
int majorityElement(vector<int>& nums) {
    for (auto num: nums) {
        for (int i = 0;i < 32;i++) {
            if (num & (1<<i))
                bitCount[i]++;
        }
    }
    int ans = 0;
    for (int i = 0;i < 32;i++) {
        if (bitCount[i] > nums.size()/2)
            ans |= 1<<i;
    }
    return ans;
}
