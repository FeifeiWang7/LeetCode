// Forward declaration of isBadVersion API.
bool isBadVersion(int version);
///
bool isBadVersion(int version);

int firstBadVersion(int n) 
{
        int start = 1, end = n, mid;                    

        while(start<end)
        {
                // mid = (start+end)/2; may have overflow
                mid = start + (end - start)/2;
                if(isBadVersion(mid) == true)
                {
                        //if(isBadVersion(mid-1) == false)
                         //       return mid;
                        end = mid;
                }
                else
                {
                       // if(isBadVersion(mid+1) == true)
                        //        return mid+1;
                        start = mid + 1;
                }
        }
        return end;
}
///privious version, wrong
int firstBadVersion(int n) 
{
	int start = 0, end = n;

	while(1)
	{
		if(isBadVersion((start+end)/2) == true) 
 		{
			if(isBadVersion((start+end)/2-1) == false)
				return (start+end)/2;
			end = (start+end)/2;
		}
		else
 		{
			if(isBadVersion((start+end)/2+1) == true)
				return (start+end)/2+1;
			start = (start+end)/2;
		}
	}
}
