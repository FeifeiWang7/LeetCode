class Solution {
public:
    bool isValid(string s) {
        unordered_map<char, int> left{{'(', 1}, {'{', 2}, {'[', 3}};
        unordered_map<char, int> right{{')', 1}, {'}', 2}, {']', 3}};
        stack<char> st;
        for (auto x : s) {
            if (left.find(x) != left.end()) {
                st.push(x);
                continue;
            }
            if (st.empty()) return false;
            if (left[st.top()] == right[x]) {
                st.pop();
                continue;
            }
            return false;
        }
        return st.empty();
    }
};
