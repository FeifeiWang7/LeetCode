string addBinary(string a, string b) {
    int i = a.size() - 1;
    int j = b.size() - 1;
    int num = 0;
    string res;
    while (i>=0||j>=0)
    {
        int value1 = 0,value2 =0;
        if (i >= 0) value1 = a[i] - '0';
        if (j >= 0) value2 = b[j] - '0';

        num += (value1 + value2);
        res.push_back(num% 2 + '0');
        num /= 2;
        i--;
        j--;
    }
    if (num!=0) res.push_back(num+'0');
    reverse(res.begin(),res.end());
    return res;
}
