class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        map<char,char> mymap;
        mymap['('] = ')';
        mymap['{'] = '}';
        mymap['['] = ']';

        for(int i=0;i<s.length();i++)
        {
            if( mymap.count(s[i])>0) st.push(s[i]);
            else if(st.empty()) return false;
            else if(mymap[st.top()]== s[i])  st.pop();
            else return false;
        }
        return st.empty();
    }
};
