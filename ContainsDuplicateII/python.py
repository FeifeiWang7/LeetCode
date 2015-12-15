def containsNearbyDuplicate(self, nums, k):
    dic = {}
    for i, v in enumerate(nums):
        if v in dic and i - dic[v] <= k:
            return True
        dic[v] = i
    return False
###
Using dict, 60ms, O(n) time & O(n) space:

    class Solution:
        # @param {integer[]} nums
        # @param {integer} k
        # @return {boolean}
        def containsNearbyDuplicate(self, nums, k):
            if not nums:
                return False
            pos = {}
            for i,v in enumerate(nums):
                if v not in pos:
                    pos[v] = i
                else:
                    prev = pos[v]
                    curr = i
                    if curr - prev <= k:
                        return True
                    else:
                        pos[v] = curr
            return False
Using set, 88ms, O(n) time & O(k) space:

class Solution:
    # @param {integer[]} nums
    # @param {integer} k
    # @return {boolean}
    def containsNearbyDuplicate(self, nums, k):
        if not nums:
            return False
        pos = set()
        for i,v in enumerate(nums):
            if len(pos) > k:
                pos.remove(nums[i-k-1])
            if nums[i] in pos:
                return True
            else:
                pos.add(nums[i])
        return False
###
class Solution:
    # @param {integer[]} nums
    # @param {integer} k
    # @return {boolean}
    def containsNearbyDuplicate(self, nums, k):
        if nums is None:
            return False

        coll = {}
        res = False
        for i in xrange(len(nums)):
            if coll.get(nums[i]) is None:
                coll[nums[i]]=i
            else:
                if i-coll[nums[i]]<=k:
                    res = True
                else:
                    coll[nums[i]] = i

        return res
I agree with this point "You don't have to iterate till the very end - enough to return as soon as a duplicate is found. ", it is better to add a return statement after "res = True". Yes, I have two searches in my code, one for the input list, and the other for the dict. I think the former is necessary, and latter one is "searching & inserting" in a dict, of which the time complexity is only O(1), however the searching and inserting operation in a list is nearly O(n).

This one is easier to understand while complexity is O(k*n):

def containsNearbyDuplicate(self, nums, k):
    for i in xrange(max(len(nums)-k+1, 1)):
        dic = {}
        for j in xrange(i, min(i+k+1, len(nums))):
            if nums[j] in dic:
                return True
            dic[nums[j]] = 0
    return False
