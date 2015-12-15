int compareVersion(string version1, string version2) {
        int ver1 = 0, ver2 = 0;
        int i = 0, j = 0;
        while( (i < version1.length())||(j < version2.length()) ){
            // calc each version num
            while(isdigit(version1[i])&&(i < version1.length())) 
                ver1 = ver1*10 + version1[i++]-'0';  
            while(isdigit(version2[j])&&(j < version2.length()))
                ver2 = ver2*10 + version2[j++]-'0';
            if(ver1 < ver2)
                return -1;
            if(ver1 > ver2)
                return 1;
            ver1 = 0, ver2 = 0;
             i++; // get rid of '.'
             j++;
        }
        return 0;
    }
//////
int compareVersion(string version1, string version2) {
    istringstream ver1(version1 + "."), ver2(version2 + ".");
    int val1 = 0, val2 = 0;
    char dot = '.';
    while (ver1.good() || ver2.good()) {
        if (ver1.good()) ver1 >> val1 >> dot;
        if (ver2.good()) ver2 >> val2 >> dot;
        if (val1 > val2) return 1;
        else if (val1 < val2) return -1;
        val1 = val2 = 0;
    }
    return 0;
}/////
int compareVersion(string version1, string version2) {
    int i=0,j=0;
    while(i<version1.size()||j<version2.size()){
        int v1=0,v2=0;
        while(i<version1.size()&&version1[i]!='.') v1=v1*10+version1[i++]-'0';
        while(j<version2.size()&&version2[j]!='.') v2=v2*10+version2[j++]-'0';
        i++;j++;
        if(v1>v2) return 1;
        if(v1<v2) return -1;
    }
    return 0;
}
