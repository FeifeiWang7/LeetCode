class Solution:
    # @param {integer[]} nums
    # @return {string[]}
    def summaryRanges(self, nums):
        result = []
        if not nums: return result
        start = current = None
        for num in nums:
            if start == None:
                start = current = num
            elif num == current + 1:
                current = num
            else:
                result.append(self.generateStringRange(start, current))
                start = current = num
        result.append(self.generateStringRange(start, current))
        return result


    def generateStringRange(self, start, end):
        result = str(start)
        if start != end: result += "->" + str(end)
        return result
#####
def summaryRanges(self, nums):
    if not nums:
        return []
    res, i, start = [], 0, 0
    while i < len(nums)-1:
        if nums[i]+1 != nums[i+1]:
            res.append(self.printRange(nums[start], nums[i]))
            start = i+1
        i += 1
    res.append(self.printRange(nums[start], nums[i]))
    return res

def printRange(self, l, r):
    if l == r:
        return str(l)
    else:
        return str(l) + "->" + str(r)
