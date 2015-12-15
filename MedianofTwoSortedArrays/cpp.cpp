If you solve the k-th minmum value of two sorted arrays, you solve this problem.This is a classical problem of "Divide and conquer".
Here is another more simple and more neat solution.
Cosider chosing first x numbers from A and k - x numbers from B.if these k numbers are the k minmum numbers of A and B, x must satisfies that A[x + 1] >= B[k - x] and B[k - x + 1] >= A[x] (for better explanation index is base-1). 
So this x is what we want.
Obviously, if A[x + 1] < B[k - x + 1] then x must be smaller, else if B[k - x] < A[x] then x must be greater. A nice two-value definition for binary search :)
To simplify edge cases, we cosider each array indefinite, with value of INTMIN when index < 1 and INTMAX when index > n.


typedef vector<int> vi;
const int inf = 0x7fffffff, ninf = 0x80000000;
class Solution {
    int kth_min(vi& a, vi& b, int k, int n, int m){
        #define A(i) (i < 1 ? ninf : (i > n ? inf : a[i - 1]))
        #define B(i) (i < 1 ? ninf : (i > m ? inf : b[i - 1]))
        int l = 0, r = n + 1, x;
        while(l <= r){
            x = (l + r) >> 1;
            if(A(x) > B(k - x + 1)) r = x - 1;
            else if(B(k - x) > A(x + 1)) l = x + 1;
            else return max(A(x), B(k - x));
        }
        return 0;   //never execute , just to hide the warning :)
        #undef A
        #undef B
    }
public:
    double findMedianSortedArrays(vector<int>& a, vector<int>& b) {
        int n = a.size(), m = b.size();
        if(n > m) return findMedianSortedArrays(b, a); //make sure that a.size() <= b.size()
        if((m + n) & 1) return kth_min(a, b, (m + n + 1) >> 1, n, m);
        return (0.0 + kth_min(a, b, (m + n + 1) >> 1, n, m) + kth_min(a, b, ((m + n) >> 1) + 1, n, m)) * 0.5;
    }
};
