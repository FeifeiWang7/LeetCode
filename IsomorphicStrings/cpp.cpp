class Solution {
public:
    bool isIsomorphic(string s, string t) {
         int size=s.size();
         if (size==0)
            return true;
        char ch[128],ismap[128];
        for(int i=0;i<128;i++)
        {`enter code here`
            ch[i]=-1;
            ismap[i]=-1;
        }
        bool flag=true;
        for(int i=0;i<size;i++)
        {
            if(ch[s[i]]==-1&&ismap[t[i]]==-1)
            {
                ch[s[i]]=t[i];
                ismap[t[i]]=s[i];

            }else if(ch[s[i]]!=t[i]||ismap[t[i]]!=s[i])
            {
                flag=false;
                break;
            }
        }
        return flag;
    }
};
/////
class Solution {
public:
    bool isIsomorphic(string s, string t) {

        unordered_map<char, char> isomorph;
        unordered_set<char> dest;

        for(int i = 0; i < s.size(); i++)
        {
            auto isIn = isomorph.find(s[i]);
            if(isIn != isomorph.end())
            {
                if(isIn->second != t[i])
                    return false;
            }
            else
            {
                auto isInDest = dest.find(t[i]);
                if(isInDest == dest.end())
                {
                    isomorph[s[i]] = t[i];
                    dest.insert(t[i]);
                }
                else
                    return false;
            }
        }

        return true;
    }
};
/////
bool isIsomorphic(char * s, char * t) {
    char dict0 [128] = {0};
    char dict1 [128] = {0};
    for (int i = 0; s[i] != '\0'; ++i)
    {
        char sc = s[i], tc = t[i];
        if (dict0[sc] == 0 && dict1[tc] == 0)
        {
            dict0[sc] = tc;
            dict1[tc] = sc;
        }else if (dict0[sc] != tc)
        {
            return false;
        }else if (dict1[tc] != sc)
        {
            return false;
        }
    }
    return true;
}
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        array <char, 128> dict0 {0}, dict1 {0};

        for (int i = 0; i < s.size(); ++i)
        {
            char sc = s[i], tc = t[i];
            if (dict0[sc] == 0 && dict1[tc] == 0)
            {
                dict0[sc] = tc;
                dict1[tc] = sc;
            }else if (dict0[sc] != tc)
            {
                return false;
            }else if (dict1[tc] != sc)
            {
                return false;
            }
        }

        return true;
    }
};
////
public class Solution {
    public boolean isIsomorphic(String s, String t) {
        Map<Character,Character> m = new HashMap<Character,Character>();
        StringBuilder sb = new StringBuilder();
        for(int i = 0; i < s.length(); i++){
            char sL = s.charAt(i);
            if (!m.containsKey(sL)) m.put(sL, t.charAt(i));
            sb.append(m.get(sL));
        }
        List<Character> lList = new ArrayList<Character>(m.values());
        Set<Character> lSet = new HashSet<Character>(m.values());
        return lList.size() == lSet.size() && sb.toString().equals(t);
    }
}
////
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int s2n[256]={0}, t2n[256]={0};
        for(int i=0; i<s.size(); i++){
            if(s2n[s[i]]>0||t2n[t[i]]>0){
                if(s2n[s[i]]==t2n[t[i]]) continue;
                else return false;
            }
            else{
                s2n[s[i]]=i+1;//map char s[i] to location of s[i] in s, should be the same mapping of t[i] to location t[i] in t
                t2n[t[i]]=i+1;
            }

        }
        return true;
    }
};
////
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if(s.size() != t.size())
            return false;
        char words[256] = {0}, wordt[256] = {0};
        for(int i=0; i<s.size(); i++){
            if(words[s[i]] == 0)
                words[s[i]] = t[i];
            else if(words[s[i]] != t[i])
                return false;
            if(wordt[t[i]] == 0)
                wordt[t[i]] = s[i];
            else if(wordt[t[i]] != s[i])
                return false;
        }
        return true;
    }
};
///
class Solution {
public:
    bool isIsomorphic(string s, string t) 
    {
        const size_t n = s.size();
        if ( n != t.size())
            return false;

        unsigned char forward_map[256] = {}, reverse_map[256] = {};

        for ( int i=0; i < n; ++i)
        {
            unsigned char c1 = s[i];
            unsigned char c2 = t[i];

            if ( forward_map[c1] && forward_map[c1] != c2)
                return false;

            if ( reverse_map[c2] && reverse_map[c2] != c1)
                return false;

            forward_map[c1] = c2;
            reverse_map[c2] = c1;
        }

        return true;
    }
};
/////
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if (s.empty())
            return true;
        return helper(s, t) && helper(t, s);
    }
    bool helper(string s, string t) {
        unordered_map<char, char> m;
        for (auto i = 0; i != s.size(); ++i) {
            if (!m.count(s[i])) {
                m.insert({s[i], t[i]});
            }
            else if (m[s[i]] != t[i])
                return false;
        }
        return true;
    }
};
////////
Use two vectors as flag to record the offset of each character in string s and t. The range of offset is -255 to 255, so we can set a value outside the range as the initial value, and in the following code, it is 1000.

class Solution  {
public:
    bool isIsomorphic(std::string s, std::string t) {
        std::string::size_type len1 = s.size(), len2 = t.size();
        if (len1 != len2)
            return false;
        std::vector<int> flag1(256, 1000), flag2(256, 1000);
        for (std::string::size_type i = 0; i != len1; ++i) {
            int pos1 = s[i] + 128, pos2 = t[i] + 128, dif = s[i] - t[i];
            if (flag1[pos1] == 1000)
                flag1[pos1] = dif;
            else if (flag1[pos1] != dif)
                return false;
            if (flag2[pos2] == 1000)
                flag2[pos2] = dif;
            else if (flag2[pos2] != dif)
                return false;
        }
        return true;
    }
};
or

class Solution {
public:
    bool isIsomorphic(std::string s, std::string t) {
        std::string::size_type len1 = s.size(), len2 = t.size();
        if (len1 != len2)
            return false;
        std::vector<int> flag(512, 1000);
        for (std::string::size_type i = 0; i != len1; ++i) {
            int pos1 = s[i] + 128, pos2 = t[i] + 384, dif = s[i] - t[i];
            if (flag[pos1] == 1000)
                flag[pos1] = dif;
            else if (flag[pos1] != dif)
                return false;
            if (flag[pos2] == 1000)
                flag[pos2] = dif;
            else if (flag[pos2] != dif)
                return false;
        }
        return true;
    }
};
