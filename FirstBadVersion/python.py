class Solution(object):
    def firstBadVersion(self, n):
        """
        :type n: int
        :rtype: int
        """
        if n < 1: return 0
        l,r = 1,n # mustbe Range
        while l < r: 
            mid = (l+r)//2
            if isBadVersion(mid):
                r = mid
            else:
                l = mid + 1
        return l
###
standard binary search

class Solution(object):
    def firstBadVersion(self, n):
        """
        :type n: int
        :rtype: int
        """
        low, high = 1, n
        while low <= high:
            middle = (low + high) >> 1
            if isBadVersion(middle):
                high = middle - 1
            else:
                low = middle + 1

        return high + 1
###
Not the shortest, but easy to understand.

class Solution(object):
def firstBadVersion(self, n):
    """
    :type n: int
    :rtype: int
    """
    ### range [l,n]
    l = 1
    r = n
    mid = 0
    while l < r:
        mid = (l + r) / 2
        if isBadVersion(mid): r = mid
        else: l = mid + 1
    ### left one in range
    return r
###
def firstBadVersion(self, n):
    """
    :type n: int
    :rtype: int
    """
    left, right = 1, n
    while left < right:
        mid = (left + right) >> 1
        if isBadVersion(mid):
            right = mid
        else:
            left = mid + 1

    if isBadVersion(left):
        return left
    else:
        return 0
###
Use binary search until your range is 1 element. If midpoint is a bad version make that your new right bound. If midpoint is good version make your new left bound midpoint + 1.

class Solution(object):
    def firstBadVersion(self, n):
        def find(left, right):
            if left == right:
                return left
            mid = (left + right) // 2
            if isBadVersion(mid):
                return find(left, mid)
            else:
                return find(mid+1,right)
        return find(1, n)
