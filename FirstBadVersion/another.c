Basically the problem is a variant of upper_bound() / lower_bound() problem. 
So we can follow the standard implementation to solve it.

int firstBadVersion(int n) {
    int lo = 1, hi = n, mid;
    while (lo < hi) {
        mid = lo + ((hi - lo) >> 1);
        isBadVersion(mid) ? (hi = mid) : (lo = mid + 1);
    }
    return hi;
}
///
int firstBadVersion(int n) {
        int l = 1, r = n, mid;
        while (l < r) {
            mid = r + (l-r-1)/2; // to make sure we are still in int, = (l+r-1)/2
            if (isBadVersion(mid)) r = mid; else l = mid+1;
        }
        mid = r + (l-r-1)/2;
        return mid;
    }

//////
bool isBadVersion(int version);

struct range {
    long leftIndex;
    long rightIndex;
};
int findBadVersion(struct range x)
{
    if ((x.rightIndex - x.leftIndex) <= 1)
    {
        return x.leftIndex + 1;
    }
    else
    {
        int middleIndex = (x.leftIndex + x.rightIndex) / 2;
        bool isBad = isBadVersion(middleIndex);
        if (isBad)
        {
            x.rightIndex = middleIndex;
        }
        else
        {
            x.leftIndex = middleIndex;
        }
        return findBadVersion(x);
    }
}

int firstBadVersion(int n) 
{
    if(isBadVersion(1))
    {
        return 1;
    }
    struct range x = {1,n};
    return findBadVersion(x);
}
// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

int firstBadVersion(int n) {
    int first = 0, last = n;
    long long int mid;
    while(last - first > 1)
    {
        mid = ((long long int)first+ (long long int)last) /2;   /* better alternative way in comments below */
        if(isBadVersion(mid))
           last = (int)mid;
        else
           first = (int)mid;
    }

    if(isBadVersion(first)) 
      return first;
    else 
      return last;
}
I think that

mid = first + (last-first)/2;

is a better way to prevent overflow, that would work if the indexes were already in the largest available format.
