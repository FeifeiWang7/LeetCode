// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int start = 0, end = n;
        n = start / 2 + end / 2;
        while (start != end) {
            if (isBadVersion(n))
                end = n;
            else
                start = n + 1;
            n = start / 2 + end / 2;
        }
        return start;
    }
};
///
class Solution {
public:
    int firstBadVersion(int n) {
        int from,to,mid;
        from=1;to=n;
        while(from!=to)
        {
            mid=((long long)from+to)/2;
            if(isBadVersion(mid)==true)
            {
                to=mid;
            }
            else
            {
                from=mid+1;
            }
        }
        return from;
    }
};
///
// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution { 
public:
int bst(long n1,long n2)
{
    if(!isBadVersion(n2-1)&&isBadVersion(n2))return n2;
    int l=(n1+n2)/2;
    if(!isBadVersion(l)&&isBadVersion(l+1))return l+1;
    else if(isBadVersion(l))return bst(n1,l);
    else return bst(l+1,n2);
}
int firstBadVersion(int n) {
    if(n==0)return 0;
    return bst(1,n);
}
};
There should be careful ! Using int is not enough to store big number !

There are other better solutions out there ^_^. for example:

bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int start = 1;
        int end = n;
        int middle;
        while(start <= end){
            middle = ((end-start)>> 1) + start;
            if(isBadVersion(middle)) end = middle - 1;
            else start = middle + 1;
        }
        return end + 1;
    }
};
////
// Forward declaration of isBadVersion API.
    bool isBadVersion(int version);
//int helperFirstBadVersion(int n, int left, int right);
    class Solution {
public:
    int firstBadVersion(int n) {
        if (n <=1) {
            return n;
        }
        return helperFirstBadVersion(1, n);
    }

    int helperFirstBadVersion(int left, int right) {
    if (left >= right) {
        return left;
    }
    int mid = left + (right -left) / 2;
    if (isBadVersion(mid)) {
        return helperFirstBadVersion(left, mid);
    } else {
        return helperFirstBadVersion(mid, right);
    }
}
};
This is my recursion version of first Bad Version problem. I ran it but got compiler error.Also I tried to put the helper function outside of the class definition but still got compiler error. I tried to figure out why but haven't understood why.

//////
public class Solution extends VersionControl {
 public int firstBadVersion(int n) {
    int start = 1;
    int end = n;
    int mid =0;
    int lastbad = mid;
    while(end >= start)
    {
        mid = start + (end-start)/2;
        if(isBadVersion(mid))
        {
            end = mid-1;
            lastbad = mid;
        }
        else
        {
            start = mid+1;
        }
    }
    return lastbad;
}
}
/////
// Remember to use INT64 to avoid overflow.
bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int ans = n;
        if(n < 2)
            return n;
        long long l = 1, r = n;
        while(l <= r){
            long long mid = (l + r)>>1;
            if(isBadVersion(mid)){
                ans = (int)mid;
                r = mid - 1;
            }else
                l = mid + 1;
        }
        return ans;
    }
};

//////
Below is my code, it got TLE. But I can't see the difference between my code and this one except for how I calculated mid. So is there any difference between "(left + right) / 2" and "left + (right - left) / 2"?

bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int left = 1;
        int right = n;
        int mid;
        while(left < right) {
            mid = (left + right) / 2;
            if(isBadVersion(mid)) {
                right = mid - 1;
            }
            else {
                left = mid + 1;
            }
        }
        return left;
    }
};
'left + right' may cause the Integer Overflow, meaning that left+right > 2147483647
But in your code, the first if sentence updates the "right" value to mid - 1 when isBadVersion(mid) return true. However, if the mid value is exactly the first bad version, then you code would go wrong.

First of all, mathematically, (left + right)/2 = left + (right-left)/2 But different languages have different characteristics.

Python works fine with both version.

Java, C++, C# will be overflowed if (left+right)>2147483647

Javascript both failed, because for example, (1+2)/2 = 1.5, not 1.
/////
class Solution {
public:
    int firstBadVersion(int n) {
        int lower = 1, upper = n, mid;
        while(lower < upper) {
            mid = lower + (upper - lower) / 2;
            if(!isBadVersion(mid)) lower = mid + 1;   /* Only one call to API */
            else upper = mid;
        }
        return lower;   /* Because there will alway be a bad version, return lower here */
    }
};

