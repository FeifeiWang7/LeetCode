The concise 7-line version.

Sample [1,2,3,4,5,6,7,8,9] 3    
The replacing process is as follow:
1) 1->4->7->1
2) 2->5->8->2
3) 3->6->9->3
public void Rotate(int[] nums, int k) {
    if(nums.Length == 0 || k % nums.Length == 0) return;
    int start = 0, i = start, curNum = nums[i], count = 0;
    while(count++ < nums.Length){
        int tmp = nums[i = (i + k) % nums.Length];
        nums[i] = curNum;
        curNum = i == start ? nums[i = ++start] : tmp;
    }
}
Below is the elaborated version easier to understand

public void Rotate(int[] nums, int k) {
    if(nums.Length == 0 || k % nums.Length == 0) return;
    int start = 0, i = start, curNum = nums[i], count = 0;
    while(count < nums.Length){
        i = (i + k) % nums.Length;
        int tmp = nums[i];
        nums[i] = curNum;
        if(i == start){
            start++;
            i = start;
            curNum = nums[i];
        }
        else curNum = tmp;
        count++;
    }
}
////
The idea is to rotate using reversal. 1. divide the array into two parts. 2. reverse first part 3. reverse second part 4. reverse whole array

/**
 * rotate right an array
 * nums      : pointer to array to be rotated
 * numsSize  : length of array
 * k         : distance of rotation
 */ 
void rotate(int* nums, int numsSize, int k) {
    k = k % numsSize;
    if (k == 0) return;
    if (numsSize <= 1) return;

    //divide the array into 2 part
    int lengthFirstPart = numsSize - k;
    //reverse first part
    reverse(nums, lengthFirstPart);
    //reverse second part
    reverse(&nums[lengthFirstPart], numsSize - lengthFirstPart);
    //reverse everything
    reverse(nums, numsSize);
}

/**
 * reverse array
 * nums      : pointer to array to be reversed
 * numsSize  : length of array
 */ 
void reverse(int* nums, int numsSize){
    int mid = numsSize / 2;
    int temp;
    for(int i = 0; i < mid; i++){
        temp = nums[i];
        nums[i] = nums[numsSize - 1 - i];
        nums[numsSize - 1 - i] = temp;
    }
}
////
class Solution {
    public:
    void rotate(vector<int>& nums, int k) {
        int offset = nums.size() - (k % nums.size());
        vector<int> t(nums.begin() + offset, nums.end());
        nums.resize(offset);
        nums.insert(nums.begin(), t.begin(), t.end());
    }
};
///////
class Solution { public: void rotate(vector& nums, int k) { int arrLen = nums.size();

    if (k >= arrLen){
        k = k % arrLen;
    }

    if (!arrLen){
        return;
    }

    if (k == 0){
        return;
    }

    int firstVal = nums[0];
    int firstIndex = 0;

    int emptyIndex = firstIndex;

    for (int i = 0; i < arrLen; i++){
        int correspondingIndex = (emptyIndex + arrLen - k) % arrLen;
        if (correspondingIndex == firstIndex){
            nums[emptyIndex] = firstVal;
            firstIndex++;
            firstVal = nums[firstIndex];
            emptyIndex = firstIndex;
        } else {
            nums[emptyIndex] = nums[correspondingIndex];
            emptyIndex = correspondingIndex;
        }
    }
}
};
