string longestCommonPrefix(vector<string>& strs) {
    if(strs.size() == 0) 
        return "";

    string result;
    for(int i = 0; i<strs[0].length(); i++) {
        char c = strs[0][i];
        for(int j = 0; j<strs.size(); j++) {
            if(strs[j][i] != c)
                return result;
        }

        result += c;
    }

    return result;
}
