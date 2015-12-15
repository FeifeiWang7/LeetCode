public boolean containsDuplicate(int[] nums) {
        if (nums.length == 0) return false;
        HashSet<Integer> appeared = new HashSet<>();
        for(int n : nums) {
            if (!appeared.add(n)) return true;
        }
        return false;
    }
///////
public class Solution {
    public boolean containsDuplicate(int[] nums) {
        HashSet<Integer> set = new HashSet<Integer>();
        for( int i : nums){
            if(set.contains(i))
                return true;
            else
                set.add(i);
        }
        return false;
    }
}
////
public class Solution {
    public boolean containsDuplicate(int[] nums) {
        int length = nums.length;
        // boolean result = false;
        if(length<=1){
            return false;
        }
        Arrays.sort(nums);

        for(int i=0; i<length-1; i++){
            if(nums[i] == nums[i+1]){
                return true;

            }
        }
        return false;
    }
}
///
The Set's add method can be used for this situation,because it will return false if the element already exists .

public  boolean containsDuplicate(int[] nums) {
         Set<Integer> set = new HashSet<Integer>();
         for(int i : nums)
             if(!set.add(i))// if there is same
                 return true; 
         return false;
     }
///
public class Solution {
    public boolean containsDuplicate(int[] nums) {
        return nums.length != new HashSet<Integer>(Arrays.stream(nums).boxed().collect(Collectors.toList())).size();
    }
}
