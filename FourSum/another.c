//add some check to run faster
int comp(const void* p, const void* q){ 
    return (*(int*) p - *(int*) q); 
}

int** fourSum(int* nums, int numsSize, int target, int* returnSize) {
    if(nums ==NULL) return 0;
    if(numsSize <4) return 0;
    int **Ans = (int**)malloc(200*sizeof(int*));
    qsort(nums,numsSize,sizeof(int),comp);
    int a,b,c,d,count=0;;
    for(a=0; a < numsSize-3;a++){
        // check [a,x,x,x] mininum
        if(nums[a]+nums[a+1]+nums[a+2]+nums[a+3]>target)    
            break;
        // check [a,x,x,x] maxinum
        if(nums[a]+nums[numsSize-3]+nums[numsSize-2]+nums[numsSize-1]<target)
            continue;
        for(b=a+1;b<numsSize-2;b++){
            // check [a,b,x,x] mininu
            if(nums[a]+nums[b]+nums[b+1]+nums[b+2]>target)
                break;      
            // check [a,b,x,x] maxinum          
            if(nums[a]+nums[b]+nums[numsSize-2]+nums[numsSize-1]<target)
                continue;
            for(c=b+1,d = (numsSize-1);c<d;){
                if(nums[a]+nums[b]+nums[c]+nums[d]>target){
                    d--;
                }
                else if(nums[a]+nums[b]+nums[c]+nums[d]<target){
                    c++;
                }else{
                    Ans[count] = (int*)malloc(4*sizeof(int));
                    Ans[count][0]=nums[a];
                    Ans[count][1]=nums[b];
                    Ans[count][2]=nums[c];
                    Ans[count][3]=nums[d];
                    while(c<d && Ans[count][2]==nums[c]) c++;   
                    while(c<d && Ans[count][3]==nums[d]) d--;           
                    count++;
                    if(count % 200 == 0)
                        Ans = (int**)realloc(Ans,sizeof(int*)*(count+200));
                }
            }
            while(b<numsSize-1 && nums[b+1] == nums[b]) b++;    
        }
        while(a<numsSize-1 && nums[a+1] == nums[a]) a++;        
    }
    *returnSize = count;
    return (int**)realloc(Ans,sizeof(int*)*count);
}
