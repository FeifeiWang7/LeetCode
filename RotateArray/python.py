n = len(nums)
nums[:] = nums[(n-k):] + nums[:(n-k)]


######
I know that this is probably not the most space efficient way to do it, but it passes all the test cases and is easy to understand. Basically I create a duplicate copy of the input list first. Then, for each number at index i in the input list, I replace it with the number at index i-k where k is another input parameter. In case i-k is negative, I use len(nums) - (i+k) instead.

Like I said, not that efficient, but gets the jerb done. :)

class Solution(object):
    def rotate(self, nums, k):
        nums_copy = nums[:]
        for i in range(len(nums)):
            nums[i] = nums_copy[ (i-k) if (i-k) >= 0 else len(nums)+(i-k) ]
