struct LinkedNode
{
    int val;
    LinkedNode *next;
    LinkedNode(int x = 0) : val(x), next(NULL) {}
};

bool containsNearbyDuplicate(vector<int>& nums, int k)
{
    int len = nums.size();
    if(len <= 1) return false;
    int D = len;
    LinkedNode *nodes = new LinkedNode[D];
    for(int i = 0;i < len;++i)
    {
        int bucket = abs(nums[i]) % D;
        LinkedNode *node = nodes[bucket].next;
        while(node)
        {
            int j = node->val;
            if(nums[i] == nums[j] && i - j <= k) return true;
            node = node->next;
        }
        node = nodes[bucket].next;
        nodes[bucket].next = new LinkedNode(i);
        nodes[bucket].next->next = node;
    }
    return false;
}
/////
bool containsNearbyDuplicate(vector<int>& nums, int k) {
    set<int> cand;
    for (int i = 0; i < nums.size(); i++) {
        if (i > k) cand.erase(nums[i-k-1]);
        if (!cand.insert(nums[i]).second) return true;
    }
    return false;
}
///////
bool containsNearbyDuplicate(vector<int>& nums, int k) {
    unordered_set<int> hashSet;
    if (!k) return false;
    if (k >= nums.size()) k = nums.size()-1;
    for (int i = 0;i <= k;++i)
        if (hashSet.find(nums[i]) == hashSet.end())
            hashSet.insert(nums[i]);
        else
            return true;
    for (int i = k+1;i < nums.size();++i) {
        hashSet.erase(nums[i-k-1]);
        if (hashSet.find(nums[i]) == hashSet.end())
            hashSet.insert(nums[i]);
        else
            return true;
    }
    return false;
}
///
bool containsNearbyDuplicate(vector<int>& nums, int k) {
    unordered_map<int,int> m;
    for(int i=0;i<nums.size();i++){
        if(m.find(nums[i])!=m.end()&&m[nums[i]]>=i-k)
        return true;
        m[nums[i]]=i;
    }
    return false;
}
///
class Solution {

public:

bool containsNearbyDuplicate(vector<int>& nums, int k) {

    unordered_map<int,int> used;

    for(int i=0;i<nums.size();i++){

        if(used.find(nums[i])==used.end()) {

            used[nums[i]]=i;

            continue;
        }

        if(i-used[nums[i]]<=k) return true; 

        used[nums[i]]=i;

    }

    return false;

}
};
///
bool containsNearbyDuplicate(vector<int>& nums, int k) {
    if(nums.empty()||k<1)
        return false;
    vector<int> temp=nums;
    sort(temp.begin(),temp.end());
    auto it=unique(temp.begin(),temp.end());
    if(it==temp.end())
        return false;
    for(auto it1=nums.begin();it1!=nums.end()-1;++it1){
        auto it2=find(it1+1,nums.end(),*it1);
        if(it2!=nums.end()){
            if(it2-it1<=k){
                return true;
            }
        }
    }
    return false;
}
