public int climbStairs(int n) {
    int[][] ret = powermatrix(n);
    return ret[0][0];
}

int[][] powermatrix(int n){
    int[][] A = {{1, 1}, {1, 0}};
    int[][] median = new int[2][2];

    if(n == 1) return A;
    median = powermatrix(n / 2);
    median = cross(median, median);

    if(n % 2 == 1) median = cross(median, A);

    return median;
}

int[][] cross(int[][] A, int[][] B){
    int[][] C = new int[2][2];
    C[0][0] = A[0][0] * B[0][0] + A[0][1] * B[1][0];
    C[0][1] = A[0][0] * B[0][1] + A[0][1] * B[1][1];
    C[1][0] = A[1][0] * B[0][0] + A[1][1] * B[1][0];
    C[1][1] = A[1][0] * B[0][1] + A[1][1] * B[1][1];

    return C;
}
