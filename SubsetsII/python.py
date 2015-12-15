class Solution(object):
def subsetsWithDup(self, nums):
    nums=sorted(nums)
    self.res=[]
    for i in xrange(1,len(nums)+1):self.cal(nums,[],i)
    return self.res+[[]]

def cal(self, nums, temp, i):
    if i==0: self.res+=temp,
    elif i>len(nums): return
    else:
        for j in xrange(len(nums)):
            if j==0 or nums[j]!=nums[j-1]:self.cal(nums[j+1:], temp+[nums[j]], i-1)

--
Difference between subset 1 is just add a condition to check if this array is already in previous result when create new arrays, but probably need further optimize, run time is 84s.

def subsetsWithDup(self, nums):
    """
    :type nums: List[int]
    :rtype: List[List[int]]
    """
    nums.sort()
    dp={}
    dp[0]=[[],[nums[0]] ] 

    for i in range(1,len(nums)):
        dp[i]=dp[i-1]+[x+[nums[i]] for x in dp[i-1] if x+[nums[i]] not in dp[i-1]]
    return dp[len(nums)-1]
--
# DFS  
def subsetsWithDup(self, nums):
    res = []
    nums.sort()
    self.dfs(nums, 0, [], res)
    return res

def dfs(self, nums, index, path, res):
    res.append(path)
    for i in xrange(index, len(nums)):
        if i > index and nums[i] == nums[i-1]: #Solution to Subset I
            continue                           #If this two lines are removed
        self.dfs(nums, i+1, path+[nums[i]], res)

--
# DFS  
def subsetsWithDup(self, nums):
    res = []
    nums.sort()
    self.dfs(nums, 0, [], res)
    return res

def dfs(self, nums, index, path, res):
    res.append(path)
    for i in xrange(index, len(nums)):
        if i > index and nums[i] == nums[i-1]:
            continue
        self.dfs(nums, i+1, path+[nums[i]], res)
---
From the previous question Subsets I, the iterate solution is

def subsets(self, nums):
    res = [[]]
    nums.sort()
    for num in nums: 
        res += [ i + [num] for i in res]
    return res
For every number in nums, we add it to every i in res. Ex. [[]], we add [] + [1] to res. The new res is [ [], [1] ]. Then add [] + [2] and [1] + [2], the new res is [[],[1],[2],[1,2]].

To void the duplicate, we check if i + [num] is already in res. So the iterate solution for Subsets II is:

def subsetsWithDup(self, nums):
    res = [[]]
    nums.sort()
    for num in nums: 
        res += [ i + [num] for i in res if i + [num] not in res]
    return res
--
class Solution:
    # @param {integer[]} nums
    # @return {integer[][]}
    # 9:51
    def subsetsWithDup(self, nums):
        result, usedSets = [], {}
        nums.sort()
        self.findSubsets(nums, result, usedSets, [])

        return result

    def findSubsets(self, nums, result, usedSets, temp, pos = 0):
        tupledTemp = tuple(temp)
        if not tupledTemp in usedSets:
            result.append(temp[:])
            usedSets[tupledTemp] = True

        for i in range(pos, len(nums)):
            temp.append(nums[i])
            self.findSubsets(nums, result, usedSets, temp, i + 1)
            temp.pop()

--
The idea is to add the current element in the sorted nums to each subset of the result from previous loop, and add those new sets to the result. If there are no duplicated element in the input nums, the result will be double in size at each loop. It avoided using recursion with expense of checking if new element is already in the result set. There are tradeoffs but it can still be done in 80ms.

class Solution:
    # @param {integer[]} nums
    # @return {integer[][]}
    def subsetsWithDup(self, nums):
        nums.sort()
        ret = set()
        ret.add(tuple([]))
        for num in nums:
            new_set = set()
            for i, ele in enumerate(ret):
                new_ele = tuple(list(ele) + [num])
                new_set.add(new_ele)
            ret = ret | new_set
        return [list(x) for x in ret]
--
class Solution:
    # @param num, a list of integer
    # @return a list of lists of integer
    # 1:02
    def __init__(self):
        self.output = []

    def subsetsWithDup(self, S, pos = 0, temp = None):
        temp = temp or []
        S.sort()

        if temp not in self.output:
          self.output.append(temp[:])

        for i in range(pos, len(S)):
            temp.append(S[i])
            self.subsetsWithDup(S, i+1, temp)
            temp.pop()

        return self.output
---
class Solution:
    # @param num, a list of integer
    # @return a list of lists of integer
    def subsetsWithDup(self, S):
        res = [[]]
        S.sort()
        for i in range(len(S)):
            if i == 0 or S[i] != S[i - 1]:
                l = len(res)
            for j in range(len(res) - l, len(res)):
                res.append(res[j] + [S[i]])
        return res
