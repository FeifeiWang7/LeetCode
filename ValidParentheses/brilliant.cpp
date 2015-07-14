bool isValid(string s) {
    int n = 0;
    for (char c : s)
        if (c%26%3)
            s[n++] = c;
        else if (!n || c%s[--n]>2)
            return false;
    return !n;
}
