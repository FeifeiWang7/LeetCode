class Solution {
public:
    vector<int> plusOne(vector<int> &digits) {
        int c = 1, n = digits.size();
        vector<int> sum(n, 0);
        for(int i = n - 1; i >= 0; i--) {
            int val = digits[i] + c; 
            sum[i] = val % 10;
            c = val / 10;
        }
        if(c) sum.insert(sum.begin(), c);
        return sum;
    }
};
