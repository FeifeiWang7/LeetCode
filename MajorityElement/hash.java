import java.util.Hashtable;

public class Solution {
    public int majorityElement(int[] nums) {

        if (nums.length < 2) return nums[0];

        Hashtable<Integer, Integer> table = new Hashtable<Integer, Integer>(); 

        for (int i = 0; i < nums.length; i++) {

            if (table.containsKey(nums[i])) {
                table.put(nums[i], table.get(nums[i])+1);
                if (table.get(nums[i]) > (nums.length) / 2) return nums[i];
            }

            else table.put(nums[i], 1);
        }

      return 0;  
    }
}

/////////
The solution use hash map to count the appearance of num is easy to understand. If the hash function is good enough, it can reach O(n) and the space complexity is O(K) K is the number of distinct num.

public class Solution {
    public int majorityElement(int[] nums) {
        Map<Integer,Integer> hm = new HashMap<Integer,Integer>();
        for(int i=0; i<nums.length;i++){
            int times;
            if(hm.containsKey(nums[i])){
                times = hm.get(nums[i])+1;
            }else{
                times = 1;
            }
            if(times > nums.length/2)
                return nums[i];
            hm.put(nums[i],times);
        }
        return 0;
    }
}
