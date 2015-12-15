class Solution {
public:
    string multiply(string num1, string num2) {
        int len1=num1.length(), len2=num2.length();
        if ( (len1==1 && num1=="0") || (len2==1 && num2=="0"))
            return "0";
        int *ans = new int[len1+len2], k=0;
        memset(ans, 0, (len1+len2)*sizeof(int));

        for (int i=len1-1; i>=0; i--)
            for (int j=len2-1; j>=0; j--)
                ans[len1-1-i + len2-1-j] += (num1[i]-'0')*(num2[j]-'0');

        for (int i=0; i<len1+len2-1; i++)
            ans[i+1] += ans[i]/10, ans[i] %= 10;

        string ret;
        for (int i=len1+len2-1; i>=0; i--)
            ret += to_string(ans[i]);

        while (k<ret.length() && ret[k]=='0') k++;
        return ret.substr(k, ret.length()-k);

    }
};

///
string multiply(string num1, string num2) {
    // init with 0 (number 0, not char '0')
    string sum(num1.size() + num2.size(), 0);

    for (int i = num1.size() - 1; 0 <= i; --i) {
        int carry = 0;
        for (int j = num2.size() - 1; 0 <= j; --j) {
            // don't subtract '0' when get sum[]
            int tmp = (sum[i + j + 1]) + (num1[i] - '0') * (num2[j] - '0') + carry;
            carry = tmp / 10;
            // tmp - carry * 10 is more fast than tmp % 10  
            // ( Subtract and Multiply is fast than DivRem )
            // and also don't add '0' when set sum[]
            sum[i + j + 1] = tmp - carry * 10;
        }
        sum[i] += carry;
    }

    // find number 0('\0'), not '0'
    size_t startpos = sum.find_first_not_of('\0');
    if (string::npos != startpos) {
        // add '0' before output
        for(int i = startpos;i<sum.size();i++)
            sum[i]+='0';
        return sum.substr(startpos);
    }
    return "0";
}
