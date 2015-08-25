class Solution {
public:
    string addBinary(string a, string b) {
        int i=a.size()-1,j=b.size()-1, carry=0;
        // since pass by value, find longer string and write to it
        if(i<j) { std::swap(a,b); std::swap(i,j); }
        // from LSB, sum and write to a, until b is all traversed
        for(;j>=0;--i,--j) {
            carry+=a[i]-'0'+b[j]-'0';
            if(carry<2) { a[i]='0'+carry; carry=0; }
            else { a[i]='0'+carry-2; carry=1; }
        }
        // if carry==1, need to modify the remaining part of a, 
        if(carry) {
            // the rightmost successive 1s would be 0s after summation, and carry remain unchanged
            for(;i>=0 && a[i]=='1';--i) { a[i]='0'; }
            if(i<0) a='1'+a; // all 1s
            else ++a[i]; // the rightmost 0 found
        }
        return a;
    }
};
