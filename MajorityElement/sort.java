Since the element which appears for more than n/2 times in the array, it should always appear at the middle of a sorted one. After we sort it, simply return the number in the middle will solve the problem.

public int majorityElement(int[] nums) {
    Arrays.sort(nums);
    return nums[nums.length/2];
}
