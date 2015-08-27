class Solution:
    # @param {integer} n
    # @return {integer}
    def climbStairs(self, n):
        cache = {}
        cache[1], cache[2] = 1, 2

        for i in range(3, n + 1):
            cache[i] = cache[i - 1] + cache[i - 2]

        return cache[n]
