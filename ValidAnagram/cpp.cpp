class Solution {
public:
    bool isAnagram(string s, string t) {
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        return s == t;     
    }
};
///
bool isAnagram(string s, string t) {
    int alp[26]={};
    for (int i = 0; i < s.length(); i++) 
        alp[s.at(i) - 'a']++;
    for (int i = 0; i < t.length(); i++)
        alp[t.at(i) - 'a']--;
    for (int i=0;i<26;i++)
        if (alp[i] != 0) 
            return false;
        return true;
   }
/////
class Solution { public: bool isAnagram(string s, string t) { //use 26 array if(s.size() != t.size()) { return false; }

    int arr[26]={0};
    for(int ii=0; ii<s.size(); ++ii)
    {
        ++arr[s[ii]-'a'];
        --arr[t[ii]-'a'];
    }

    for(int ii=0; ii<26; ++ii)
    {
        if(arr[ii] != 0)
        {
            return false;
        }
    }
    return true;
}
};
///
int alphabetS[26] = { 0 };
    int alphabetT[26] = { 0 };
    for (auto c : s)alphabetS[c - 'a'] ++;
    for (auto c : t)alphabetT[c - 'a'] ++;
    return memcmp(alphabetS,alphabetT, 26* sizeof(int)) == 0;
///
class Solution {
public:
bool isAnagram(string s, string t) {
vector<int> counters(26,0);
vector<int> countert(26,0);
for(int i=0;i!=s.size();++i){
    counters[s[i]-'a']++;
}
for(int i=0;i!=t.size();++i){
    countert[t[i]-'a']++;
}
return counters==countert;
}
};
