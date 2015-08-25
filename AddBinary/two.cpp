class Solution {
public:
    std::string addBinary(std::string a, std::string b) {
        int m = a.size(), n = b.size(), carry_bit = 0;
        if (m < n)  return addBinary(b, a);
        for (int i = 0; i != m; ++i) {
            int tmp = a[m - 1 -i] + (i < n ? b[n - 1 -i] : '0') + carry_bit;
            if (tmp == 2 * '0' + 1) {
                a[m - 1 - i] = '1';
                carry_bit = 0;
            } else if (tmp == 2 * '0' + 2) {
                a[m - 1 - i] = '0';
                carry_bit = 1;
            }
        }
        return carry_bit ? "1" + a : a;
    }
};

/// solves the problem that I want to reuse the address of a, but cannot decide whether a or b is longer.

