void reverse( int *nums,int begin,int end ){
    int tmp = 0;
    while( begin < end ){
        tmp = nums[begin];
        nums[begin++] = nums[end];
        nums[end--] = tmp;
    }
}
void three_reverse( int *nums,int numsSize,int n ){
    reverse(nums,0,n-1);
    reverse(nums,n,numsSize-1);
    reverse(nums,0,numsSize-1);
}
void rotate(int* nums, int numsSize, int k) {
    k %= numsSize;
    three_reverse(nums,numsSize,numsSize-k);
}
//////
void reverse(int *nums , int begin , int end){

int tmp;
while(begin<end){
    tmp=nums[begin];
    nums[begin]=nums[end];
    nums[end]=tmp;
    begin++;
    end--;
}
}

void rotate(int* nums, int numsSize, int k) {

if(k==0 || k==numsSize)
    return;
if(numsSize==0 )
  return;

reverse(nums,0,numsSize-1);
if(k>numsSize)
    k=k%numsSize;
if(numsSize-k!=0){


reverse(nums,0,k-1);
 reverse(nums,k,numsSize-1);   

}
}


