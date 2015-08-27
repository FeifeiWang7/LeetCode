public void merge(int A[], int m, int B[], int n) {

    int k = m + n - 1, i = m - 1, j = n - 1;
    while(j >= 0) {
        if(i >= 0 && A[i] >= B[j])  // i >=0, in case A is empty
            A[k--] = A[i--];
        else
            A[k--] = B[j--];
    }
}
