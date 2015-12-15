def rob(self, nums):
    max_far = near = 0
    for x in nums:
        near, max_far = x + max_far, max(near, max_f)
    return max(near, max_far)


#####
Explanation: Let's say the array is like: [1,3,5,5,2,2....j ...], so for each optimal value end of j is dp[j], than the recursive relation is: for new added j element, it has no border with dp[j-2], so dp[j-2]+ nums[j] is a candidate; and at same time, it could be smaller than dp[j-1], which could have adjacent element with nums[j], so the optimal value is max(max((dp[i-2]+nums[i]),dp[i-1]))

def rob(self,nums):
    dp={};
    dp[0]=nums[0]
    dp[1]=max(nums[0],nums[1])

    for i in range(2,len(nums)):
        dp[i] = max((dp[i-2]+nums[i]),dp[i-1])
    return dp[len(nums)-1]
########

You can just skip 1 house, or 2 houses to get the maximum money. That means maximum_money(i_th) = max(maximum_money(i-2th), maximum_money(i-3th)).

class Solution(object):
    def rob(self, nums):
        leng = len(nums)
        if leng == 0:
            return 0
        elif leng == 1:
            return nums[0]
        elif leng == 2:
            return max(nums[0], nums[1])

        money = [0] * leng
        # set initial state
        money[0] = nums[0]
        money[1] = nums[1]
        money[2] = nums[0] + nums[2]

        # set the bigger one
        for i in range(3, leng):
            money[i] = max(money[i-2] + nums[i], money[i-3] + nums[i])

        return max(money[leng-1], money[leng-2])
