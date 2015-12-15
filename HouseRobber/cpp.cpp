class Solution {
public:
    int rob(vector<int>& nums) {
        int it1 = 0, it2 = 0;
        for (int i = 0; i < nums.size(); i++) {
            it1 = max(it1 + nums[i], it2);
            swap(it1, it2);
        }
        return it2;
    }
};
