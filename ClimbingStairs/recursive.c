int climbStairsCore(int n, int *record) {
    if (n == 1) {
        return 1;
    }
    else if (n == 2) {
        return 2;
    }
    else {
        int resultA = *(record + n - 1);
        if (resultA == -1) {
            resultA = climbStairsCore(n - 1, record);
            *(record + n - 1) = resultA;
        }

        int resultB = *(record + n - 2);
        if (resultB == -1) {
            resultB = climbStairsCore(n - 2, record);
            *(record + n - 2) = resultB;
        }
        return (resultA + resultB);
    }
}

int climbStairs(int n) {
    int *record = malloc(sizeof(int)*n);
    for (int i = 0; i < n; i++) {
        *(record + i) = -1;
    }
    return climbStairsCore(n, record);
}
