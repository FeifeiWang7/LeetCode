class Solution {
public:
    int compareVersion(string version1, string version2) {
        version1.push_back(0), version2.push_back(0);
        auto p1=&version1[0],p2=&version2[0];
        while(1) {
            int x1=0, x2=0, tmp1=sscanf(p1,"%d",&x1), tmp2=sscanf(p2,"%d",&x2);
            if(x1<x2) return -1;
            if(x1>x2) return 1;
            if(tmp1==EOF || tmp2==EOF) return 0;
            while(*p1 && *p1++!='.') {}
            while(*p2 && *p2++!='.') {}
        }
    }
};
