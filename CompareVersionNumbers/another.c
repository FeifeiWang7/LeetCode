int compareVersion(char* version1, char* version2) 
{

    int num1=0, num2=0;

    while(1)
    {
        num1=0;
        num2=0;
        while(version1[0]!='.' && version1[0]!='\0')
        {
            num1=num1*10+version1[0]-'0';
            version1++;
        }
        while(version2[0]!='.' && version2[0]!='\0')
        {
            num2=num2*10+version2[0]-'0';
            version2++;
        }
        if(version1[0]=='.') version1++;
        if(version2[0]=='.') version2++;

        if(num1>num2)return 1;
        else if(num2>num1)return -1;
        else if(version1[0]=='\0' && version2[0]=='\0')
        return 0;
    }


}
/////
int compareVersion(string version1, string version2) {
    int i = 0; 
    int j = 0;
    int n1 = version1.size(); 
    int n2 = version2.size();

    int num1 = 0;
    int num2 = 0;
    while(i<n1 || j<n2)
    {
        while(i<n1 && version1[i]!='.'){
            num1 = num1*10+(version1[i]-'0');
            i++;
        }

        while(j<n2 && version2[j]!='.'){
            num2 = num2*10+(version2[j]-'0');;
            j++;
        }

        if(num1>num2) return 1;
        else if(num1 < num2) return -1;

        num1 = 0;
        num2 = 0;
        i++;
        j++;
    }

    return 0;
}
//////

int compareVersion(char* version1, char* version2) { char *ver1 = NULL; char *ver2 = NULL; int val1=0,val2=0;

ver1 = version1;
ver2 = version2;

while((*ver1 != '\0')||(*ver2 != '\0')) {
    while((*ver1 != '\0') && (*ver1 != '.')) {
        val1 = (val1*10)+(*ver1-'0');
        ver1++;
    }
    while( (*ver2 != '\0') && (*ver2 != '.')) {
        val2 = (val2*10)+(*ver2-'0');
        ver2++;
    }
    if (val1 > val2) return 1;
    else if (val2 > val1) return -1;
    val1=val2=0;
    if (*ver1 =='.') ver1++;
    if (*ver2 =='.') ver2++;

}
return 0;
}
