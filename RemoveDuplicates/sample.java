class Solution {
public:
    int removeDuplicates(int A[], int n) {
        if(n==0)
            return 0;
        int i=1;
        for(int j=1;j<n;++j)
        {
            if(A[i-1] != A[j])
                A[i++] = A[j];
        }
        return i;
    }
};
