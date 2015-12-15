class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n = numbers.size(), l = 0, r = n - 1;
        while (l < r) {
            if (numbers[l] + numbers[r] == target)
                return {l + 1, r + 1};
            if (numbers[l] + numbers[r] > target) r--;
            else l++;
        }
    }
};
///
class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        vector<int> result;
        int rem = 0;
        unordered_map<int, int> mapNum;

        for (size_t i = 0; i < numbers.size() ; i++)
        {
            rem = target - numbers[i];
            auto iter = mapNum.find(rem);
            if (iter!=mapNum.end())
            {
                result.push_back(iter->second + 1);
                result.push_back(i + 1);
                break;
            }
            mapNum[numbers[i]] = i;
        }
        return result;
    }
};
