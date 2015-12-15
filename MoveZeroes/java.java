1st pointer: for loop

2nd pointer: security, to make sure the current and previous elements in the array != 0

public void moveZeroes(int[] nums) {
    int security = 0;
    for (int i = 0; i< nums.length; i++)
        if (nums[security] != 0) security++;
        else if (nums[i] != 0) {
            nums[security++] = nums[i];
            nums[i] = 0;
        }
    }
///
public class Solution {

public void moveZeroes(int[] nums) {

    int p1 = 0, p2 = 0;
    while(p2<nums.length){

        if(p1 == p2){
            if(nums[p1] != 0){
                p1++;
            }
        }else{
            if(nums[p2] != 0){
                nums[p1++] = nums[p2];
                nums[p2] = 0;
            }
        }
        p2++;
    }
}
}
//
public class Solution {

public void moveZeroes(int[] nums) {
    int count = 0;
    int i = 0;
    for (; i < nums.length; i++) {
        if (nums[i] == 0)  {
            count++;
        }
        if (nums[i] != 0 && count != 0) {
            nums[i-count] = nums[i];
            nums[i] = 0;
        }
    }
    for (i = i - count; i< nums.length; i++) {
        nums[i] = 0;
    }

}
}
///
public void moveZeroes(int[] nums) {
    int index = 0;
    for (int num : nums)  if(num != 0) nums[index++] = num;
    for (int i = index; i < nums.length; i++) nums[i] = 0;
}
///
public class Solution {

public void moveZeroes(int[] nums) {

    if(nums == null || nums.length == 0){
        return;
    }

    int j = 0;
    for(int i = 0; i < nums.length; i++){
        if(nums[i] != 0){
            nums[j] = nums[i];
            j++;
        }
    }

    for(int m = j; m < nums.length; m++){
        nums[m] = 0;
    }

    return;
} 
}
///
public void moveZeroes(int[] nums) {
    int i = 0;
    for (int n : nums) {
        if (n != 0)
            nums[i++] = n;
    }
    while (i < nums.length) nums[i++] = 0;
}
///
method1: exchange zero and non-zero

public class Solution {
public void moveZeroes(int[] nums) {
    for(int i = 0; i < nums.length-1; i++){
        if(nums[i] == 0 ){
            int j=i;
            while(nums[j] == 0 && j<nums.length-1){
                j++;
            }
            nums[i] = nums[j];
            nums[j] = 0;
        }
    }
}
//algorithm : exchange value, the zero position exchange with the next non-zero position
}

method2: find non-zero put in new order, then all zero filled the array

public class Solution {
public void moveZeroes(int[] nums) {
    // change method, only find non-zero position and put those in order, then put all zero behind
    int order_pos = 0;
    for (int i = 0; i < nums.length; i++) {
        if(nums[i] != 0){
            nums[order_pos++] = nums[i];
        }
    }// i is used to find the non-zero postions

    while(order_pos < nums.length){
        nums[order_pos++] = 0;
    }
}
}
///
public class Solution {
    public void moveZeroes(int[] nums) {
        int i = 0, j = 0;
        for (i = 0; i < nums.length; i++) {
            if (nums[i] != 0) {
                if (j != i) {
                    nums[j] = nums[i];
                    nums[i] = 0;
                }
                j++;
            }
        }
    }
}
///
public void moveZeroes(int[] nums) {
    int i = -1, j = 0;
    while (j < nums.length) {
        if (nums[j] != 0) {
            swap(++i, j, nums);
        }
        j++;
    }
}

public void swap(int i, int j, int[] nums) {
    int temp = nums[i];
    nums[i] = nums[j];
    nums[j] = temp;
}
///
public class Solution {
    public void moveZeroes(int[] nums) {
        int zero = 0;
        for(int i=0;i<nums.length;i++){
            if(nums[i]==0){
                zero++;
                continue;
            }
            nums[i-zero] = nums[i];
        }
        for(int i=nums.length-zero;i<nums.length;i++){
            nums[i] = 0;
        }
    }
}
///
public class Solution {
    public void moveZeroes(int[] nums) {
        int index = 0 ;
        for(int i = 0 ; i < nums.length; i++)
        {

            if (nums[i]!=0 )
            {
                nums[index]=nums[i];
                if(index!= i)
                {
                    nums[i]= 0;
                }
                index++;
            }
        }
    }
}
///
public void moveZeroes(int[] nums) {
    int count = 0;
    for (int i = 0; i < nums.length; i++) {
        if (nums[i] == 0) {
            count++;
        } else {
            nums[i - count] = nums[i];
            if (count != 0) {nums[i] = 0;}
        }
    }
    return;
}
///
public class Solution {
    public void moveZeroes(int[] nums) {
        int rightPos = 0, curr = 0;
        while(curr < nums.length) {
            if(nums[curr]!=0) nums[rightPos++] = nums[curr];
            curr++;
        }
        while(rightPos < nums.length) {
            nums[rightPos++] = 0;
        }
    }
}
///
public void moveZeroes(int[] nums) {
    int zeroNum      =  0; // the number(length) of zeros


    for(int i =0 ;i<nums.length;i++){
        // if nums[i] ==0; zeroNum++;
        if(nums[i]==0){
           zeroNum++;
        }
        // Else nums[i]!=0;
        //        if there are N zeros before it, we should swap the most left zero and nums[i];
        //        else means no zeros if before it, all nozeros until now, just do nothing.
        else{
            if(zeroNum>0){
                nums[i-zeroNum]= nums[i];
                nums[i] =0;
            }
        }

    }
}
///
// Shift non-zero values as far forward as possible
// Fill remaining space with zeros

public void moveZeroes(int[] nums) {
    if (nums == null || nums.length == 0) return;        

    int insertPos = 0;
    for (int num: nums) {
        if (num != 0) nums[insertPos++] = num;
    }        

    while (insertPos < nums.length) {
        nums[insertPos++] = 0;
    }
}
