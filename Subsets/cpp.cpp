vector<vector<int>> subsets(vector<int>& nums) {
    std::sort(nums.begin(), nums.end());
    vector<vector<int>> vv;
    vector<int> v;
    sub(vv, v, nums, 0, nums.size());
    return vv;
}

void sub(vector<vector<int>>& vv, vector<int>& v, vector<int>& nums, int start, int size) {
    vv.push_back(v);
    for (int i=start; i<size; ++i) {
        vector<int> vt = v;
        vt.push_back(nums[i]);
        sub(vv, vt, nums, i+1, size);
    }
}
-----
vector<vector<int>> subsets(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    vector<vector<int>> res;
    vector<int> path;
    dfs(nums, 0, path, res);
    return res;
}

void dfs(vector<int>& nums, int index, vector<int>& path, vector<vector<int>>& res) {
    res.push_back(path);
    for (unsigned int i = index; i < nums.size(); i++) {
        path.push_back(nums[i]);
        dfs(nums, i+1, path, res);
        path.pop_back();
    }
}
---
vector<vector<int>> subsets(vector<int>& nums) {

    sort(nums.begin(),nums.end());

    vector<int> s;
    vector<vector<int>> result(1,s);
    int n = nums.size(),j;

    for(int i = 0 ; i+1<1<<n;i++)
    {
        for(j = 0; (i>>j)&1;j++) s.pop_back();
        s.push_back(nums[n - j - 1]);
        result.push_back(s);
    }

    return result;
}
---
class Solution {
public:
    static int comp(int a, int b)
    {
        return a>b;
    }

    vector<vector<int>> dfs(vector<int>& nums, int p) {
        vector<vector<int>> ans;
        if (p==nums.size()) {
            ans.push_back(vector<int> ());
        } else {
            for (auto i : dfs(nums, p+1)) {
                ans.push_back(i);
                i.push_back(nums[p]);
                ans.push_back(i);
            }
        }
        return ans;
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        sort(nums.begin(), nums.end(), comp);
        return dfs(nums, 0);
    }
};
---
class Solution {
public:
    void f(vector<int>& temp,vector<vector<int>>&result,int i,vector<int>& nums){
        if(i==nums.size()){
            result.push_back(temp);
            return;
        }
        temp.push_back(nums[i]);
        f(temp,result,i+1,nums);
        temp.pop_back();
        f(temp,result,i+1,nums);
        return;
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int> temp;
        vector<vector<int>>result;
        f(temp,result,0,nums);
        return result;
    }
};
---
The comments should be self-explanary, but the basic idea is in each recursion call, we removes the last element of the input numbers, and call subsets() on the remaining numbers, then adds back the last element to each of the subsets of the remaining numbers to construct the final result.

e.g. nums = {3, 1, 2} sort -> nums = {1, 2, 3} last = 3 remaining nums = {1, 2} call subsets(nums) -> {{}, {1}, {2}, {1, 2}} adds back last -> {{}, {1}, {2}, {1, 2}, {3}, {1, 3}, {2, 3}, {1, 2, 3}}.

vector<vector<int>> subsets(vector<int>& nums) {
  vector<vector<int>> result;

  // recursion ending condition, we return an empty vector
  if (nums.size() <= 0) {
    result.push_back(nums);
    return result;
  }

  // sort the input numbers
  std::sort(nums.begin(), nums.end());

  // get the last element from the input numbers
  // this way we can make sure when we push back
  // in the recursive call, the biggest element are at the back
  int last = nums[nums.size() - 1];
  nums.erase(nums.end() - 1);

  // recursively construct the subsets
  for (vector<int> e : subsets(nums)) {
    result.push_back(e);
    e.push_back(last);
    result.push_back(e);
  }

  return result;
}
---
Recursive (Backtracking)

This is a typical problem that can be tackled by backtracking. Since backtracking has a more-or-less similar template, so I do not give explanations for this method.

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> subs;
        vector<int> sub;  
        genSubsets(nums, 0, sub, subs);
        return subs; 
    }
    void genSubsets(vector<int>& nums, int start, vector<int>& sub, vector<vector<int>>& subs) {
        subs.push_back(sub);
        for (int i = start; i < nums.size(); i++) {
            sub.push_back(nums[i]);
            genSubsets(nums, i + 1, sub, subs);
            sub.pop_back();
        }
    }
};
Iterative

This problem can also be solved iteratively. Take [1, 2, 3] in the problem statement as an example. The process of generating all the subsets is like:

Initially: [[]]
Adding the first number to all the existed subsets: [[], [1]];
Adding the second number to all the existed subsets: [[], [1], [2], [1, 2]];
Adding the third number to all the existed subsets: [[], [1], [2], [1, 2], [3], [1, 3], [2, 3], [1, 2, 3]].
Have you got the idea :-)

The code is as follows.

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> subs(1, vector<int>());
        for (int i = 0; i < nums.size(); i++) {
            int n = subs.size();
            for (int j = 0; j < n; j++) {
                subs.push_back(subs[j]); 
                subs.back().push_back(nums[i]);
            }
        }
        return subs;
    }
}; 
Bit Manipulation

This is the most clever solution that I have seen. The idea is that to give all the possible subsets, we just need to exhaust all the possible combinations of the numbers. And each number has only two possibilities: either in or not in a subset. And this can be represented using a bit.

There is also another a way to visualize this idea. That is, if we use the above example, 1 appears once in every two consecutive subsets, 2 appears twice in every four consecutive subsets, and 3 appears four times in every eight subsets, shown in the following (initially the 8 subsets are all empty):

[], [], [], [], [], [], [], []

[], [1], [], [1], [], [1], [], [1]

[], [1], [2], [1, 2], [], [1], [2], [1, 2]

[], [1], [2], [1, 2], [3], [1, 3], [2, 3], [1, 2, 3]

The code is as follows.

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int num_subset = pow(2, nums.size()); 
        vector<vector<int> > res(num_subset, vector<int>());
        for (int i = 0; i < nums.size(); i++)
            for (int j = 0; j < num_subset; j++)
                if ((j >> i) & 1)
                    res[j].push_back(nums[i]);
        return res;  
    }
};
Well, just a final remark. For Python programmers, this may be an easy task in practice since the itertools package has a function combinations for it :-)
---
class Solution {
    vector<vector<int>> res;
    void addSubset(std::vector<int> &inset,std::vector<int> &rest) {
        if(rest.empty()) res.push_back(inset);
        else {
            auto x=rest.back(); rest.pop_back();
            addSubset(inset,rest);

            inset.push_back(x);
            addSubset(inset,rest);

            inset.pop_back();
            rest.push_back(x);
        }
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        res.clear();
        std::sort(nums.begin(),nums.end(),[](const int x,const int y) { return x>y; });
        std::vector<int> inset, &rest=nums;
        addSubset(inset,rest);
        return res;
    }
};
---
vector<vector<int>> subsets(vector<int>& nums) {
    vector<vector<int>> ret;
    ret.push_back(vector<int>());
    sort(nums.begin(), nums.end());
    for (const auto& i:nums) {
        vector<vector<int>> sub(ret);
        for (auto& j:sub) j.push_back(i);
        ret.insert(ret.end(), sub.begin(), sub.end());
    }
    return ret;
}
---
class Solution {
public:
    void subsets_helper(vector<int>& s, int m, vector<int>* ans, vector<vector<int> >* res) {
        if (!ans->empty()) {
            res->emplace_back(*ans);
        }
        for (int i = m; i < s.size(); ++i) {
            ans->emplace_back(s[i]);
            subsets_helper(s, i + 1, ans, res);
            ans->pop_back();
        }
    }

    vector<vector<int> > subsets(vector<int> &S) {
        sort(S.begin(), S.end());
        vector<int> ans;
        vector<vector<int> > result;
        result.emplace_back(vector<int>{});
        subsets_helper(S, 0, &ans, &result);
        return result;
    }
};
---
class Solution {
public:
    void subsets(vector<vector<int> >& out, const vector<int>& nums,vector<int>& picked_subset,int i)
    {
        if (i==nums.size())
        {
            out.push_back(picked_subset);
            return;
        }
        subsets(out,nums,picked_subset,i+1);
        picked_subset.push_back(nums[i]);
        subsets(out,nums,picked_subset,i+1);
        picked_subset.pop_back();
    }
    vector<vector<int> > subsets(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int> > out;
        vector<int> picked_subset;
        subsets(out,nums,picked_subset,0);
        return out;
    }
};

---
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ret;
        vector<int> v;
        ret.push_back(v);
        for (int i = 0; i < nums.size(); i++){
            int n = ret.size();
            for (int j = 0; j < n; j++){
                v = ret[j];
                v.push_back(nums[i]);
                ret.push_back(v);
            }
        }
        return ret;
    }
};
--
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int> > rtn;
        sort(nums.begin(), nums.end());
        int setsize = nums.size();
        int maxval = pow(2,setsize);

        for(int i = 0; i < maxval; i++){
            vector<int> temp;
            for(int j = 0; j<=setsize;j++){
                if((1<<j)&(i)) temp.push_back(nums[j]);
            }
            rtn.push_back(temp);
        }
        return rtn;
    }
};
---
void dfs(vector<int>& nums, int i, vector<int>& output, vector<vector<int>> &result) {
    if (i == nums.size()) {
        return;
    }
    for (int j = i; j<nums.size(); j++) {
        output.push_back(nums[j]);
        result.push_back(output);
        dfs(nums,j+1,output,result);
        output.pop_back();
    }
}
vector<vector<int>> subsets(vector<int>& nums) {
    // the question is asking for nondescending order, then we should sort it first
    sort(nums.begin(), nums.end());
    // the question asks us to print out all possible subsets. it can usually be solved DFS
    // the tree looks like this for 1,2,3
    //              root
    //           1    2     3
    //          2 3  3 
    //         3     
    vector<int> output;
    vector<vector<int>> result;
    result.push_back(output);
    dfs(nums, 0, output, result);
    return result;
}
---
class Solution { public: vector<vector > subsets(vector &S) {

vector<vector<int> > result,tempRe;
vector<int> tempVec;
result.push_back(tempVec);

sort(S.begin(),S.end());

for(vector<int>::iterator it = S.begin();it != S.end();it++)
{
    tempRe = result;
    for(vector<vector<int> >::iterator itvec = tempRe.begin();itvec!= tempRe.end();itvec++)
    {
        itvec->push_back(*it);
    }
    result.insert(result.begin(),tempRe.begin(),tempRe.end());
}

return result;

}
};


---
class Solution {
public:
vector<vector<int> > subsets(vector<int> &S) {
    vector<vector<int> > res(1, vector<int>());
    sort(S.begin(), S.end());

    for (int i = 0; i < S.size(); i++) {
        int n = res.size();
        for (int j = 0; j < n; j++) {
            res.push_back(res[j]);
            res.back().push_back(S[i]);
        }
    }

    return res;
  }
};

--
vector<vector > subsets(vector &S) { vector<vector > ret; vector subset;

for (int i = 0; i < (1 << S.size()); i++)
{
    subset.clear();
    for (int j = 0; j < S.size(); j++)
    {
        if ((1 << j) & i)
            subset.push_back(S[j]);
    }
    sort(subset.begin(), subset.end());
    ret.push_back(subset);
}

return ret;
}

----
Basic idea is to let the bit representing whether an element is required. Computation complexity is not taking serious care as the resulting set is to the scale of 2^N. The additional N in the loop is not the major factor to the problem. With DP or DFS, the generation of 2^N result can not be avoid anyway.

**public class Solution {
        public List<List<Integer>> subsets(int[] S) {
            List<List<Integer>> results = new ArrayList<List<Integer>>();
            Arrays.sort(S);
            for (int i=0;i<1<<S.length;i++)
            {
                List<Integer> result =  new ArrayList<Integer>();
                for(int j=0;j<S.length;j++)
                {
                    if ((i&(1<<j))!=0) result.add(S[j]);
                }
                results.add(result);
            }
            return results;
        }
    }**
---
/*
   LEgend:
        #S -> size of input set
        #SS(n) -> total number of subsets for a set with size n (i.e 2^n)
        S(i) ->ith element of input set
        SS(i) -> ith element of the set of subsets of S (starting from 0)
        SSn = set of Subset for Sn
        SS(#SS(n)-1) -> Last element in SSn

   Logic:
        #SS(n)= 2 * #SS(n-1)
        => SSn = SSn-1 U { {SS(0),S(n)} , {SS(1),S(n)} , ...  , {SS(#SS(n-1)-1),S(n)} }

   Explanation :      
    In simple words,I am using the logic of Dynamic Programming and breaking the problem in smaller subproblems

    eg. S={1,2}
    SS2 = { { } , {1} , {2} , {1,2} }

    now to get the subset for {1,2,3} we add the element 3 
     in each of the solution set of SS and with this new set do union of SS

    SS3 = SS2 U { {3} , {1,3} , {2,3} , {1,2,3} }
        = { {} , {1} , {2} , {1,2} , {3} , {1,3} , {2,3} , {1,2,3} }  
*/

    vector<vector<int> > subsets(vector<int> &S) {
        vector <int> temp;
        vector<vector<int> >ans;
        ans.push_back(temp);   //Enters null set
        int len=S.size();
        int len2;
        if(len==0)
         return ans;

        sort(S.begin(),S.end());

        for(int i=0 ; i<len ; i++)   //Traverses the whole input array
        {    
            len2=ans.size();
          // Since we cannot append the new number along with the null set therefore this is done outside the loop
            temp.clear();
            temp.push_back(S[i]);
            ans.push_back(temp);

            for(int j=1 ; j<len2 ; j++)
            {
                vector<int> temp2(ans[j]);
                temp2.push_back(S[i]);
                ans.push_back(temp2);
            }
        }
        return ans;
    }
--
For every element it has two options: 1. Either it is in set. 2. or it is NOT in set. I used this concept to write this code.

class Solution {
public:
    vector<vector<int> > res;

    void findsub(vector<int> &s, vector<int> &v, int i)
    {
        if(i==s.size())
        {
            res.push_back(v);
            return;
        }

        findsub(s, v, i+1);

        v.push_back(s[i]);
        findsub(s, v, i+1);

        v.pop_back();   //backtrack
        return;

    }
    vector<vector<int> > subsets(vector<int> &S) {

        sort(S.begin(), S.end());
        vector<int> v;
        findsub(S,v, 0);
        return res;

    }
};

---
using condition temp.back() < source[i] ,guarantee non-descending order.

class Solution {
public:
    vector<vector<int> > res;
    vector<int> source;
    vector<vector<int> > subsets(vector<int> &S) {
        res.clear();
        source = S;
        vector<int> t;
        dfs(t);
        return res;
    }
    void dfs(vector<int> temp){
        res.push_back(temp);
        for(int i=0;i<source.size();i++){
            if(temp.empty()||temp.back() < source[i]){
                temp.push_back(source[i]);
                dfs(temp);
                temp.pop_back();
            }
        }
    }
};
---
I am a big recursive person. And I would like to think everything in a recursive way.

For the case of this problem, using a loop seems definitely to be a more elegant solution. But I would still like to share my recursive solution with you guys.

I make recursive call trying to go over the vector from left to right. For each number in vector, it has to options: show in the subset, or not show in the subset. There for each recursive call will generate two more recursive calls. And in the base case, we add the vector to result set.

Hope you liked my solution.

class Solution {
public:
    void subsets_helper(vector<int> tmpVec, vector<vector<int>>& result, vector<int>& S, int level){
        if(level==0) result.push_back(tmpVec);
        else{
            vector<int> newVec0 = tmpVec; newVec0.push_back(S[S.size()-level]);
            vector<int> newVec1 = tmpVec;
            subsets_helper(newVec0, result, S, level-1);
            subsets_helper(newVec1, result, S, level-1);
        }
    }

    vector<vector<int> > subsets(vector<int> &S) {
        sort(S.begin(), S.end());
        vector<vector<int>> result;
        vector<int> tmpVec;
        subsets_helper(tmpVec, result, S, S.size());
        return result;
    }
};

--
class Solution {
public:
    vector<vector<int> > subsets(vector<int> &S) {
        sort (S.begin(), S.end());
        int elem_num = S.size();
        int subset_num = pow (2, elem_num);
        vector<vector<int> > subset_set (subset_num, vector<int>());
        for (int i = 0; i < elem_num; i++)
            for (int j = 0; j < subset_num; j++)
                if ((j >> i) & 1)
                    subset_set[j].push_back (S[i]);
        return subset_set;
    }
};
----
My idea was to start out with an empty subset and either take or don't take the next element in the input array. Here's how it goes down for input [1,2,3]:

start with

[] // empty set is always a subset
then either take or not take the next element (1), this doubles the result size:

[]   // not take 1
[1] //      take 1 + new
then take or not take the next element: 2

[]    // not take 1, not take 2
[2]   // not take 1,     take 2 + new
[1]   //     take 1, not take 2
[1,2] //     take 1,     take 2 + new
and finally take or not take 3.

[]      // not take 1, not take 2, not take 3
[3]     // not take 1, not take 2,     take 3 + new
[2]     // not take 1,     take 2, not take 3
[2,3]   // not take 1,     take 2,     take 3 + new
[1]     //     take 1, not take 2, not take 3
[1,3]   //     take 1, not take 2,     take 3 + new
[1,2]   //     take 1,     take 2, not take 3
[1,2,3] //     take 1,     take 2,     take 3 + new
And we're done, we have all 2^3 = 8 subsets generated.

It is possible to generate these with a simple loop, there's only one trick here, the variable size. It's usually a good practice to cache method call results, but now it is cached for a different reason: because it changes in every iteration. If we don't want to end up with an infinite loop, we have to remember how many results were available in the previous iteration, which is exactly the size() of the result at the beginning of the current iteration.

public List<List<Integer>> subsets(int[] nums) {
    Arrays.sort(nums); // make sure subsets are ordered
    List<List<Integer>> result = new ArrayList<>();
    result.add(new ArrayList<>()); // start with empty set
    for (int i = 0; i < nums.length; ++i) {
        for (int j = 0, size = result.size(); j < size; ++j) { // remember
            List<Integer> subset = new ArrayList<>(result.get(j)); // copy a new one
            subset.add(nums[i]); // expand
            result.add(subset); // collect
        }
    }
    return result;
}
It is also necessary to order the input to satisfy the requirement:

Elements in a subset must be in non-descending order.
Because i is increasing it means that whatever we take from nums will also be in increasing order.

The other requirement:

The solution set must not contain duplicate subsets.
is automatically guaranteed by the input specification and the algorithm walking indices straight and once:

Given a set of distinct integers, nums, return all possible subsets. [emphasis mine]

