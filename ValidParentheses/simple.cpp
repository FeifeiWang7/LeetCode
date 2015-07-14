class Solution {
public:
    bool isValid(string s) {
        stack<char> paren;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(' || s[i] == '{' || s[i] == '[')
                paren.push(s[i]);
            else if (s[i] == ')' || s[i] == '}' || s[i] == ']') {
                if (paren.empty()) return false;
                if (!match(paren.top(), s[i])) return false;
                paren.pop();
            }
        }
        return paren.empty();
    }
private:
    bool match(char s, char t) {
        if (t == ')') return s == '(';
        if (t == '}') return s == '{';
        if (t == ']') return s == '[';
    }
};
