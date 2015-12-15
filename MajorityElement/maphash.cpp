class Solution {
public:
int majorityElement(vector<int>& nums) {
    int i;
    int size=nums.size();
    map<int,int> cnt_list;


    for(i=0;i<nums.size();i++)
        cnt_list[nums[i]]+=1;

    map<int,int>::iterator it=cnt_list.begin();           

    for(;it!=cnt_list.end();it++)
        if(it->second>size/2)
            return it->first;
}
};
