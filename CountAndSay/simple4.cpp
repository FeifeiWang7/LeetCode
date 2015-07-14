class Solution {
public:
    string countAndSay(int n) {
        if(n<1)return "";
        string Out="1",Cha;
        char Num='1';
        for(int loop=1;loop<n;loop++)
        {
            Cha=Out;
            Out.clear();
            for(int i=0;i<Cha.size();i++)
            {
                if(Cha[i]!=Cha[i+1]||i+1==Cha.size())
                {
                    Out+=Num;
                    Out+=Cha[i];
                    Num='1';
                }else
                {
                    ++Num;
                }
            }
        }
        return Out;
    }
};
