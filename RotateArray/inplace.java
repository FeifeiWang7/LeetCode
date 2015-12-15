public void rotate(int[] nums, int k) {
    if (nums == null || nums.length == 0) return;
    int n = nums.length;
    k = k % n;
    reverse(nums, 0, n - 1);
    reverse(nums, 0, k - 1);
    reverse(nums, k, n - 1);
}

private void reverse(int[] nums, int start, int end) {
    while (start < end) {
        int tmp = nums[start];
        nums[start++] = nums[end];
        nums[end--] = tmp;
    }
}
/////
public class Solution {
public void rotate(int[] nums, int k) {
    int n = nums.length;
    if(n<2|| k <= 0||k==n)return ;
    if(k>n) k = k%n;
    reverse(nums,0,n-k-1);
    reverse(nums,n-k,n-1);
    reverse(nums,0,n-1);
}
public void reverse(int[] nums,int p,int q){
    for(int i = 0;i<=(q-p)/2;i++){
        int temp = nums[p+i];
        nums[p+i] = nums[q-i];
        nums[q-i] = temp;
    }

}
}
///////
public class Solution {

public void rotate(int[] nums, int k) {
    int length=nums.length;
    int rk=k%length;
    int [] copy=new int[length*2];
    for(int i=0;i<2*length;i++){
        copy[i]=nums[i%length];
    }
    for(int t=length-rk,i=0;t<2*length-rk;t++,i++)
    {
        nums[i]=copy[t];

    } 

}
}

////
public class Solution {
    public void rotate(int[] nums, int k) {
       int end = nums.length;
        k=k%end;// to check for outofbounds when k >= nums.length
        rotate(nums,0,end-k-1);//reverse one half of the array
        rotate(nums,end-k,end-1);//reverse other half of the array
        rotate(nums,0,end-1);//reverse whole array  
    }
    public void swap(int[] nums,int a,int b){
        int temp = nums[a];
        nums[a] = nums[b];
        nums[b] = temp;
    }

    public void rotate(int[] nums,int start,int end){
        for(int i = start;i<=(start+end)/2;i++){
            swap(nums,i,(start+end)-i);
        }
    }


}
//////
public class Solution {
    public void rotate(int[] nums, int k) {
       int end = nums.length;
        k=k%end;// to check for outofbounds when k >= nums.length
        rotate(nums,0,end-k-1);//reverse one half of the array
        rotate(nums,end-k,end-1);//reverse other half of the array
        rotate(nums,0,end-1);//reverse whole array  
    }
    public void swap(int[] nums,int a,int b){
        int temp = nums[a];
        nums[a] = nums[b];
        nums[b] = temp;
    }

    public void rotate(int[] nums,int start,int end){
        for(int i = start;i<=(start+end)/2;i++){
            swap(nums,i,(start+end)-i);
        }
    }


}
