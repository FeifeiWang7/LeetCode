void moveZeroes(int* nums, int numsSize) {

if(!nums || !numsSize)
    return 0;

int count = 0,i = 0;

for(; i < numsSize; i++)
    if (nums[i] != 0)
        nums[count++] = nums[i];

while(count < numsSize)
    nums[count++] = 0;

return 0;
}
///
void moveZeroes(vector& nums) {

    int i, j;
    for (i = 1; i < nums.size(); i++) {
        int x = nums[i];
        //nums[j - 1] > x .... nums[j-1]==0&&x!=0
        for ( j = i; j>0 && (nums[j-1]==0&&x!=0); j--) {
            nums[j] = nums[j - 1];
        }
        nums[j] = x;
    }
}
///
void moveZeroes(int* nums, int numsSize) {
    int runnerIndex = 0;
    int chaserIndex = 0;

    for(runnerIndex = 0; runnerIndex < numsSize; runnerIndex++) {
        if(nums[runnerIndex] != 0){
            if(runnerIndex != chaserIndex) {
                nums[chaserIndex] = nums[runnerIndex];
                nums[runnerIndex] = 0;
            }
            chaserIndex++;
        }
    }
}
////
void moveZeroes(vector<int>& nums) {
    int cur = 0;
    for(int i=0; i<nums.size(); i++)
        if(nums[i] != 0) swap(nums[i], nums[cur++]);
}

///
Solution 1

r is the read index, w is the write index (where the next non-zero number shall be written).

void moveZeroes(vector<int>& nums) {
    for (int r=0, w=0; r<nums.size(); ++r)
        if (nums[r])
            swap(nums[r], nums[w++]);
}
Solution 2

This one potentially uses fewer operations. Think of long a vector without zeros or with a long beginning part without zeros - we can skip that whole part (my above solution and every other solution I've seen instead overwrites that whole part with itself).

r is the read iterator, w is the write iterator (where the next non-zero number shall be written).

void moveZeroes(vector<int>& nums) {
    auto w = find(nums.begin(), nums.end(), 0), r = w;
    for (; r != nums.end(); ++r)
        if (*r)
            swap(*r, *w++);
}
Slight variation:

void moveZeroes(vector<int>& nums) {
    auto w = find(nums.begin(), nums.end(), 0), r = w;
    for (; r != nums.end(); ++r)
        if (*r)
            *w++ = *r;
    fill(w, r, 0);
}
Got the idea to use r instead of nums.end() in the fill from apolloydy's solution.

Solution 3

This one doesn't count (it uses "a temporary buffer" if it can), I just want to mention it anyway.

void moveZeroes(vector<int>& nums) {
    stable_partition(begin(nums), end(nums), [](int i){return i;});
}
