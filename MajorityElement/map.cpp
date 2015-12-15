class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int size = nums.size();
        if(size == 1) return nums[0];

        int half = size/2;
        unordered_map<int, int> map;
        while(size-- >= 0)
            if(map[nums[size]]++ >= half) 
                return nums[size];  
    }
};
