use c 0ms
    char* longestCommonPrefix(char** strs, int strsSize) 
    {
        if(strsSize==0)return "";
        if(strsSize==1)return strs[0];
        int msize=strlen(strs[0]);
        for(int i=0;i<strsSize;i++)
        {
            if(strlen(strs[i])==0||strs[i][0]!=strs[0][0])
            return "";
            if(strlen(strs[i])<msize)msize=strlen(strs[i]);
        }
       char* result=malloc(sizeof(char)*msize);
       int top=0;
       for(int i=0;i<strlen(strs[0]);i++)
       {
           for(int j=0;j<strsSize;j++)
           {
               if(strs[j][i]!=strs[0][i])
               {
                   result[top]='\0';
                   return result;
               }
           }
          result[top++]=strs[0][i];
       }
          result[top]='\0';
        return result;
    }
