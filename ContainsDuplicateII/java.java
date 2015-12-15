public boolean containsNearbyDuplicate(int[] nums, int k) {
    Map<Integer, Integer> map = new HashMap<Integer, Integer>();
    for (int i = 0; i < nums.length; i++) {
        if (map.containsKey(nums[i])) {
            if (i - map.get(nums[i]) <= k) return true;
        }
        map.put(nums[i], i);
    }
    return false;
}
///
public boolean containsNearbyDuplicate(int[] nums, int k) {
    // i - j <= k
    if (nums.length <= 1 || k <= 0) {return false;}
    HashSet<Integer> set = new HashSet<>();
    for (int i = 0; i < nums.length; i++) {
        if (!set.add(nums[i])) {return true;}
        if (i >= k) {
            set.remove(nums[i - k]);
        }
    }
    return false;
}
///
public boolean containsNearbyDuplicate(int[] nums, int k) {
    Map<Integer, Integer> map = new HashMap<>();
    for (int i = 0; i < nums.length; i++) {
        if (map.containsKey(nums[i])) {
            int diff = i - map.get(nums[i]);
            if(diff <= k) return true;
        }
        map.put(nums[i], i);
    }
    return false;
}
/////
This is my solution using java.util.Set.

public boolean containsNearbyDuplicate(int[] nums, int k) {
        java.util.Set<Integer> set = new java.util.HashSet<Integer>();
        for (int i = 0; i < nums.length; i++ {
                    if (i < k + 1) {
                            set.add(nums[i]);
                            if (set.size() < i + 1) {
                                    return true;
                            }
                    } else {
                            set.remove(nums[i - k - 1]);
                            set.add(nums[i);
                            if (set.size() < k + 1) {
                                    return true;
                            }
                    }
        }
        return false;
}
