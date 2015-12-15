private List<List<Integer>> res = new ArrayList<>();

public List<List<Integer>> subsetsWithDup(int[] nums) {
    Arrays.sort(nums);
    addSubset(nums, 0, new ArrayList<Integer>());
    return res;
}

private void addSubset(int[] nums, int i, List<Integer> b) {
    res.add(b);
    for (int j = i; j < nums.length; j++) {
        List<Integer> c = new ArrayList<>(b);
        if (j == i || (j > i && nums[j] != nums[j-1])) {
            c.add(nums[j]);
            addSubset(nums, j+1, c);
        }
    }
}
//
Recursion solution:

public class Solution {
    Set<Integer> hash = new HashSet<>();
    List<List<Integer>> res = new ArrayList<>();
    int n;
    int[] nums;

    public void search(List<Integer> l, int p) {
        if (p == n) {
            int h = l.hashCode();
            if (!hash.contains(h)) {
                hash.add(h);
                res.add(new ArrayList<>(l));
            }
            return;
        }
        l.add(nums[p]);
        search(l, p+1);
        l.remove(l.size()-1);
        search(l, p+1);
    }

    public List<List<Integer>> subsetsWithDup(int[] nums) {
        this.n = nums.length; this.nums = nums;
        Arrays.sort(nums);
        search(new ArrayList<Integer>(), 0);
        return res;
    }
}
Non-recursion solution:

public class Solution {
    public List<List<Integer>> subsetsWithDup(int[] nums) {
        List<List<Integer>> res = new ArrayList<>();
        List<Integer> temp = new ArrayList<>();
        res.add(temp);
        Arrays.sort(nums);
        int l = 0, k;
        for (int i = 0; i < nums.length; i++) {
            if (i == 0 || nums[i] != nums[i-1])
                l = res.size();
            k = res.size();
            for (int j = k-l; j < k; j++) {
                temp = new ArrayList<>(res.get(j));
                temp.add(nums[i]);
                res.add(temp);
            }
        }
        return res;
    }
}
//
public List<List<Integer>> subsetsWithDup(int[] nums) {

    Arrays.sort(nums);
    List<List<Integer>> ans = new LinkedList<List<Integer>>();
    if (nums.length < 1)
        return ans;
    subsetsWithDupHelper(ans, nums, new LinkedList<Integer>(), 0);

    return ans;

}

private void subsetsWithDupHelper(List<List<Integer>> ans, int[] nums,
        LinkedList<Integer> curAns, int start) {
    ans.add(curAns);
    if (start == nums.length)
        return;

    for (int i = start; i < nums.length; i++) {
        if (i == start || nums[i] != nums[i - 1]) {
            LinkedList<Integer> newCur = new LinkedList<Integer>(curAns);
            newCur.add(nums[i]);
            subsetsWithDupHelper(ans, nums, newCur, i + 1);
        }
    }
---
public class Solution {
    int justRmvd = Integer.MIN_VALUE;

    public List<List<Integer>> subsetsWithDup(int[] nums) {
        List<List<Integer>> results = new ArrayList();

        if(nums.length>0) {
            Arrays.sort(nums);
            helper(nums, 0, new ArrayList<Integer>(), results);
        }
        return results;
    }

    void helper(int[] nums, int index, List<Integer> path, List<List<Integer>> results) {
        results.add(new ArrayList<Integer>(path));

        for(int i=index; i<nums.length; i++) {
            if(justRmvd==nums[i]) continue;

            path.add(nums[i]);
            helper(nums, i+1, path, results);
            justRmvd = path.remove(path.size()-1);
        }
    }
}
--
public class Solution {
    public List<List<Integer>> subsetsWithDup(int[] nums) {
        List<List<Integer>> res = new ArrayList<List<Integer>>();
        List<Integer> sublist = new ArrayList<Integer>();

        Arrays.sort(nums);

        for(int i = 0; i <= nums.length; i++){
            getSubsets(res, sublist, nums, i, 0);
        }

        return res;
    }
    private void getSubsets(List<List<Integer>> res, List<Integer> sublist, int[] nums, int k, int position){
        if(sublist.size() == k){
            res.add(new ArrayList<Integer>(sublist));
            return;
        }

        for(int i = position; i < nums.length;){
            sublist.add(nums[i]);
            getSubsets(res, sublist, nums, k, i+1);
            sublist.remove(sublist.size()-1);
            i++;
            while (i < nums.length && nums[i] == nums[i - 1]) {
                i++;
            }
        }

        return;
    }
}

--
public List<List<Integer>> subsetsWithDup(int[] nums) {
    Arrays.sort(nums);
    List<List<Integer>> res = new ArrayList<>();
    List<Integer> each = new ArrayList<>();
    helper(res, each, 0, nums);
    return res;
}
public void helper(List<List<Integer>> res, List<Integer> each, int pos, int[] n) {
    if (pos <= n.length) {
        res.add(each);
    }
    int i = pos;
    while (i < n.length) {
        each.add(n[i]);
        helper(res, new ArrayList<>(each), i + 1, n);
        each.remove(each.size() - 1);
        i++;
        while (i < n.length && n[i] == n[i - 1]) {i++;}
    }
    return;
}
--
public class Solution {
    public List<List<Integer>> subsetsWithDup(int[] nums) {
        Arrays.sort(nums);
        List<List<Integer>> result = new ArrayList<List<Integer>>();
        dfs(nums,0, new ArrayList<Integer>(), result);
        return result;
    }
    void dfs(int[] nums, int start, ArrayList<Integer> list, List<List<Integer>> result) {
        result.add(new ArrayList<Integer>(list));
        for(int i = start; i < nums.length; i++) {
            if(i > start && nums[i] == nums[i-1]) continue;
            list.add(nums[i]);
            dfs(nums,i+1,list, result);
            list.remove(list.size()-1);

        }
    }
}
//
public class Solution {
    public List<List<Integer>> subsetsWithDup(int[] nums) {
        Arrays.sort(nums);
        List<List<Integer>> result= new ArrayList<>();
        dfs(nums,0,new ArrayList<Integer>(),result);
        return result;
    }

    public void dfs(int[] nums,int index,List<Integer> path,List<List<Integer>> result){
        result.add(path);
        for(int i=index;i<nums.length;i++){
            if(i>index&&nums[i]==nums[i-1]) continue;
            List<Integer> nPath= new ArrayList<>(path);
            nPath.add(nums[i]);
            dfs(nums,i+1,nPath,result);
        }
    }
}
//
for duplication, like "1111",we only take the first one in the "for" loop

// if(i!= start && nums[i] == nums[i-1]) // continue;

public class Solution {
            public List<List<Integer>> subsetsWithDup(int[] nums) {
                List<List<Integer>> res = new ArrayList<List<Integer>>();
                List<Integer> subsets = new ArrayList<Integer>();
                res.add(new ArrayList());
                Arrays.sort(nums);
                doSubsets(nums,res,subsets,0);
                return res;
            }

            private void doSubsets(int[] nums, List res, List subsets, int start){
                for(int i=start; i<nums.length; i++){
                    if(i!= start && nums[i] == nums[i-1])
                        continue;
                    subsets.add(nums[i]);
                    res.add(new ArrayList(subsets));
                    doSubsets(nums,res,subsets,i+1);
                    subsets.remove(subsets.size()-1);
                }
            }
        }

--
We need to pay attention when there are duplicated elements in the sorted array. Up to the ith element, 'lists' actually stores all the possible sub-arrays until the last element smaller than num[i]. So this is a dp solution. For the array [1,2,2,2],

when i=0; lists ={[ ]};

when i=1; lsits ={[ ][1]}, next={[ ],[1]}+{[2],[1,2]}

when i=2; lists ={[ ],[1]}, next={[ ],[1]}+{[2],[1,2]}+{[2,2][1,2,2]} (We treat the duplicate elements {2,2} as one single number and add it to every list in 'lists')

when i=3; lists ={[ ],[1]} still, because num[i]==num[i-1].
next={[ ],[1]}+{[2],[1,2]}+{[2,2][1,2,2]}+{[2,2,2],[1,2,2,2]} (Treat {2,2,2} as one number)

public List<List<Integer>> subsetsWithDup(int[] num) {
    List<List<Integer>> lists=new ArrayList<List<Integer>>();
    lists.add(new LinkedList<Integer>());
    if(num.length==0) return lists;
    Arrays.sort(num);

    int dupCount=0;     
    List<List<Integer>> next=new ArrayList<List<Integer>>(lists);

    for(int i=0;i<num.length;i++){
        if(i!=0&&num[i]==num[i-1])  dupCount++;   //count the number of elements equal to num[i] up to now.
        else{
            dupCount=0;                     //when num[i]!=num[i-1], num[i] is a new number, reset dupCount
            next=new ArrayList<List<Integer>>(lists);             
        }

        for(List<Integer> list:lists){
            List<Integer> tmp=new LinkedList<Integer>(list);
            for(int count=0;count<=dupCount;count++){
                tmp.add(num[i]);
            }
            next.add(tmp);
        }

        if(i==num.length-1||num[i]!=num[i+1])       
            lists=next;
    }
    return lists;
}
--
public class Solution {
    public List<List<Integer>> subsetsWithDup(int[] num) {
        Arrays.sort(num);
        List<List<Integer>> lists = new ArrayList<>();
        int subsetNum = 1<<num.length;
        for(int i=0;i<subsetNum;i++){
            List<Integer> list = new ArrayList<>();
            boolean illegal=false;
            for(int j=0;j<num.length;j++){
                if((i>>j&1)==1){
                    if(j>0&&num[j]==num[j-1]&&(i>>(j-1)&1)==0){
                        illegal=true;
                        break;
                    }else{
                        list.add(num[j]);
                    }
                }
            }
            if(!illegal){
               lists.add(list); 
            }

        }
        return lists;
    }
}
The idea is using every bit to represent one element in the set. The total number is 2 to num.length. Then we need to avoid duplicates. After we sort the array, the same number will be adjacent to each other.

For example the set is {1,1,1}. We can get subset {} and {1} first. That's great. Then we need to pay attention. Suppose we have a subset x, which including the second 1 but not the first 1, x is a duplicate. That's why I write the predicate: if(j>0&&num[j]==num[j-1]&&(i>>(j-1)&1)==0){ illegal=true; break; }

Hope someone can explain it better. I will go to gym now.
--
Time complexity 2 ^ n, inside the second for loop, need check whether has duplicated elements, if has, skip, if not add the element

public class Solution {
    public List<List<Integer>> subsetsWithDup(int[] num) {
        List<List<Integer>> result = new ArrayList<List<Integer>>();
        result.add(new ArrayList());

        Arrays.sort(num);

        for(int i : num){
            List<List<Integer>> temp = new ArrayList<List<Integer>>();
            for(List<Integer> sub : result){
                List<Integer> inner = new ArrayList<Integer>(sub);
                inner.add(i);
                if(!result.contains(inner))
                    temp.add(inner);
            }
            result.addAll(temp);
        }
        return result;
    }
}
--
my method is simple, try to output all combination of the list and skip the same integer.

public class Solution {
public List<List<Integer>> subsetsWithDup(int[] num) {
    Arrays.sort(num);
    List<List<Integer>> result = new LinkedList<List<Integer>>();
    LinkedList<Integer> temp = new LinkedList<Integer>();
    Rec(num,result,temp,0);
    return result;
}
private static void Rec(int[] a,List<List<Integer>> result, LinkedList<Integer> temp, int current){
    result.add(new LinkedList(temp));
    for(int i=current;i<a.length;i++){
        if(i==current || a[i]!=a[i-1]){
            temp.add(a[i]);
            Rec(a,result,temp,i+1);
            temp.remove(temp.size()-1);
        }
    }
    return;
}
}
---
public List<List<Integer>> subsetsWithDup(int[] num) {
    Arrays.sort(num);
    List<List<Integer>> ans = new ArrayList<List<Integer>>();
    int len = num.length;
    if (len == 0) return ans; 

    ans.add(new ArrayList<Integer>()); // first, need to add the subset of num[0]
    ans.add(new ArrayList<Integer>());
    ans.get(1).add(num[0]);

    int nprev = 1; // this is the number of lists that the previous number was added in.
                 // if the current number is same as the prev one, it'll be only added in the 
                // lists that has the prev number.

    for (int i = 1; i < len ; ++i){
        int size = ans.size();
        if (num[i]!=num[i-1])   // if different
            nprev = size;        // this means add num[i] to all lists in ans;
        for (int j = size-nprev; j < size; ++j){
            List<Integer> l = new ArrayList<Integer>(ans.get(j));
            l.add(num[i]);
            ans.add(l);
        }
    }
    return ans;
}
---
public List<List<Integer>> subsetsWithDup(int[] num) {
    Arrays.sort(num);
    return subset(num, 0, new ArrayList<List<Integer>>());

}

public List<List<Integer>> subset(int[] num, int index, List<List<Integer>> newNext) {
    List<List<Integer>> result = new ArrayList<List<Integer>>();

    if (index >= num.length) {
        List<Integer> list = new ArrayList<Integer>();
        result.add(list);
        return result;
    }

    List<List<Integer>> nextList = subset(num, index + 1, newNext);
    List<List<Integer>> iterate = null;

    iterate = (index + 1 < num.length && num[index] == num[index+1]) ? newNext : nextList;
    for (List<Integer> l : iterate) {
        List<Integer> newList = new ArrayList<Integer>(l);
        newList.add(0, num[index]);
        result.add(newList);
    }

    newNext.clear();
    for (List<Integer> l : result) {
        newNext.add(l);
    }

    result.addAll(nextList);
    return result;
}
--
public List<List<Integer>> subsetsWithDup(int[] num) {
  Arrays.sort(num);
  List<List<Integer>> ret = new ArrayList<>();
  ret.add(new ArrayList<Integer>());

  int size = 0, startIndex;
  for(int i = 0; i < num.length; i++) {
    startIndex = (i >= 1 && num[i] == num[i - 1]) ? size : 0;
    size = ret.size();
    for(int j = startIndex; j < size; j++) {
      List<Integer> temp = new ArrayList<>(ret.get(j));
      temp.add(num[i]);
      ret.add(temp);
    }
  }
  return ret;
}
--
class Solution {
public:
    vector<vector<int> > subsetsWithDup(vector<int> &S) {
        vector<vector<int> > ret;
        ret.push_back(vector<int>());
        sort(S.begin(), S.end());
        for (int i = 0; i < S.size(); ) {
            int j = i;
            while (j < S.size() && S[j] == S[i]) j++;
            int size = ret.size();
            for (int len = 1; i + len <= j; len++) {
                for (int cnt = 0; cnt < size; cnt++) {
                    vector<int> subset(ret[cnt]);
                    for (int k = 0; k < len; k++) subset.push_back(S[i]);
                    ret.push_back(subset);
                }
            }
            i = j;
        }
        return ret;
    }
};
--
The most inner loop can be avoided.

vector<vector<int>> subsetsWithDup(vector<int>& nums) {
    vector<vector<int>> ret;
    ret.push_back(vector<int>());
    sort(nums.begin(), nums.end());
    for (int i = 0; i < nums.size(); ) {
        int j = i;
        while (j < nums.size() && nums[j] == nums[i]) j++;
        int size = ret.size();
        vector<int> tmp;
        for (int len = 1; i + len <= j; len++) {
            tmp.push_back(nums[i]);
            for (int cnt = 0; cnt < size; cnt++) {
                ret.push_back(ret[cnt]);
                ret.back().insert(ret.back().end(), tmp.begin(), tmp.end());
            }
        }
        i = j;
    }
    return ret;
}
--
Here is my solution using bit masks.

public class Solution {
public List<List<Integer>> subsetsWithDup(int[] num) {
    //Sort the input
    Arrays.sort(num);
    int numberSets = 1 << num.length;
    List<List<Integer>> solution = new LinkedList<>();
    for(int i = 0; i<numberSets; i++){
        List<Integer> subset = new LinkedList<Integer>();
        for(int j = 0; j< num.length; j++){
            if((i & (1 << j)) > 0){
                subset.add(num[j]);
            }
        }
        if(!solution.contains(subset))
            solution.add(subset);
    }

    return solution;
}
}
