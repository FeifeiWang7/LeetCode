public class Solution {
public List<List<Integer>> subsets(int[] nums) {
    List<List<Integer>> res = new ArrayList<List<Integer>>();
    if (nums.length == 0 || nums == null) {
        return res;
    }
    Arrays.sort(nums);
    for (int count = 0; count <= nums.length; count++) {
        search(count, 0, nums, new ArrayList<Integer>(), res);
    }
    return res;
}
public void search(int count, int start, int[] nums, List<Integer> temp, List<List<Integer>> res) {
    if (temp.size() == count) {
        res.add(temp);
        return;
    }
    for (int i = start; i < nums.length; i++) {
        List<Integer> newTemp = new ArrayList<Integer>(temp);
        newTemp.add(nums[i]);
        search(count, i + 1, nums, newTemp, res);
    }
}
}
---
public class Solution {
    public List<List<Integer>> subsets(int[] nums) {
        // sort, then DFS
        List<List<Integer>> result = new ArrayList<List<Integer>>();
        if (nums == null) {
            return result;
        }
        Arrays.sort(nums);
        subsetsHelper(0, nums, new ArrayList<Integer>(), result);
        return result;
    }

    private void subsetsHelper(int curr, int[] nums, List<Integer> prefix, List<List<Integer>> result) {
        if (curr == nums.length) {
            result.add(new ArrayList<Integer>(prefix));
            return;
        }
        // skip the curr number
        subsetsHelper(curr + 1, nums, prefix, result);
        // take the curr number
        prefix.add(nums[curr]);
        subsetsHelper(curr + 1, nums, prefix, result);
        prefix.remove(prefix.size()-1);
    }
}
---
public List<List<Integer>> subsets(int[] nums) {
    Arrays.sort(nums);
    List<List<Integer>> result = new ArrayList<>();
    if(nums==null || nums.length==0){
        result.add(new ArrayList<Integer>());
        return result;
    }
    List<Integer> internal = new ArrayList<Integer>();
    subSets(nums, 0, result,internal);
    result.add(new ArrayList<Integer>());
    return result;
}
private void subSets(int[] nums, int index, List<List<Integer>> result, List<Integer> internal){
    for(; index<nums.length;index++){
        internal.add(nums[index]);
        result.add(new ArrayList<Integer>(internal));
        subSets(nums,index+1,result,internal);
        internal.remove(internal.size()-1);
    }
}
---
public List<List<Integer>> subsets(int[] nums) {
    List<List<Integer>> result = new ArrayList();
    Arrays.sort(nums);
    int len = nums.length;
    int total = (int) Math.pow(2, len);
    for(int i=0;i<total;i++){
        int temp=i;
        List<Integer> row = new ArrayList<Integer>();
        for(int j=0;j<len;j++){
            if((temp&1)==1){
                row.add(nums[j]);
            }
            temp=temp>>1;
        }
        result.add(row);
    }
    return result;
}
---
public class Solution {
    public List<List<Integer>> subsets(int[] nums) {
        Arrays.sort(nums);
        ArrayList<List<Integer>> res = new ArrayList<List<Integer>>();
        addOrNot(res, new ArrayList<Integer>(), nums, 1);
        return res;
    }

    private void addOrNot(ArrayList<List<Integer>> res, ArrayList<Integer> list, int[] nums, int start){
        if(start>nums.length){
            res.add(list);
            return;
        }
        ArrayList<Integer> l1 = new ArrayList<Integer>(list);
        ArrayList<Integer> l2 = new ArrayList<Integer>(list);
        l2.add(nums[start-1]);
        addOrNot(res, l1, nums, start+1);
        addOrNot(res, l2, nums, start+1);
    }
}
---
public static List<List<Integer>> subsets(int[] nums) {
    Arrays.sort(nums);
    List<List<Integer>> result = new ArrayList<>();
    for (int i = 0; i < Math.pow(2, nums.length); i++) {
        List<Integer> list = new ArrayList<>();
        for (int j = 0; j < nums.length; j++) {
            if (((i >> j) & 1) == 1)
                list.add(nums[j]);
        }
        result.add(list);
    }
    return result;
}
---
public class Solution {
public List<List<Integer>> subsets(int[] nums){
    List<List<Integer>> result = new ArrayList<List<Integer>>();
    List<Integer> stk = new ArrayList<Integer>();
    Arrays.sort(nums);
    return helper(nums,result,stk,0);
//  return result;

}
public List<List> helper(int[] nums,List<List> result,List stk,int start){

    if(start ==nums.length){
      //  List<Integer> item = new ArrayList<Integer>(stk);
        if (!result.contains(new ArrayList<Integer>(stk)))
        result.add(new ArrayList<Integer>(stk));

        return result;
    }
    for(int i=start;i<nums.length;i++){
        helper(nums,result,stk,i+1);
        stk.add(nums[i]);
        helper(nums,result,stk,i+1);
        stk.remove(stk.size()-1);
    }
    return result;

}
}
--
public class Solution {
public List<List<Integer>> subsets(int[] nums) {
    List<List<Integer>> ans = new ArrayList<>();
    List<Integer> path = new ArrayList<Integer>();
    if (nums == null || nums.length == 0) return ans;

    Arrays.sort(nums);
    subsetsHelper(nums, path, ans, 0);

    return ans;
}

public void subsetsHelper(int[] nums, List<Integer> path, List<List<Integer>> ans, int pos) {
    ans.add(new ArrayList<Integer>(path)); //**WHY I HAVE TO CREATE NEW LIST HERE???**

    for (int i = pos; i < nums.length; i++) {
        path.add(nums[i]);
        subsetsHelper(nums, path, ans, i + 1);
        path.remove(path.size() - 1);
    }
}
}
---
public class Solution {
    public List<List<Integer>> subsets(int[] nums) {
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

        for(int i = position; i < nums.length; i++){
            sublist.add(nums[i]);
            getSubsets(res, sublist, nums, k, i+1);
            sublist.remove(sublist.size()-1);
        }

        return;
    }
}
---
public class Solution {
public List<List<Integer>> subsets(int[] nums) {
    int n = nums.length;
    List<List<Integer>> subsets = new ArrayList<>();
    for (int i = 0; i < Math.pow(2, n); i++)
    {
        List<Integer> subset = new ArrayList<>();
        for (int j = 0; j < n; j++)
        {
            if (((1 << j) & i) != 0)
                subset.add(nums[j]);
        }
        Collections.sort(subset);
        subsets.add(subset);
    }
    return subsets;
}
}
---
public class Solution {
    public List<List<Integer>> subsets(int[] nums) {
        List<List<Integer>> subsets = new ArrayList<>();
        List<Integer> template = new ArrayList<>();
        subsets.add(template);
        collectSubsets(nums, 0, template, subsets);
        return subsets;
    }

    private void collectSubsets(int[] nums, int start, List<Integer> template,
            List<List<Integer>> subsets) {
        if (start >= nums.length) {
            return;
        }

        for (int i = start; i < nums.length; i++) {
            List<Integer> subset = new ArrayList<>(template);
            subset.add(nums[i]);
            Collections.sort(subset);
            subsets.add(subset);
            collectSubsets(nums, i + 1, subset, subsets);
        }
    }
}
---
public List<List<Integer>> subsets(int[] nums) {
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
    for (int i = pos; i < n.length; i++) {
        each.add(n[i]);
        helper(res, new ArrayList<>(each), i + 1, n);
        each.remove(each.size() - 1);
    }
    return;
}
The idea is use pos to keep track of the index of the array. Compare to other backracking problem like combinations, the condition that each single List adds to the List<List> is when the index of the array is valid. Meanwhile, after adding to the List<List> , keeping going for the for loop.

the following is the combinations I wrote, which is very similar to this problem.

    public List<List<Integer>> combine(int n, int k) {
    List<List<Integer>> res = new ArrayList<>();
    List<Integer> each = new ArrayList<>();
    helper(res, each, 1, n, k);
    return res;
}
public void helper(List<List<Integer>> res, List<Integer> each, int pos, int n, int k) {
    if (each.size() == k) {
        res.add(each);
        return;
    }
    for (int i = pos; i <= n; i++) {
        each.add(i);
        helper(res, new ArrayList<>(each), i + 1, n, k);
        each.remove(each.size() - 1);
    }
    return;
}
--
public List<List<Integer>> subsets(int[] nums) {
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
    for (int i = pos; i < n.length; i++) {
        each.add(n[i]);
        helper(res, new ArrayList<>(each), i + 1, n);
        each.remove(each.size() - 1);
    }
    return;
}
The idea is use pos to keep track of the index of the array. Compare to other backracking problem like combinations, the condition that each single List adds to the List<List> is when the index of the array is valid. Meanwhile, after adding to the List<List> , keeping going for the for loop.

the following is the combinations I wrote, which is very similar to this problem.

    public List<List<Integer>> combine(int n, int k) {
    List<List<Integer>> res = new ArrayList<>();
    List<Integer> each = new ArrayList<>();
    helper(res, each, 1, n, k);
    return res;
}
public void helper(List<List<Integer>> res, List<Integer> each, int pos, int n, int k) {
    if (each.size() == k) {
        res.add(each);
        return;
    }
    for (int i = pos; i <= n; i++) {
        each.add(i);
        helper(res, new ArrayList<>(each), i + 1, n, k);
        each.remove(each.size() - 1);
    }
    return;
}
--
public List<List<Integer>> subsets(int[] nums) {
    int N=nums.length;
    Arrays.sort(nums);
    boolean[] seats=new boolean[N];

    List<List<Integer>> res=new ArrayList<>();


    search(res,nums,seats,N,0);

    return res;
}

public void search(List<List<Integer>> res,int[] nums,boolean[] seats,int N,int index){
    if(index==N){

        List<Integer> list=new ArrayList<>();

        for (int i=0;i<N;i++){
            if(seats[i]){
                list.add(nums[i]);
            }
        }
        res.add(list);
        return;
    }

    seats[index]=true;
    search(res,nums,seats,N,index+1);
    seats[index]=false;
    search(res,nums,seats,N,index+1);


}
---
public class Solution {
    public List<List<Integer>> subsets(int[] nums) {
        Arrays.sort(nums);
        List<List<Integer>> result = new ArrayList<>();
        dfs(nums,0,new ArrayList<Integer>(),result);
        return result;
    }

    public void dfs(int[] nums, int index,List<Integer> path, List<List<Integer>> result){
        if(index<=nums.length){
            result.add(path);
        }
        for(int i=index;i<nums.length;i++){
            List<Integer> nPath= new ArrayList<>(path);
            nPath.add(nums[i]);
            dfs(nums,i+1,nPath,result);
        }
    }
}
---
public class Solution {
    public List<List<Integer>> subsets(int[] S) {
        List<List<Integer>> res = new ArrayList<>();
        res.add(new ArrayList<Integer>());

        Arrays.sort(S);
        for(int i : S) {
            List<List<Integer>> tmp = new ArrayList<>();
            for(List<Integer> sub : res) {
                List<Integer> a = new ArrayList<>(sub);
                a.add(i);
                tmp.add(a);
            }
            res.addAll(tmp);
        }
        return res;
    }
}
--
public List<List<Integer>> subsets(int[] S) {
    List<List<Integer>> res = new ArrayList<List<Integer>>();
    res.add(new ArrayList<Integer>());
    Arrays.sort(S);
    for(int i = S.length - 1; i >= 0; i--){
        int size = res.size() - 1;
        for(int j = size; j >= 0; j--){
            List<Integer> newList1 = new ArrayList<>();
            newList1.add(S[i]);
            newList1.addAll(res.get(j));
            res.add(newList1);
        }
    }
    return res;
}
--
// iterative method to get each element
vector<vector<int> > subsets(vector<int> &S) {
    vector<vector<int> > ans(1, vector<int>());
    sort(S.begin(), S.end());

    vector<int> tmp;
    for (int i = 0; i < S.size(); ++i) {
        int len = ans.size();
        for (int j = 0; j < len; ++j) {
            tmp = ans[j];
            tmp.push_back(S[i]);
            ans.push_back(tmp);
        }
    }

    return ans;
}

// recursive backtracing
vector<vector<int> > subsets(vector<int> &S) {
    vector<vector<int> > ans;
    if (S.size() <= 0) return ans;

    sort(S.begin(), S.end());
    if (S.size() == 1) {
        ans.push_back(vector<int>());
        ans.push_back(S);
        return ans;
    }

    vector<int> tmp;
    vector<int> a(S.begin()+1, S.end());
    ans = subsets(a);
    int n = ans.size();
    for (int i = 0; i < n; ++i) {
        tmp = ans[i];
        tmp.insert(tmp.begin(), *S.begin());
        ans.push_back(tmp);
    }

    return ans;
}
---
private List<List<Integer>> rec_subsets(int []S, int begin){
    List<List<Integer>> result = new ArrayList<List<Integer>>();

    if(S.length == 0 || begin >= S.length){
        List<Integer> emptyList = new ArrayList<Integer>();
        result.add(emptyList);
        return result;
    }

    List<List<Integer>> rest = rec_subsets(S, begin+1);

    // Add the result from the rest of the problem.
    result.addAll(rest);

    for(List<Integer> elem : rest){
        ArrayList<Integer> newComb = new ArrayList<Integer>();
        newComb.addAll(elem);       
        elem.add(0, S[begin]);

        result.add(newComb);
    }

    return result;
}

public List<List<Integer>> subsets(int[] S) {
            Arrays.sort(S);
    return this.rec_subsets(S, 0);
}
---
Basic idea is:

sort the array
start from the end of the array, for each element, do recursive call to get subset for element 'n-1'.
Once get all sebset for n-1, then your subset for n will be : Subset(n)= Subset(n-1)+(n itself) +(add n to Subset(n-1))
at last, don't forget to add [] , from OJ, it counts as one subset as well.

public class Solution {

public List <List <Integer>> subsets (int[] S) {
    if (S == null)
        return null;
    Arrays.sort (S);
    List <List <Integer>> result = new ArrayList <List <Integer>> ();
    result = getSubSet (S, S.length - 1);
    result.add (new ArrayList <Integer> ());
    return result;
}

List <List <Integer>> getSubSet (int[] s, int index) {
    List <List <Integer>> result = new ArrayList <List <Integer>> ();
    if (index < 0) {
        return result;
    }
    List <List <Integer>> subResult = getSubSet (s, index - 1);
    result.addAll (subResult);
    for (int i = 0; i < subResult.size (); i++) {
        List <Integer> bList = new ArrayList <> ();
        bList.addAll (subResult.get (i));
        bList.add (s[index]);
        result.add (bList);
    }
    result.add (Arrays.asList (s[index]));
    return result;
}
}

