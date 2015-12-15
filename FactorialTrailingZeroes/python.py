class Solution(object):
    def trailingZeroes(self, n):
        results = 0
        ans = 1
        thePower = 0
        while ans >= 1:
            thePower += 1
            ans = n/(5**thePower)
            results += int(ans)
    return results
