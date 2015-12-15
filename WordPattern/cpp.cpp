class Solution {
public:
    bool wordPattern(string pattern, string str) {
        if(!pattern.size() && !str.size())
            return true;
        int wrd_cnt = 0;
        int idx = 0;
        for(int i = 0; i < pattern.size(); ++ i){
            char kv = pattern[i];
            string wkv = "";
            while(str[idx] == ' ' && idx < str.size())
                ++ idx;
            while(str[idx] != ' ' && idx < str.size()){
                wkv += str[idx];
                ++ idx;
            }
            if(ptn_wrd.find(kv) != ptn_wrd.end()){
                if(ptn_wrd[kv] != wkv)
                    return false;
            }else{
                ptn_wrd[kv] = wkv;
                if(wrd_ptn.find(wkv) != wrd_ptn.end()){
                    if(wrd_ptn[wkv] != kv)
                        return false;
                }else{
                    wrd_ptn[wkv] = kv;
                }
            }
            ++ wrd_cnt;
            if(idx >= str.size())
                break;
        }
        if(wrd_cnt != pattern.size() || (wrd_cnt == pattern.size() && idx < str.size()))
            return false;
        return true;
    }
private:
unordered_map<char,string> ptn_wrd;
unordered_map<string, char> wrd_ptn;
};
////
I think all previous C++ solutions read all words into a vector at the start. Here I read them on the fly.

bool wordPattern(string pattern, string str) {
    map<char, int> p2i;
    map<string, int> w2i;
    istringstream in(str);
    int i = 0, n = pattern.size();
    for (string word; in >> word; ++i) {
        if (i == n || p2i[pattern[i]] != w2i[word])
            return false;
        p2i[pattern[i]] = w2i[word] = i + 1;
    }
    return i == n;
}

///
bool wordPattern(string pattern, string str) {
    // split str by " "
    vector<string> vs;
    istringstream strcin(str);
    string s;
    while (strcin >> s) vs.push_back(s);
    if (pattern.size() != vs.size()) return false;

    // The same method of "Isomorphic Strings" by grandyang
    map<char, int> mpc;
    map<string, int> mps;
    for (int i = 0; i < pattern.size(); ++i) {
        if (mpc[pattern[i]] != mps[vs[i]]) return false;
        mpc[pattern[i]] = i + 1;
        mps[vs[i]] = i + 1;
    }
    return true;
}
////
bool wordPattern(string pattern, string str) {
        istringstream strcin(str);
        string s;
        vector<string> vs;
        while(strcin >> s) vs.push_back(s);
        if (pattern.size() != vs.size()) return false;
        map<string, char> s2c;
        map<char, string> c2s;
        for (int i = 0; i < vs.size(); ++i) {
            if (s2c[vs[i]] == 0 && c2s[pattern[i]] == "") { 
                s2c[vs[i]] = pattern[i]; 
                c2s[pattern[i]] = vs[i]; 
                continue; 
            }
            if (s2c[vs[i]] != pattern[i]) return false;
        }
        return true;
    }
