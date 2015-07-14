bool isValid(string s) {
    std::stack<char> bra;
    for(auto c : s)
    {
        switch(c)
        {
        case '(':
        case '[':
        case '{': bra.push(c); break;
        case ')':
            if (bra.empty() || bra.top() != '(') return false;
            else bra.pop(); 
            break;
        case ']':
            if (bra.empty() || bra.top() != '[') return false;
            else bra.pop(); 
            break;
        case '}':
            if (bra.empty() || bra.top() != '{') return false;
            else bra.pop(); 
            break;
        default :throw;
        }
    }
    return bra.empty();
}
