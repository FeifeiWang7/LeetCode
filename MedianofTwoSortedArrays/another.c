double findKthSortedArrays(int* nums1, int nums1Size, int*nums2, int nums2Size, int k) {
    int *a1 = nums1;
    int *a2 = nums2;
    int size1 = nums1Size;
    int size2 = nums2Size;
    int *atmp, itmp;

    do {
        if (size1 > size2) {
            atmp = a1;
            a1 = a2;
            a2 = atmp;
            itmp = size1;
            size1 = size2;
            size2 = itmp;
        }

        if (size1 == 0)
            return a2[k];

        if (size1 + size2 == k+1)
            return a1[size1-1] > a2[size2-1] ? a1[size1-1] : a2[size2-1];

        int k1 = size1 / 2;
        int k2 = k - k1;

        if (a1[k1] > a2[k2]) {
            k = k1;
            a2 += k2;
            size2 -= k2;
            size1 = k1;
        } else {
            k = k2;
            a1 += k1;
            size1 -= k1;
            size2 = k2;
        }
    } while (true);
}

double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    int total = nums1Size + nums2Size;
    if (total & 0x1 == 1)
        return findKthSortedArrays(nums1, nums1Size, nums2, nums2Size, total/2);
    else
        return (findKthSortedArrays(nums1, nums1Size, nums2, nums2Size, total/2 - 1)
              + findKthSortedArrays(nums1, nums1Size, nums2, nums2Size, total/2)) / 2;
}
/////
double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {

int m, n;
int total = nums1Size + nums2Size;
int left1max, left2max, right1min, right2min, leftmax, rightmin;
int left1, left2, right1, right2;
int result = 0;

if (nums1Size > nums2Size)
    return findMedianSortedArrays(nums2, nums2Size, nums1, nums1Size);

if (nums1Size == 0) {
    if (nums2Size & 0x1) {
        return nums2[(nums2Size + 1) / 2 - 1];
    } else {
        return (nums2[(nums2Size + 1) / 2 - 1] + nums2[(nums2Size + 1) / 2]) / 2.0;
    }
}

n = (nums2Size + 1) / 2;
m = (nums1Size + nums2Size + 1) / 2 - n;

left1 = m;
right1 = nums1Size;
left2 = n;
right2 = nums2Size;

while (1) {
    left1max = m > 0 ? nums1[m - 1] : 0;
    left2max = n > 0 ? nums2[n - 1] : 0;
    right1min = m < nums1Size ? nums1[m] : INT_MAX;
    right2min = n < nums2Size ? nums2[n] : INT_MAX;
    if (left1max > right2min) {
        int move = (m - left1 + 1 ) / 2 ? : 1;
        m = m - move;
        n = n + move;
        left1 = m;
        right2 = n;
    } else if (left2max > right1min) {
        int move = (right1 - m) / 2 ? : 1;
        m = m + move;
        n = n - move;
        left2 = n;
        right1 = m;
    } else
        break;
}

leftmax = left1max > left2max ? left1max : left2max;
rightmin = right1min < right2min ? right1min : right2min;

if (total & 0x1)
    return leftmax;
else
    return (leftmax + rightmin) / 2.0;
}

////
double findMedianSortedArrays(int *nums1, int nums1Size, int *nums2, int nums2Size) {
    if(nums2Size < nums1Size) {
        return findMedianSortedArrays(nums2, nums2Size, nums1, nums1Size);}

    int low = 0, high = nums2Size, count1 = 0, count2 = 0, mid = (nums1Size+nums2Size)/2 + 1; 

    int find_index_to_insert(int num, int *nums, int size) {
        int lo = 0, hi = size;
        while(lo != hi-1) {
            int index = (lo+hi) / 2;
            if(nums[index] >= num) {
                hi = index;}
            else {
                lo = index;}}
        return (nums[lo] > num) ? lo : lo+1;}

    while(count1 + count2 != mid) { // pick count1 elements from nums1 and count2 elements from nums2
        if(count1 == nums1Size) {
            count2 = mid - count1;
            break;}
        if(low == high) {
            count1 = mid - count2;
            break;}
        int index2 = (low+high) / 2;
        int index1 = find_index_to_insert(nums2[index2], nums1+count1, nums1Size-count1);
        if(count1+index1 + index2+1 > mid) {
            high = index2;}
        else {
            count1 += index1;
            low = count2 = index2+1;}}

    if((nums1Size+nums2Size) % 2 == 0) { // take care of all the cases
        if(count1 == 0) return ((double)nums2[count2-1]+nums2[count2-2])/2;
        if(count2 == 0) return ((double)nums1[count1-1]+nums1[count1-2])/2;
        int first, second;
        if(nums1[count1-1] > nums2[count2-1]) {
            first = nums1[count1-1];
            second = nums2[count2-1];}
        else {
            first = nums2[count2-1];
            second = nums1[count1-1];}
        if(count1 >= 2) {
            second = (second > nums1[count1-2]) ? second : nums1[count1-2];}
        if(count2 >= 2) {
            second = (second > nums2[count2-2]) ? second : nums2[count2-2];}
        return ((double)first+second)/2;}
    if(count1 == 0) return (double)nums2[count2-1];
    if(count2 == 0) return (double)nums1[count1-1];

    return (double)(nums2[count2-1] > nums1[count1-1] ? nums2[count2-1] : nums1[count1-1]);}

////
double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) 
{
    double rtVal;
    int i1, i2, csum, sum;
    int targetL=0, targetR=0;

    sum=nums1Size+nums2Size;
    if(1 == (sum & 1))
    {
        if(1 != sum)
        {
            targetL = (sum - 1)/2;
            targetR = targetL;
        }
        else
        {
            if(1==nums1Size)
                return nums1[0];
            else
                return nums2[0];
        }
    }
    else
    {
        targetL = (sum - 1)>>1;
        targetR = targetL+1;
    }
    i1=0;i2=0;csum=0;

    while(csum<sum)
    {
        int addVal=0;
        if(i1>=nums1Size)
        {
            addVal = nums2[i2];
            i2++;
        }
        else if(i2>=nums2Size)
        {
            addVal = nums1[i1];
            i1++;
        }
        else
        {
            if(nums1[i1]<=nums2[i2])
            {
                addVal = nums1[i1];
                i1++;
            }
            else
            {
                addVal = nums2[i2];
                i2++;
            }
        }
        csum++;
        if(targetL==(csum-1))
            rtVal = addVal;
        if(targetR==(csum-1))
        {
            rtVal += addVal;
            break;
        }
    }
    rtVal /= 2;
    return rtVal;
}

