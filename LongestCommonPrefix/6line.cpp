class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) return "";
        for (int pos = 0; pos < strs[0].length(); pos++)
            for (int i = 1; i < strs.size(); i++)
                if (pos >= strs[i].length() || strs[i][pos] != strs[0][pos])
                    return strs[0].substr(0, pos);
        return strs[0];
    }
};
