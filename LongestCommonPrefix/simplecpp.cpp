class Solution {
    public:
        string longestCommonPrefix(vector<string>& strs)
        {
         if(strs.empty())return "";
         if(strs.size()==1)return strs[0];
        for(int i=0;i<strs.size();i++)
        {
            if(strs[i].length()==0||strs[i][0]!=strs[0][0])
            return "";
        }
        //now it be common
       string result="";
       for(int i=0;i<strs[0].length();i++)
       {
           for(int j=0;j<strs.size();j++)
           {
               if(strs[j][i]!=strs[0][i])
               {
                   return result;
               }
           }
          result+=strs[0][i];
       }
       return result;
        }
    };
