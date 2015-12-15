public class Solution { public void rotate(int[] nums, int k) { int temp = 0; int idxOld = 0;

    int aLen = nums.length;
    int i = 0;
    while (k >= aLen)
        k -= aLen;
    if (k == 0)
        return;

    int idxNew = k;    
    int GCD = 1;
    // get GCD.
    for (int j = k; j > 0; j--) {
        if ((aLen % j == 0) && (k % j == 0)) {
            GCD = j;
            break;
        }
    }
    System.out.print(GCD);
    while (i < aLen) {
        idxNew = (idxNew >= aLen ? idxNew-aLen : idxNew);
        temp = nums[idxNew];
        nums[idxNew] = nums[idxOld];
        nums[idxOld] = temp;
        i++;
        idxNew += k;
        if (i%(aLen/GCD) == 0) {
            idxNew ++;
            idxOld ++;
        }
    }
}
}


