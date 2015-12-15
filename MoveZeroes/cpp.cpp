class Solution{
public:
void moveZeroes(vector<int>& nums){
    if(nums.empty()){
        return;
    }
    vector<int>::iterator it_fir = nums.begin();
    vector<int>::iterator it_end = nums.begin();
    it_end++;
    while(it_end != nums.end()){
        if(*it_fir == 0){
            if(*it_end == 0){
                it_end++;
            }else{
                *it_fir = *it_end;
                *it_end = 0;
            }
        }else{
            it_fir++;
            it_end++;
        }
    }
}
};
////
class Solution {
public:
    void moveZeroes(vector<int>& nums) {        
        for (auto i = nums.begin(), j = i; i != nums.end(); ++i)
            if (*i != 0)
                std::swap(*i, *j++);
    }
};
///
void moveZeroes(vector<int>& nums) {
  for (int i = 0, j = 0; i < nums.size(); i++) if(nums[i] != 0) swap(nums[i], nums[j++]);
}

 void moveZeroes(vector<int>& nums) {
    for (int i = 0, j = 0; i < nums.size(); i++)  {
        if (nums[i] != 0) swap(nums[i], nums[j++]);
    }
}
///
Very concise!

One comment, this will make it swap the leading non-zero nums, and swap n times when there is no zero in the vector. The following can avoid this:

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        for (int i = 0, l = 0; i < nums.size(); ++i) {
            if (nums[i] && l == i) ++l;  // leading nums[i] is not zero, just skip
            else if (nums[i]) swap(nums[i], nums[l++]);
        }
    }
};
///
The idea comes from the c++ erase/remove idiom.

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        fill(remove(nums.begin(), nums.end(),0), nums.end(), 0);
    }
};
///
struct Solution {
    void moveZeroes(vector<int>& nums) {
        for (int i = 0, j = 0; i < nums.size() ; ++ i)
            if (nums[i] != 0)
                swap(nums[i], nums[j++]);
    }
};
///
class Solution {
    public:
        void moveZeroes(vector<int>& nums) {
            for(int i=0,j=0;i<nums.size();i++) 
                if (nums[i]!=0) swap(nums[i],nums[j++]);
        }
    };
///
void moveZeroes(vector<int>& nums) {
    int last = 0, cur = 0;

    while(cur < nums.size()) {
        if(nums[cur] != 0) {
            swap(nums[last], nums[cur]);
            last++;
        }

        cur++;
    }
}
///
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int len = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] != 0) {
                if (nums[len] != nums[i]) {
                    swap(nums[len], nums[i]);
                }
                ++len;
            }
        }
    }
};
///
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int j = -1;
        for(int i = 0;i < nums.size();i++){
            if(nums[i] != 0){
                j++;
                nums[j] = nums[i];
            }
        }
        for(int i = j+1;i < nums.size();i++)
        nums[i] = 0;
    }
};
///
Similar but you can init j as zero. -1 is a little bit odd.

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int i=0, j=0;
        for (; i<nums.size(); ++i) {
            if (nums[i]) {
                nums[j++]=nums[i];
            }
        }
        for (; j<i;++j){
            nums[j]=0;
        }
    }
};
