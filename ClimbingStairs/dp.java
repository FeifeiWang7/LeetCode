public int climbStairs(int n) {
    if (n < 3) return n;
    int sum1 = 1;
    int sum2 = 2;
    for (int i = 2; i < n; i ++) {
        sum2 = sum1 + sum2;
        sum1 = sum2 - sum1;
    }
    return sum2;
}
