bool isAnagram(char* s, char* t) {
    if(s==NULL && t==NULL) return true;
    if(strlen(s) != strlen(t)) return false;

    int a[26]={0};
    for(int i=0;i<strlen(s);i++){
        a[s[i]-'a']++;
        a[t[i]-'a']--;
    }

    for(int i=0;i<26;i++){
        if(a[i]<0) return false;
    }
    return true;
}
///
bool isAnagram(char* s, char* t) {
int M[26] = {0};
while(*(s)!='\0') M[*(s++)-97]++;
while(*(t)!='\0'){
    if(M[*(t)-97] > 0) M[*(t)-97]--;
    else{
        M[*(t)-97] ++;
    }
    t++;
}
for(int i=0;i<26;i++){
    if (M[i] > 0) return false;
}
return true;
}
///
bool isAnagram(char* s, char* t) {
    int count[26] = {0};
    char c;
    while ((c=*s++)!='\0')
        count[c-'a']++;
    while ((c=*t++)!='\0')
        count[c-'a']--;
    for (int i=0; i<26 ;++i)
        if (count[i]!=0)
            return 0;
    return 1;
}
