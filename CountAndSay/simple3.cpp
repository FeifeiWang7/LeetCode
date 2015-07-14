string say(string s) {
    if (s.size() < 1) return "";
    if (s.size() == 1) return "1" + s;

    int     count = 1, i = 1;
    string retVal = "";

    for (; i < s.size(); i++) {
        if (s[i] != s[i - 1]) {
            retVal += to_string(count) + s[i - 1];
            count = 1;
        } else {
            count ++;
        }
    }

    return retVal + to_string(count) + s[i - 1];
}

string countAndSay(int n) {
    if (n < 1) return "";
    if (n == 1) return "1";

    return say(countAndSay(n - 1));
}
