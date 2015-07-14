map.insert(make_pair('<','>')); 

class Solution {
    map<char,char> mymap;
public:

    Solution() {
        mymap.insert(make_pair('(',')'));
        mymap.insert(make_pair('[',']'));
        mymap.insert(make_pair('{','}'));
    }

    bool isValid(string s) {
        int size = s.size();
        if(size == 0) {
            return true;
        }

        stack<char> st;
        for(auto bracket: s) {
            map<char,char>::iterator it = mymap.find(bracket);
            if(it != mymap.end()) {
                //We found an open bracket
                st.push(bracket);
            } else {
                //We found a closing bracket
                if(st.empty()) {
                    return false;
                }
                it = mymap.find(st.top());
                if(it->second != bracket) {
                    return false;
                } else {
                    st.pop();
                }
            }
        }

        if(st.empty()) {
            return true;
        } else {
            return false;
        }
    }
};
