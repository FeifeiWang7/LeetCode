public class Solution {
    public int[] twoSum(int[] nums, int target) {
        int[] OriNum=nums.clone();
        Arrays.sort(nums);
        int left=0,right=nums.length-1;
        while(left<right){
            if(nums[left]+nums[right]==target){
                int[] rs=new int[2];
                int pos=0;
                for(int i=0;i<OriNum.length;i++){
                    if(OriNum[i]==nums[left]||OriNum[i]==nums[right])
                        rs[pos++]=i+1;
                }
                return rs;
            }
            if(nums[left]+nums[right]>target)
                right--;
            if(nums[left]+nums[right]<target)
                left++;
        }
        return new int[]{0,0};
    }
}

////
Use a map to cahce each element seen so far. While scanning the array left to right , for each element nums[i] check if there is a number K in cache such that A[i] + k = target. That means we need to find in cache for k = target-A[i].

public class Solution {
    public int[] twoSum(int[] nums, int target) {
        int[] res = new int[2];
        res[0] = -1;
        res[1] = -1;

        final HashMap<Integer, Integer> h = new HashMap<Integer, Integer>();

        for (int i = 0; i < nums.length; i++) {
            if (h.containsKey(target - nums[i])) {
                int index = h.get(target-nums[i])+1;
                res[0] = Math.min(i+1, index);
                res[1] = Math.max(i+1, index);
            }
            h.put(nums[i], i);
        }

        return res;
    }
}
