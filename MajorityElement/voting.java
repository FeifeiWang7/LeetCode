This problem is a perfect match with moose's voting algorithm. Basic thought: set two variables: majorityIndex to locate the index of element occurring most, count to count the occurrences of majority element. Loop through array, if current element equals Array[majorityIndex], count++, otherwise count--. If count == 0, turn majorityIndex into current index. Through this way, we are able to find the element occurring most in this array.

Since we can assume there is always a majority element, we can immediately return the element we found through algorithm above. However, it'd be better to check if the element we found occurred more than size / 2 times in given array.

public class Solution {
    public int majorityElement(int[] nums) {
        // moore's voting algorithm
        // find candidate element
        if (nums.length == 1) return nums[0];
        int majorityIndex = 0, count = 1;
        for (int i = 1; i < nums.length; i++) {
            if (nums[i] == nums[majorityIndex]) count++;
            else count--;
            if (count == 0) {
                majorityIndex = i;
                count = 1;
            }
        }

        // check if candidate is the majority element
        return nums[majorityIndex];
    }
}
