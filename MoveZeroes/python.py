The idea is to move an element in nums p positions left (p being the number of zeros encountered so    far), and finally change the last p elements in nums to 0.

class Solution(object):
        def moveZeroes(self, nums):
            """
            :type nums: List[int]
            :rtype: void Do not return anything, modify nums in-place instead.
            """
            zero_count = 0
            for i in xrange(len(nums)):
                if nums[i] == 0:
                    zero_count += 1
                    continue
                nums[i - zero_count] = nums[i]
            for i in xrange(zero_count, 0, -1):
                nums[-i] = 0
###
class Solution(object):
    def moveZeroes(s, a):
        a.sort(key=lambda x: not x or None)
##
class Solution(object):
    def moveZeroes(self, nums):
        start, cur = -1, 0
        while cur < len(nums):
            if not nums[cur] == 0:
                start += 1
                nums[cur], nums[start] = nums[start], nums[cur]
            cur += 1
        return 
