vector<vector<int>> subsetsWithDup(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    vector<vector<int>> res;
    vector<int> path;
    dfs(nums, 0, path, res);
    return res;
}

void dfs(vector<int>& nums, int index, vector<int>& path, vector<vector<int>>& res) {
    res.push_back(path);
    for (unsigned int i = index; i < nums.size(); i++) {
        if (i > index && nums[i] == nums[i-1])
            continue;
        path.push_back(nums[i]);
        dfs(nums, i+1, path, res);
        path.pop_back();
    }
}
--
bool cmp(const vector<int>& v1, const vector<int>& v2) {
    int len1 = v1.size(), len2 = v2.size();
    if (len1 != len2) return len1 < len2;
    for (int i = 0; i < len1; i++) {
        if (v1[i] != v2[i]) return v1[i] < v2[i];
    }
    return true;
}
class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ret;
        vector<int> vec;
        int i, j, len = nums.size(), size = 1 << len;
        for (i = 0; i < size; i++) {
            vec.clear();
            for (j = 0; j < len; j++) {
                if ((i >> j) & 1) vec.push_back(nums[j]);
            }
            ret.push_back(vec);
        }
        sort(ret.begin(), ret.end(), cmp);
        vector<vector<int>>::iterator it = unique(ret.begin(), ret.end());
        ret.resize(distance(ret.begin(), it));
        return ret;
    }
};
---
When num[i] == num[i-1] , num[i] is only needed to be added to the vectors which are generated from the previous one, which starts from ans[sz-pre_sz]

class Solution {
    public:
        vector<vector<int>> subsetsWithDup(vector<int>& nums) {
            vector<vector<int>> ans(1, vector<int>());

            if (nums.empty()) return ans;

            sort(nums.begin(), nums.end());

            int pre_sz = 0;
            for (int i=0; i<nums.size(); ++i) {
                int sz = ans.size();

                for (int j=0; j<sz; ++j) {
                    if (i>0 && nums[i] == nums[i-1] && j < sz - pre_sz) {
                        continue;
                    }

                    ans.push_back(ans[j]);
                    ans.back().push_back(nums[i]);
                }

                pre_sz = ans.size() - sz;
            }

            return ans;
        }
    };
---
class Solution {
public:
    void f(vector<int>& nums,vector<vector<int>>&result,int i,vector<int>&temp){
        if(i==nums.size()){
            result.push_back(temp);
            return;
        }
        temp.push_back(nums[i]);
        int j=i+1;
        f(nums,result,j,temp);
        temp.pop_back();
        while(j<nums.size()&&nums[j]==nums[i]){j++;}
        f(nums,result,j,temp);
        return;

    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int>temp;
        vector<vector<int>>result;
        f(nums,result,0,temp);
        return result;
    }
};
--
class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> subs(1,vector<int>());
        int cursize,dpsize=1;
        for(int i=0;i<nums.size();i++){
            cursize=subs.size();
            if(i>0&&nums[i]!=nums[i-1])dpsize=cursize;
            for(int j=cursize-dpsize;j<cursize;j++){
                subs.push_back(subs[j]);
                subs.back().push_back(nums[i]);
            }
        }
        return subs;
    }
};
---
class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> subsets;
        vector<int> subset;
        subsetsWithDupWorker(nums, subsets, subset, 0);
        return subsets;
    }
private:
    void subsetsWithDupWorker(const vector<int>& nums, vector<vector<int>>& subsets, vector<int>& subset, int begin) {
        subsets.push_back(subset);
        for (int i = begin; i < nums.size(); i++) {
            if (i != begin && nums[i] == nums[i-1]) continue;
            subset.push_back(nums[i]);
            subsetsWithDupWorker(nums, subsets, subset, i+1);
            subset.pop_back();
        }
    }
};
--
vector<vector<int>> build(vector<vector<int>> &ret, vector<int> &nums, int start)
{
    if (start >= nums.size())
    {
        ret.push_back(vector<int>());                      // pi. null.
        return ret;
    }

    int cur = nums[start];
    int next = start;
    while (next<nums.size() && cur == nums[next]) next++;  // count the duplicates

    build(ret, nums, next);                                // direction: right to left
    int size = ret.size();
    vector<vector<int>> rocknroll = ret;                   // copy the previous values

    for (int i = 1; i <= next - start; i++)
    {
        for (int j = 0; j<size; j++) rocknroll[j].insert(rocknroll[j].begin(), cur); // insert a number in front of the previous values
        for (int j = 0; j<size; j++) ret.push_back(rocknroll[j]); // insert the values after the previous values.
    }

    return ret;
}

vector<vector<int>> subsetsWithDup(vector<int>& nums) {
    vector<vector<int>> ret;
    sort(nums.begin(), nums.end());
    return build(ret, nums, 0);
}
---
The idea is to first remove the duplicates (keeping record of the number of duplicates) and then perform a DFS. For example, for nums = [5, 6, 6], we first remove the duplicates and get sinNums = [5, 6], dups = [1, 2] (meaning that 5 appears once and 6 appears twice). After that, the following DFS is performed:

path = [] -> [5] -> [5, 6] -> [5, 6, 6] -> [6] -> [6, 6]

class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        if (nums.size() == 0)
            return vector<vector<int>>();
        vector<int> path;
        vector<vector<int>> res(1, path);
        sort(nums.begin(), nums.end());
        vector<int> sinNums(1, nums[0]), dups(1, 1);
        for (int i = 1; i < nums.size(); i++)
            if (nums[i] != nums[i - 1])
                sinNums.push_back(nums[i]), dups.push_back(1);
            else
                dups[dups.size() - 1]++;
        __subsetsWithDup(sinNums, dups, res, path, 0);
        return res;
    }

private:
    void __subsetsWithDup(vector<int>& nums, vector<int>& dups, vector<vector<int>>& res, vector<int>& path, int pos) {
        for (int j = pos; j < nums.size(); j++) {
            int count = 0;
            for (int i = 0; i < dups[j]; i++) {
                path.push_back(nums[j]);
                res.push_back(path);
                __subsetsWithDup(nums, dups, res, path, j + 1);
                count++;
            }
            path.erase(path.end() - count, path.end());
        }
        return ;
    }
};
--
class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {

        vector< vector<int> > res;
        res.push_back( vector<int>() );

        sort(nums.begin(), nums.end());

        //nCurr: the number of entries added to res when processing nums[i];
        //nPrev: the number of entries added to res when processing nums[i-1];
        int nCurr=0, nPrev=0;

        for(int i=0; i<nums.size(); i++)
        {

            int nSize=res.size();
            nCurr=0;

            for(int j=0;j<nSize; j++)
            {
                //skip the entries that were not added when processing nums[i-1];
                if(i>0 && nums[i]==nums[i-1] && j<nSize-nPrev ) 
                    continue;

                res.push_back( res[j] );
                res.back().push_back(nums[i]);

                nCurr++;
            }
            nPrev=nCurr;
        }

        return res;
    }
};
--
Solution #1 BFS

public IList<IList<int>> SubsetsWithDup(int[] nums) {
    List<IList<int>> result = new List<IList<int>>();
    result.Add(new List<int>());
    Array.Sort(nums);
    int len, lastLength = 0;
    for (int i = 0; i < nums.Length; i++){
        List<IList<int>> newResult = new List<IList<int>>();
        len = i > 0 && nums[i] == nums[i - 1] ? lastLength : 0;
        lastLength = result.Count;
        while(len < result.Count){
            List<int> nr = new List<int>(result[len++]);
            nr.Add(nums[i]);
            newResult.Add(nr);
        }
        result.AddRange(newResult);
    }
    return result;
}
Solution #2 DFS

public IList<IList<int>> SubsetsWithDup(int[] nums) {
    Array.Sort(nums);
    IList<IList<int>> result = new List<IList<int>>();
    dfs(new List<int>(), nums, 0, result);
    return result;
}

private void dfs(IList<int> curList, int[] nums, int iCur, IList<IList<int>> result){
    if(iCur == nums.Length){
        result.Add(new List<int>(curList));
        return;
    }
    if(curList.Count == 0 || curList[curList.Count - 1] != nums[iCur])
        dfs(curList, nums, iCur + 1, result);
    curList.Add(nums[iCur]);
    dfs(curList, nums, iCur + 1, result);
    curList.RemoveAt(curList.Count - 1);
}
//
//bitmap 12ms
vector<vector<int>> subsetsWithDup(vector<int>& nums) {
    n = nums.size();
    vector<vector<int>> res(1, vector<int>());
    if (n == 0) return res;
    sort(nums.begin(), nums.end());
    int mask = 0, total = pow(2, n), tmpi, tmpj, lastnum;
    bool dp;
    for (int i = 1; i < total; i++) {
        dp = false;
        vector<int> tmp;
        lastnum = -1;
        for (int j = 0; j < n; j++) {
            if (i & (1 << j)) {
                //check if duplicate
                tmpi = nums[j];
                if (nums[j] == lastnum) {
                    tmpj = j - 1;
                    while (tmpj >= 0 && nums[tmpj] == lastnum) {
                        if (!(i & (1 << tmpj))) {
                            dp = true;
                            break;
                        }
                        tmpj--;
                    }
                }
                if (dp) break;
                tmp.push_back(tmpi);
            }
            lastnum = nums[j];
        }
        if (dp) continue;
        res.push_back(tmp);
    }

    return res;
}

//recursive 8ms
vector<vector<int>> res;
int n;
void generate(vector<int>& num, vector<int>& tmp, int k) {
    res.push_back(tmp);
    for (int i = k; i < n; i++) {
        tmp.push_back(num[i]);
        generate(num, tmp, i + 1);
        tmp.pop_back();
        while (i < n - 1 && num[i] == num[i + 1]) {
            i++;
        }
    }
}

vector<vector<int>> subsetsWithDup3(vector<int>& nums) {
    n = nums.size();
    vector<int> tmp;
    sort(nums.begin(), nums.end());
    generate(nums, tmp, 0);
    return res;
}

//another recursive 12ms
    vector<vector<int>> subsetsWithDup2(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> res(1, vector<int>());
        if (n == 0) return res;
        sort(nums.begin(), nums.end());
        int m, tmpi;
        for (int i = 0; i < n; i++) {
            tmpi = 1;
            while (i - tmpi >= 0 && nums[i - tmpi] == nums[i]) tmpi++;
            tmpi--;
            m = res.size();
            for (int j = 0; j < m; j++) {
                if (tmpi > 0 && (res[j].empty() || res[j].size() < tmpi || res[j][res[j].size() - tmpi] != nums[i])) continue;
                vector<int> tmp = res[j];
                tmp.push_back(nums[i]);
                res.push_back(tmp);
            }
        }
        return res;
    }

//
class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        n=nums.size();
        vector<int> vec;
        getSubset(nums,vec,0);
        return res;
    }
    void getSubset(vector<int> &nums, vector<int> vec, int i)
    {
        if(i==n)
        {
            res.push_back(vec);
            return;
        }
        int j=i+1;
        while(j<n&&nums[j]==nums[i])
            j++;
        int k=j-i;
        getSubset(nums,vec,j);
        for(int m=0;m<k;m++)
        {
            vec.push_back(nums[i]);
            getSubset(nums,vec,j);
        }
    }
private:
    vector<vector<int>> res;
    int n;
};
//
The characteristics of C++ reference is an outstanding tool for backtracking algorithm!

let us use [1,2,3,4] as an example to explain my solution:

subsets([1,2,3,4]) = []
                     // push(1)
                     [1, subsets([2,3,4])] // if push N times in subsets([2,3,4]), the pop times is also N, so vec is also [1] after backtrack.
                     // pop(), push(2)
                     [2, subsets([3,4])]
                     // pop(), push(3)
                     [3, subsets([4])]
                     // pop(), push(4)
                     [4, subsets([])]
                     // pop()
Accepted 10ms c++ solution use backtracking for Subsets

class Solution {
public:
    std::vector<std::vector<int> > subsets(std::vector<int> &nums) {
        std::sort(nums.begin(), nums.end());
        std::vector<std::vector<int> > res;
        std::vector<int> vec;
        subsets(res, nums, vec, 0);
        return res;
    }
private:
    void subsets(std::vector<std::vector<int> > &res, std::vector<int> &nums, std::vector<int> &vec, int begin) {
        res.push_back(vec);
        for (int i = begin; i != nums.size(); ++i) {
            vec.push_back(nums[i]);
            subsets(res, nums, vec, i + 1);
            vec.pop_back();
        }
    }
};
Accepted 10ms c++ solution use backtracking for Subsets II

class Solution {
public:
    std::vector<std::vector<int> > subsetsWithDup(std::vector<int> &nums) {
        std::sort(nums.begin(), nums.end());
        std::vector<std::vector<int> > res;
        std::vector<int> vec;
        subsetsWithDup(res, nums, vec, 0);
        return res;
    }
private:
    void subsetsWithDup(std::vector<std::vector<int> > &res, std::vector<int> &nums, std::vector<int> &vec, int begin) {
        res.push_back(vec);
        for (int i = begin; i != nums.size(); ++i)
            if (i == begin || nums[i] != nums[i - 1]) { 
                vec.push_back(nums[i]);
                subsetsWithDup(res, nums, vec, i + 1);
                vec.pop_back();
            }
    }
};
//
vector<vector<int>> subsetsWithDup(vector<int>& nums) {
    vector<vector<int>> ret;
    ret.push_back(vector<int>());
    sort(nums.begin(), nums.end());
    vector<vector<int>> sub;
    for (int i = 0; i < nums.size(); ++i) {
        if (i == 0 || nums[i] != nums[i-1]) sub = ret;
        for (auto& j:sub) j.push_back(nums[i]);
        ret.insert(ret.end(), sub.begin(), sub.end());
    }
    return ret;
}
--
The idea is to make sure that every tmp.push_back(S[i]) can make a new subset, and then push it in the res.

void helper(vector<int> tmp,vector<vector<int>> &res,vector<int> &S, int start){
    res.push_back(tmp);

    int n=S.size();

    for(int i=start;i<n;i++){
        if(i>start&&S[i]==S[i-1])continue;//skip the duplicate element

        tmp.push_back(S[i]);
        helper(tmp,res,S,i+1);
        tmp.pop_back();
    }
}
vector<vector<int> > subsetsWithDup(vector<int> &S) {
    vector<vector<int>> res;
    vector<int> tmp;
    sort(S.begin(),S.end());

    helper(tmp,res,S,0);

    return res;
}
-----
vector<vector<int> > subsetsWithDup(vector<int> &S) {
    vector<vector<int>> result = {{}};
    if(S.size()==0)
    {
        return result;
    }

    sort(S, 0, S.size()-1);

    vector<vector<int>> temp;
    vector<vector<int>> last;

    for(int i=0;i<S.size();i++)
    {
        if(i>0 && S[i] == S[i-1])
        {
            temp = last;
        }
        else
        {
            temp = result;
        }

        last.clear();
        for(int j=0;j<temp.size();j++)
        {
            temp[j].push_back(S[i]);
            last.push_back(temp[j]);
            result.push_back(temp[j]);
        }
    }

    return result;

}
---
class Solution {
public:
    vector<vector<int> > subsetsWithDup(vector<int> &S) {
        vector<vector<int> > result;
        result.push_back(vector<int>(0));
        sort(S.begin(), S.end());
        subsetRec(S, 0, S.size(), result, vector<int>(0));
        return result;
    }

    void subsetRec(vector<int>& a, int s, int n, vector<vector<int>>& result, vector<int> cur_vec) {
        if (s == n) {
            return;
        }

        for (int i = s; i < n; ++i) {
            // check to avoid duplicate numbers
            if  (i == s || a[i] != a[i-1]) {
                cur_vec.push_back(a[i]);
                result.push_back(cur_vec);
                subsetRec(a, i+1, n, result, cur_vec);
                cur_vec.pop_back();
            }
        }
    }
};
---
// bit operation: first get all results, finally delete the duplicates
vector<vector<int> > subsetsWithDup1(vector<int> &S) {
    sort(S.begin(), S.end());
    int len = S.size();
    int n = pow(2, len);
    vector<vector<int> > ans(n, vector<int>());

    for (int i = 0; i < len; ++i) {
        for (int j = 0; j < n; ++j) {
            if (j >> i & 1) ans[j].push_back(S[i]);
        }
    }

    sort(ans.begin(), ans.end());
    ans.resize(unique(ans.begin(), ans.end()) - ans.begin());
    return ans;
}

// iterative solution: ignore the duplicates directly
vector<vector<int> > subsetsWithDup(vector<int> &S) {
    sort(S.begin(), S.end());
    vector<vector<int> > ans(1, vector<int>());
    int len = S.size();
    int s = 0, e = 0;

    vector<int> tmp;
    for(int i = 0; i < len; ++i) {
        s = i >= 1 && S[i] == S[i-1] ? e : 0;
        e = ans.size();
        for(int j = s; j < e; ++j) {
            tmp = ans[j];
            tmp.push_back(S[i]);
            ans.push_back(tmp);
        }
    }

    return ans;
}
---
class Solution {
public:
    vector<vector<int> > subsetsWithDup(vector<int> &S) {
        sort(S.begin(),S.end());
        vector<vector<int>> results;
        vector<vector<int>> append;
        //from less to more
        for (unsigned i = 0; i < S.size(); ++i){
            if (i>0 && S[i] != S[i - 1]){
                append = results;
            }
            for (vector<vector<int>>::iterator iter = append.begin(); iter != append.end(); ++iter){
                iter->push_back(S[i]);
                results.push_back(*iter);
            }
            if (i ==0 || i > 0 && S[i] != S[i - 1]){
                vector<int> temp;
                temp.push_back(S[i]);
                append.push_back(temp);
                results.push_back(temp);
            }
        }
        vector<int> emp;
        results.push_back(emp);
        return results;
    }
};
---
void dfs(vector<int> &S, int start, vector<int> &output, vector<vector<int>> &result) {
    result.push_back(output);

    for (int i = start; i < S.size(); i++) {
        output.push_back(S[i]);
        dfs(S, i + 1, output, result);
        output.pop_back();
        // disable following line for subset I
        while (i + 1 < S.size() && S[i + 1] == S[i]) i++;
    }
}

vector<vector<int> > subsetsWithDup(vector<int> &S) {
    vector<vector<int>> result;
    vector<int> output;

    if (0 == S.size()) {
        result.push_back(output);
        return result;
    }

    sort(S.begin(), S.end());
    dfs(S, 0, output, result);
    return result;
}
---
class Solution {
public:
    void generate(vector<int> s, vector<int> v,vector<vector<int> >  &vt,int n)
    {
        if(n==s.size())
        {
            sort(v.begin(),v.end());
            vt.push_back(v);
            return;
        }
        if((n==0)||v.empty()||s[n]!=v.back())   //don't use duplicate item
        generate(s,v,vt,n+1);
        v.push_back(s[n]);
        generate(s,v,vt,n+1);

    }

    vector<vector<int> > subsetsWithDup(vector<int> &S) 
   {
        vector<vector<int> > vt;
        vector<int> v;
        sort(S.begin(),S.end());
        generate(S,v,vt,0);
        return vt;
    }
};
---
To solve this problem, it is helpful to first think how many subsets are there. If there is no duplicate element, the answer is simply 2^n, where n is the number of elements. This is because you have two choices for each element, either putting it into the subset or not. So all subsets for this no-duplicate set can be easily constructed: num of subset

(1 to 2^0) empty set is the first subset
(2^0+1 to 2^1) add the first element into subset from (1)
(2^1+1 to 2^2) add the second element into subset (1 to 2^1)
(2^2+1 to 2^3) add the third element into subset (1 to 2^2)
....
(2^(n-1)+1 to 2^n) add the nth element into subset(1 to 2^(n-1))
Then how many subsets are there if there are duplicate elements? We can treat duplicate element as a spacial element. For example, if we have duplicate elements (5, 5), instead of treating them as two elements that are duplicate, we can treat it as one special element 5, but this element has more than two choices: you can either NOT put it into the subset, or put ONE 5 into the subset, or put TWO 5s into the subset. Therefore, we are given an array (a1, a2, a3, ..., an) with each of them appearing (k1, k2, k3, ..., kn) times, the number of subset is (k1+1)(k2+1)...(kn+1). We can easily see how to write down all the subsets similar to the approach above.

    class Solution {
public:
    vector<vector<int> > subsetsWithDup(vector<int> &S) {
        vector<vector<int> > totalset = {{}};
        sort(S.begin(),S.end());
        for(int i=0; i<S.size();){
            int count = 0; // num of elements are the same
            while(count + i<S.size() && S[count+i]==S[i])  count++;
            int previousN = totalset.size();
            for(int k=0; k<previousN; k++){
                vector<int> instance = totalset[k];
                for(int j=0; j<count; j++){
                    instance.push_back(S[i]);
                    totalset.push_back(instance);
                }
            }
            i += count;
        }
        return totalset;
        }
};
---
If we want to insert an element which is a dup, we can only insert it after the newly inserted elements from last step.

vector<vector<int> > subsetsWithDup(vector<int> &S) {
    sort(S.begin(), S.end());
    vector<vector<int>> ret = {{}};
    int size = 0, startIndex = 0;
    for (int i = 0; i < S.size(); i++) {
        startIndex = i >= 1 && S[i] == S[i - 1] ? size : 0;
        size = ret.size();
        for (int j = startIndex; j < size; j++) {
            vector<int> temp = ret[j];
            temp.push_back(S[i]);
            ret.push_back(temp);
        }
    }
    return ret;
}
