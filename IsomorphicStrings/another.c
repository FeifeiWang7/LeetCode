bool isIsomorphic(char* s, char* t) {
    int ms[255]={0};
    int mt[255]={0};
    char *ps=s;
    char *pt=t;
    while(0!=*ps){
        int i = *ps;
        int j = *pt;
        if(0!=ms[i]){
            if(ms[i]!=j)
                return false;
        } else {
            if(0!=mt[j])
                return false;
            ms[i]=j;
            mt[j]=i;
        }

        ++pt;
        ++ps;
    }
    return true;
}
////
The idea is to use two arrays to store the mappings between corresponding characters of s and t.

bool isIsomorphic(char* s, char* t) {
    char map[256], rmap[256];

    memset(map, 0, sizeof map);
    memset(rmap, 0, sizeof rmap);
    for ( ; *s; ++s, ++t)
        if (!map[*s]) {
            if (rmap[*t]) // another character already maps to *t
                return false;

            map[*s] = *t;
            rmap[*t] = *s;
        } else if (map[*s] != *t)
            return false;

    return true;
}
//////
bool isIsomorphic(char* s, char* t) {
    char charArrS[256] = { 0 };
    char charArrT[256] = { 0 };
    int i = 0;
    while (s[i] !=0)
    {
        if (charArrS[s[i]] == 0 && charArrT[t[i]] == 0)
        {
            charArrS[s[i]] = t[i];
            charArrT[t[i]] = s[i];
        }
        else
        if (charArrS[s[i]] != t[i] || charArrT[t[i]] != s[i])
            return false;
        i++;
    }

    return true;
}
///
bool isIsomorphic(char* s, char* t)
{
    int i;
    int hash[256];
    int hash1[256]={0};
    memset(hash,-1,sizeof(hash));
    bool flag = true;
    int len1 = strlen(s);
    int len2= strlen(t);
    if( len1 != len2 )return false;
    for(i=0;i<len1;i++)
    {
        if((hash[s[i]]!=-1&&hash[s[i]]!=t[i])||(hash1[t[i]]>0)&&hash[s[i]]<0)
        {
            flag = false;
            break;
        }
        hash[s[i]] = t[i];
        hash1[t[i]]++;
    }
    return flag;
}
////
bool isIsomorphic(char* s, char* t) 
{
    char mapAll[128] = "";
    int nLen = strlen(s);
    int i = 0;
    for (i=0; i<nLen; i++)
    {
        if(mapAll[s[i]] == 0)
        {
            mapAll[s[i]] = t[i];
            if(i >0 && mapAll[s[i]] == mapAll[s[i-1]])
                return false;
            continue;
        }
        if(mapAll[s[i]] != t[i])
            return false;
    }
    return true;
}
