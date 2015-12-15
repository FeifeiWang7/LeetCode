public class Solution {
public int rob(int[] nums) {
    int size = nums.length;

    //Basic cases
    if(size == 0) {
        return 0;
    } else if(size == 1) {
        return nums[0];
    } else if(size == 2) {
        return Math.max(nums[0], nums[1]);
    }
    nums[2] += nums[0];
    for (int i = 3; i < size; i++) {
        nums[i] = Math.max(nums[i] + nums[i-3], nums[i] + nums[i-2]);
    }
    return Math.max(nums[size-1], nums[size-2]);
}
}

///////
The basic idea is DP. Use two variables two record the previous max before previous max, providing judging information when considering the current house.

public int rob(int[] nums) {
    if (nums.length < 1)
        return 0;
    else if (nums.length < 2)
        return nums[0];
    int beforePrevious = nums[0], previous = Math.max(beforePrevious,
            nums[1]);
    for (int i = 2; i < nums.length; i++) {
        if (previous > beforePrevious + nums[i]) {
            beforePrevious = previous;
        } else {
            int temp = previous;
            previous = beforePrevious + nums[i];
            beforePrevious = temp;
        }
    }

    return Math.max(previous, beforePrevious);
}
//////////
if(num.length==0) return 0;
if(num.length==1) return num[0];
num[1] = Math.max(num[0], num[1]);
for(int i=2;i<num.length;i++) num[i] = Math.max(num[i]+num[i-2], num[i-1]);
return num[num.length-1];
////dp
public class Solution {
public int rob(int[] nums) {
    /* DP solution.
     * preRob - max value if rob previous house.
     * preNotRob - max value if not rob previous house.
     * rob - max value if rob current house.
     * notRob - max value if not rob current house.
     */     
    int preRob = 0, preNotRob = 0, rob = 0, notRob = 0;
    for (int n : nums) {
        /*
         * dp(i-1) -> dp(i) key bridging:
         * 
         * dp[i][1] = dp[i-1][0] + nums[i-1] 
         * dp[i][0] = Max(dp[i-1][0], dp[i-1][1])
         * whereas dp[i][1] means rob current house and dp[i][0] not rob,
         * nums[i-1] is the cash from the current house (0 based index).
         */
        rob = preNotRob + n;
        notRob = Math.max(preRob, preNotRob);

        preNotRob = notRob;
        preRob = rob;
    }
    return Math.max(rob, notRob);
}
}
