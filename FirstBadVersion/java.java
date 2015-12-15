public class Solution extends VersionControl {
  public int firstBadVersion(int n) {
      if(n==1) return n;
      return firstHelper(1,n);
  }
  public int firstHelper(int start, int end){
      if(start==end) return start;
      int mid=start+ (end-start)/2;
      if(isBadVersion(mid) && !isBadVersion(mid-1)) return mid;
      if(isBadVersion(mid) && isBadVersion(mid-1))  return firstHelper(start, mid-1);
      return firstHelper(mid+1, end);
  }
}
///
public class Solution extends VersionControl {
    public int firstBadVersion(int n) {
        int lo = 1, hi = n;
        int last = 0;
        while(lo <= hi){
            int mid = lo + (hi - lo)/2;
            if(isBadVersion(mid)){
                hi = mid - 1;
                last = mid;
            }else{
                lo = mid + 1;
            }
        }
        return last;
    }
}
/////
public int firstBadVersion(int n) {
        int min = 1, max = n;
        while(min<max){
            int mid = min+(max-min)/2;
            if(isBadVersion(mid)){
                max = mid;
            }else{
                min = mid+1;
            }
        }
        return min;
    }
///
/* The isBadVersion API is defined in the parent class VersionControl. boolean isBadVersion(int version); */

public class Solution extends VersionControl {

public int firstBadVersion(int n) {

    if(n==0) {
        return 0;
    }

   return helper(n,1,n);
}


public int helper(int n, int start, int end) {

    if(start>=end) {
        return start;
    }
    int middle = start+(end-start)/2;

    if(isBadVersion(middle)) {
        return helper(n,start,middle);
    } else {
        return helper(n,middle+1,end);

    }
}
}

it looks very simple, but actually a little tricky. Have to pay attention to the detail. 
Algo. 1 --

  public int firstBadVersion(int n) {
    int lo = 1, hi = n;
    while (lo < hi) {
        int med = lo + (hi -  lo)/2;
        if (isBadVersion(med)) {
            hi = med;
        } else {
            lo = med + 1;
        }
    }
    return lo;
}
Algo.2 --

    public int firstBadVersion(int n) {
    int lo = 1, hi = n;
    while (lo <= hi) {
        int med = lo + (hi -  lo)/2;
        if (isBadVersion(med)) {
            if (med == 1 || !isBadVersion(med-1))
                return med;
            hi = med;
        } else {
            lo = med + 1;
        }
    }
    return -1; //no solution found.
}
