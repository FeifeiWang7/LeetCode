class Solution {
public:
    string addBinary(string a, string b) {
        int aLen = a.size(), bLen = b.size(), i = aLen-1, j = bLen-1, k = max(aLen, bLen)-1, carrier=0, sum;

        string res(k+1, 1);
        while(i>=0 || j>=0)
        {
            sum = (i>=0?(a[i--] - '0'):0 ) + (j>=0?(b[j--] - '0'):0) + carrier;
            res[k--] = sum % 2 + '0';
            carrier = sum>1;
        }
        return carrier? "1"+res:res;
    }
};
