int strStr(string haystack, string needle) {
    int i,j,h_size,n_size;
    h_size=haystack.size();
    n_size=needle.size();
    if(!n_size)
        return 0;
    if(!h_size)
        return -1;

    vector<int> next(n_size,0);
    next[0]=-1;
    for(i=1,j=0;i<n_size;i++){
        if(needle[i]==needle[j]){

            next[i]=j;
            j++;
        }
        else if(needle[i]!=needle[j]){
            next[i]=-1;
            j=0;
        }
    }

    for(i=0,j=0;i<h_size;){
        if(haystack[i]==needle[j]){
            if(j==n_size-1)
                return i-j;
            else{
                i++;
                j++;
            }
        }
        else{
            if(j==0||next[j-1]==-1){
                j=0;
                if(haystack[i]!=needle[0])
                    i++;        
            }
            else
                j=next[j-1]+1;
        }
    }
    return -1;
}

