int removeElement(int* nums, int numsSize, int val) {
    if (!nums || numsSize == 0) {
        return 0;
    }
    int idx_fill = 0;
    int idx_search;
    for (idx_search = 0; idx_search < numsSize; ++idx_search) {
        if (nums[idx_search] != val) {
            nums[idx_fill++] = nums[idx_search];
        }
    }
    return idx_fill;
}
