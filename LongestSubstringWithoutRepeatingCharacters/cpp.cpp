//the max length ended at index i is either i-j or Ans(i-i)+1,j is the index of last appearance of the same
//character as S[i] ans Ans is the max length that ended at position i. This is the basic idea of this solution
#include<algorithm>
#include<cstring>
class Solution {
public:
int lengthOfLongestSubstring(string s) {
    int last[300];
    int len=s.length();
    if(len==0) return 0;
    int temp=1;
    memset(last,-1,sizeof(last));
    int ans=1;
    last[s[0]]=0;//mark down the last appearance of the same character
    for(int i=1;i<len;i++)
    {
        int lastApp=last[s[i]];
        if(lastApp==-1) temp++;
        else temp=min(temp+1,i-lastApp);
        last[s[i]]=i;
        ans=max(ans,temp);
    }
    return ans;
   }
};

///
int lengthOfLongestSubstring(string s) {
        vector<int> dict(256, -1);
        int maxLen = 0, start = -1;
        for (int i = 0; i != s.length(); i++) {
            if (dict[s[i]] > start)
                start = dict[s[i]];
            dict[s[i]] = i;
            maxLen = max(maxLen, i - start);
        }
        return maxLen;
    }
////
class Solution 
{
public:
int lengthOfLongestSubstring(string s) 
{
    int size=s.size();

    int table[256];
    for(int i=0;i<256;i++)
    {
        table[i]=-1;
    }

    int ret=0;
    int currtL=0;
    int currtR=size-1;
    for(int i=0;i<size;i++)
    {
        if(table[s[i]]!=-1)
        {
            int preIdx=table[s[i]];
            if(preIdx>=currtL)
            {
                int tmp=i-currtL;
                if(tmp>ret)
                {
                    ret=tmp;
                }
                currtL=preIdx+1;
                if(size-currtL<=ret){break;}
            }
        }
        table[s[i]]=i;
    }
    if(ret<currtR-currtL+1)
    {
      ret=currtR-currtL+1;
    }
    return ret;
}
};
