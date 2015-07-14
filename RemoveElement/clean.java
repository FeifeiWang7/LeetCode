public int removeElement(int[] nums, int val) {
    int length = nums.length,i = 0;
    while(i < length){
        if(nums[i] == val){
            nums[i] = nums[--length];
        } else {
            i++;
        }
    }
    return length;
}
