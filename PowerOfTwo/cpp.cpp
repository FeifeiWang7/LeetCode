I used n&(n-1), but, attention the 0.

class Solution {
public:
    bool isPowerOfTwo(int n) {
        return n > 0 && !(n&(n-1));
    }
};
///
class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n <= 0)  return false;
        return (n &= (n-1)) == 0;
    }
};
///
#include <bitset>

class Solution {
public:
    bool isPowerOfTwo(int n) {
        return n > 0 && std::bitset<sizeof(n) * 8>(n).count() == 1;
    }
};
///
bool isPowerOfTwo(int n) {
 return (int)log2(n)==log2(n);
}
