Two considerations: 1) At Nth row, each k-th element is determined by a well-known formula: C(n, k) = n! / (k!*(n-k)!). Obviously, we don't want to calculate factorial each time since we need to fill in the whole row, so we can just multiply both the numerator and denominator sequentially

2) A row in Pascal triangle is always symmetric, so we fill up two elements at each loop iteration

A drawback: In order to avoid overflows, we need to employ ugly casts to unsigned long

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> r;
        r.resize(rowIndex + 1);
        r[0] = r[rowIndex] = 1;
        for(auto i = 1; i < (r.size() + 1)/2; ++i)
        {
            r[i] = r[rowIndex - i] = (unsigned long)r[i - 1]*(unsigned long)(rowIndex - i + 1)/i;
        }
        return r;
    }
};
///

