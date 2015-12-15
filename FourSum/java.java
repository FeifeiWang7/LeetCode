// 4pointer
public List<List<Integer>> fourSum(int[] nums, int target) {
    List<List<Integer>> results = new LinkedList<List<Integer>>();
    if (nums == null || nums.length < 4)
        return results;
    Arrays.sort(nums);

    for (int s = 0; s < nums.length - 3; s++) {
        if (s != 0 && nums[s] == nums[s - 1])  continue;

        for (int e = nums.length - 1; e >= s + 3; e--) {
            if (e != nums.length - 1  && nums[e] == nums[e + 1]) continue;

            int local = target - nums[s] - nums[e];
            int j = s + 1;
            int k = e - 1;
            while (j < k) {
                if ( (nums[j] + nums[k]) > local){
                    while (k > j  && k > s && nums[k] == nums[k - 1]) {
                        k--;
                    }
                    k--;
                }else if ( (nums[j] + nums[k]) < local){
                    while (j < k && j < e && nums[j] == nums[j + 1]) {
                        j++;
                    }
                    j++;
                }else{
                    List<Integer> comb = new LinkedList<Integer>();
                    comb.add(nums[s]);
                    comb.add(nums[j]);
                    comb.add(nums[k]);
                    comb.add(nums[e]);
                    results.add(comb);
                    while (k > j  && k > s && nums[k] == nums[k - 1]) {
                        k--;
                    }
                    k--;
                    while (j < k && j < e && nums[j] == nums[j + 1]) {
                        j++;
                    }
                    j++;
                }
            }
        }
    }
    return results;

}
// binary search
vector<vector<int>> fourSum(vector<int>& nums, int target) {
    int n=nums.size(); vector<vector<int> > ans;
    if(n<4) return ans;
    sort(nums.begin(), nums.end());

    int w, x, y, z, ly, ry, a, b, c, d, dc;
    for(w=0; w<n-3; w++){
        a=nums[w];
        if(a+nums[w+1]+nums[w+2]+nums[w+3]>target) return ans;
        for(x=w+1; x<n-2; x++){
            b=nums[x];
            if(a+b+nums[x+1]+nums[x+2]>target) break;
            for(z=n-1; z>x+1; z--){
                d=nums[z]; ly=x; ry=z; dc=target-a-b-d; y=(ly+ry)/2;c=nums[y];
                if(a+b+nums[z-1]+nums[z]<target) break;
                while(ly!=y && ry!=y){
                    if(c<dc) ly=y;
                    else if(c>dc) ry=y;
                    else if(c==dc){ ans.push_back(vector<int> {a, b, c, d}); break;}
                    y=(ly+ry)/2;c=nums[y];
                    }
                    while(nums[z]==nums[z-1]) {z--; if(z<3) break;}
                }
                while(nums[x]==nums[x+1]){x++; if(x>n-3) break;}
            }
            while(nums[w]==nums[w+1]){w++; if(w>n-4) break;}
        }
    return ans;
}
