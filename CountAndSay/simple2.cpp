class Solution {
public:
    string countAndSay(int n) 
    {
        string str = "1",res;
        for(int k=2; k<=n; ++k)
        {
            int num = 1;
            for(int i=0; i<str.size(); ++i)
            {
                char text = str[i];
                if(i+1 < str.size() && text == str[i+1])
                    ++num;
                else
                {
                    res.push_back(num+'0');
                    res.push_back(text);
                    num = 1;
                }
            }
            str = res;
            res.clear();
        }
        return str;
    }
};
