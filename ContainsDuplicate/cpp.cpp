bool containsDuplicate(vector<int>& nums) {
    sort(nums.begin(),nums.end());
    if(nums.size()==1){
        return false;
    }
    for(int i=0,n=nums.size();i<n-1;i++) {
        if(nums[i]==nums[i+1]) {
            return true;
        }
    }
    return false;
}
////
#define BITSPERWORD 32  
#define SHIFT 5  
#define MASK 0x1F  
#define N 10000000  
int a[1 + N/BITSPERWORD]; 
void set_(int i) {        a[i>>SHIFT] |=  (1<<(i & MASK)); }  
void clr(int i) {        a[i>>SHIFT] &= ~(1<<(i & MASK)); }  
int  test(int i){ return a[i>>SHIFT] &   (1<<(i & MASK)); }  


class Solution {

public:
    bool containsDuplicate(vector<int>& nums) {
        if(nums.size()==0)return false;
        int i;  
    for (i = 0; i < nums.size(); i++)  
        clr(nums[i]);    
    for (i = 0; i < nums.size(); i++)  
    {
        if(test(nums[i]))return true;
        else set_(nums[i]);  
    }
   return false;
    }
};

///
class Solution { public: bool containsDuplicate(vector& nums) {

    unordered_set<int> h;
    h.clear();
    if (nums.size() <= 1 ) return false; // Base case return false if there is one/no elements;
    for(int i=0; i<nums.size(); i++){

        if(h.find(nums[i]) != h.end()){     // At each iteration check whether there is any duplicate element;
            return true;
        }
        h.insert(nums[i]);                     // insert elements;
    }
    return false;
}
};

///
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        if( nums.empty() )
            return false;

        int len = nums[ 0 ];
        for( int i = 1; i < nums.size(); i++ )
            if( nums[ i ] > len )
                len = nums[ i ];

        int *arr = new int[ len + 1 ];

        for( int i = 0; i < nums.size(); i++ )
        {
            if( arr[ nums[ i ] ] == 1 )
                return true;

            arr[ nums[ i ] ] = 1;
        }

        return false;
    }
};
/////
bool containsDuplicate(vector<int>& nums) {
    if(nums.size() > 1){
       unordered_set<int> unset;
       pair<unordered_set<int>::iterator,bool> res;
        for(int i = 0; i <nums.size(); ++i)
        {
            res = unset.insert(nums[i]);
            if(res.second==false)
                return true;
        }  
   }
    return false;
}
////
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        return unique(nums.begin(), nums.end()) != nums.end();
    }
};
///
bool containsDuplicate(vector<int>& nums) {

    // empty array or single element has no duplicate
    if( (nums.size() == 0) || (nums.size() == 1) ) return false;

    // sort array
    std::sort(std::begin(nums), std::end(nums));

    // search for duplicate
    for(int i = 0; i < nums.size()-1; i++)
       if(nums[i] == nums[i+1]) return true;

    return false;
}
///
This solution is very straightforward, it's time complexity is O(N). It's better than sort method in Time complexity. But sorting is better in space complexity.

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> hashset;
        for (int i = 0; i < nums.size(); ++i) {
            if (hashset.find(nums[i]) != hashset.end()) {
                return true;
            }
            else {
                hashset.insert(nums[i]);
            }
        }
        return false;
    }
};
///
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        if (nums.empty()) { return false; }
        unordered_map<int,int> mp;
        for (int i : nums) {
            if (++mp[i] > 1) {
                return true;
            }
        }
        return false;
    }
};
///
class Solution {
  public:
    bool containsDuplicate(vector<int>& nums) {
        return set<int>(nums.begin(), nums.end()).size() < nums.size();
    }
};
///
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> duplicates ;
        for(int i = 0 ; i < nums.size() ; i++){
            if(!duplicates.insert(nums[i]).second) {
                return true ;
            }
        }
        return false;
    }
};
///
#include <algorithm>
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        return std::adjacent_find(nums.begin(), nums.end()) != nums.end();
    }
};
///
bool containsDuplicate(vector<int>& nums) {
    unordered_set<int> occ;
    for (auto item : nums) {
        if(occ.find(item) != occ.end()) return true;
        else occ.insert(item);
    }
    return false;
}
///////
class Solution {

public:

bool containsDuplicate(vector<int>& nums) {
    vector <bool> vec;
    vec.push_back(false);
if (nums.size()<=1){
    return false;
}
for (int i=0; i<nums.size();i++){
    int m=nums[i];
    if (m>=vec.size()){
        for (int j=vec.size();j<=m;j++){
            vec.push_back(false);
        }
    }
    if (m<vec.size()){
        if (vec[m]==true){
            return true;
        }
        else{
            vec[m]=true;
        }
    }
}
return false;
}
};


