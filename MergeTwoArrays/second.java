class Solution {
public:
    void merge(int A[], int m, int B[], int n) {
        while(n&&m){
            if(A[m-1]>B[n-1]){
                A[m+n-1]=A[m-1];
                m--;
            }
            else{
                A[m+n-1]=B[n-1];
                n--;
            }
        }
        while(n){
            A[n-1]=B[n-1];
            n--;
        }
    }
};
