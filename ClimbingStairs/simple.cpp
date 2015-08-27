int climbStairs(int n) {
    int a = 1, b = 1;
    for (int i = 1;i < n;i++) {
        b += a;
        a = b - a;
    }
    return b;
}
