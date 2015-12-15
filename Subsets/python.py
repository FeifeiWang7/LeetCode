class Solution(object):
    def subsets(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        if len(nums) ==0:
            return  [[]]
        nums.sort()
        without_1st = self.subsets(nums[1:])
        with_1st = [([nums[0]] + x) for x in without_1st]
        return without_1st + with_1st
---
For this question, DP or recursive or backtrack what ever, I think it's almost same thing,but let's do it in a pure DP way:

1 Start from only 1 dig in the list, then result is obvious, [[],[nums[0]]]

2 Than for each new dig, the result is the previous list + previous list append the new dig, it's easy to understand, since once the new dig come in, there is 2 options, with it or with out it. without it, is the previous result, with it, it to add this dig in each array of the previuos result

def subnets(nums):
    nums.sort()
    dp={}
    dp[0]=[[],[nums[0]] ] 

    for i in range(1,len(nums)):
        dp[i]=dp[i-1]+[x+[nums[i]] for x in dp[i-1]]
    return dp[len(nums)-1]

--
import copy
class Solution(object):
    def subsets(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        result=[[]]
        n=len(nums)
        nums.sort()
        for i in range(n):
            c = copy.deepcopy(result)
            for k in c:
                k.append(nums[i])
                result.append(k)
        return result
---
Sort nums to satisfy solution constraint for sorted output. Turn into a tuple so that elements can be hashed for use in set. Stat with original tuple and add it to the subset. Then len(tuple) new subsets each with one element removed from the prior tuple. Check that the subset isn't already in the set (memoization) and then repeat process recursively.

This approach is more top-down then other faster solution I've seen that are bottom-up (i.e. start building subsets from single elements).

class Solution(object):
    def subsets(self, nums):
        def sub(nums):
            if nums:
                subsets.add(nums)
                for num in nums:
                    temp = tuple(x for x in nums if x != num)
                    if temp not in subsets:
                        sub(temp)
        subsets = set()
        sub(tuple(sorted(nums)))
        return [list(t) for t in list(subsets)] + [[]]
---
After removing the if and simplifying the return:

def subsets(self, nums):
    def sub(nums):
        subsets.add(nums)
        for num in nums:
            temp = tuple(x for x in nums if x != num)
            if temp not in subsets:
                sub(temp)
    subsets = set()
    sub(tuple(sorted(nums)))
    return map(list, subsets)
---
# DFS recursively 
def subsets1(self, nums):
    res = []
    self.dfs(sorted(nums), 0, [], res)
    return res

def dfs(self, nums, index, path, res):
    res.append(path)
    for i in xrange(index, len(nums)):
        self.dfs(nums, i+1, path+[nums[i]], res)

# Bit Manipulation    
def subsets2(self, nums):
    res = []
    nums.sort()
    for i in xrange(1<<len(nums)):
        tmp = []
        for j in xrange(len(nums)):
            if i & 1 << j:  # if i >> j & 1:
                tmp.append(nums[j])
        res.append(tmp)
    return res

# Iteratively
def subsets(self, nums):
    res = [[]]
    for num in sorted(nums):
        res += [item+[num] for item in res]
    return res
---
Straight-forward iterative solution:

def subsets(self, nums):
    subsets = [[]]
    for n in sorted(nums):
        subsets += [s + [n] for s in subsets]
    return subsets
Same thing but with reduce instead of the loop:

def subsets(self, nums):
    return reduce(lambda subsets, n: subsets + [s+[n] for s in subsets],
                  sorted(nums), [[]])
Using combinations from the library:

def subsets(self, nums):
    return [s for n in range(len(nums)+1)
            for s in itertools.combinations(sorted(nums), n)]
Using integers as bit mask to tell which elements to use in a subset:

def subsets(self, nums):
    nums.sort()
    return [[nums[i] for i in range(len(nums)) if mask >> i & 1]
            for mask in range(2 ** len(nums))]
---
class Solution:
    # @param {integer[]} nums
    # @return {integer[][]}
    def subsets(self, nums):
        if nums is None:
            return

        nums.sort()
        res1 = []
        res2 = nums[:]
        res = []

        def sum_inside(res1,res2):
            res.append(res1[:])
            res2_len = len(res2)
            if res2_len!=0:
                for i in range(res2_len):
                    res1.append(res2[i])
                    res3 = res2[i+1:]
                    sum_inside(res1,res3)
                    res3.insert(0,res1.pop())

        sum_inside(res1,res2)
        return res
---
class Solution:
    # @param {integer} n
    # @param {integer} k
    # @return {integer[][]}
    def combine(self, n, k):
        result = []
        self.getCombination(n, k, result, [])

        return result

    def getCombination(self, n, k, result, temp, start = 1):
        if len(temp) == k:
            result.append(temp[:])
            return

        for i in range(start, n + 1):
            temp.append(i)
            self.getCombination(n, k, result, temp, i + 1)
            temp.pop()


---
class Solution:
# @param S, a list of integer
# @return a list of lists of integer
def subsets(self, S):
    if not S:
        return [[]]
    else:
        S.sort()
        pre_subsets = self.subsets(S[1:])
        return pre_subsets + [[S[0]]+elem for elem in pre_subsets]
---
class Solution:
    # @param S, a list of integer
    # @return a list of lists of integer
    def subsets(self, S):
        n = len(S);
        S = sorted(S)
        result = [];
        for i in xrange(1<<n):
            temp = []
            for j in xrange(n):
                if i & (1<<j) > 0:
                    temp.append(S[j]);
            result.append(temp);
        return result;
