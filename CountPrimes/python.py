class Solution(object):
    def countPrimes(self, n):
        if n < 3:
            return 0
        _xrange = xrange
        nums = range(1, n, 2)
        nums[0] = 0
        count = 1
        n //= 2
        for p in itertools.ifilter(None, nums):
            count += 1
            for q in _xrange(p * p // 2, n, p):
                nums[q] = 0
        return count
