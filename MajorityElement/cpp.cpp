class Solution {
public:
int majorityElement(vector<int>& nums) {
    //return solution1(nums);     //use map
    //return solution2(nums);     //use sort
    return solution3(nums);     //use O(1) space
}
private:
int solution1(vector<int> &nums){
    unordered_map<int, int> m;
    for(int i = 0; i < nums.size(); i++)
        m[nums[i]]++;
    auto cur = m.begin();
    for(auto i = cur; i != m.end(); i++){
        if(cur->second < i->second) cur = i;
    }
    return cur->first;
}
int solution2(vector<int> &nums){
    sort(nums.begin(), nums.end());
    return nums[nums.size() / 2];
}
int solution3(vector<int> &nums){
    int cur = nums[0];
    for(int i = 1, count = 1; i < nums.size(); i++){
        if(nums[i] == cur) count++;
        else count--;
        if(count == -1){
            cur = nums[i];
            count = 1;
        }
    }
    return cur;
}
};

////
class Solution {
public:
    int majorityElement(vector<int>& nums) 
{
       int i,num=0,temp=0;
       for(i=0;i<nums.size();i++)
       {  
          num==0? temp=nums[i]:i=i;
          nums[i]!=temp?num--:num++;
       }
       return temp;
    }
};

///
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        vector<int>::iterator mid = nums.begin() + nums.size()/2;
        nth_element(nums.begin(), mid, nums.end());
        return (*mid);
    }
};
