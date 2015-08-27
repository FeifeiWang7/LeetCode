int f(int n, int *arr)
{
    if (n == 0 || n == 1) return 1;
    if (arr[n] != 0) return arr[n];
    else{
      arr[n] = f(n - 1, arr) + f(n - 2, arr);
      return arr[n];
    }
}

int climbStairs(int n) {
    int *p = (int *)malloc(sizeof(int) * (n + 1));
    int res, i;

    if (n == 0 || n == 1) p[n] = 1;  //Base condition

    for (i = 2; i <= n; i++) p[i] = 0; //For memoization, defaulting all values to 0

    res = f(n, p);
    free(p);

    return res;
}
