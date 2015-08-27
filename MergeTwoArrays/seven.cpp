class Solution {
public:
    void merge(int A[], int m, int B[], int n) {
        int total=m+n;
        while(m && n)
        {
            if(A[m-1]>B[n-1]) A[--total]=A[--m];
            else A[--total]=B[--n];
        }
        while(n) A[--total]=B[--n];
    }
};
