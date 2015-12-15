class Solution {
public:
    int majorityElement(vector<int>& nums) {
        sort(begin(nums),end(nums));
        return nums[nums.size()/2];
    }
};
