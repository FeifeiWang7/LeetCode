int removeDuplicates(int* nums, int numsSize) {
if (numsSize == 0)
{
    return numsSize;
}
int cur = 0;
int i = 1;
for (; i < numsSize; i++)
{
    if (nums[cur] != nums[i])
        nums[++cur] = nums[i];
}
return ++cur;
}
