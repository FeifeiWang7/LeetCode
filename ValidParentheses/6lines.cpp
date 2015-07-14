bool isValid(string s) {
    stack<char>st;
    for (string::iterator i = s.begin(); i != s.end(); ++i){
        if (!st.empty() && ((*i - st.top() == 1) || (*i - st.top() == 2)))st.pop();
        else st.push(*i);
    }
    return st.empty();
}
