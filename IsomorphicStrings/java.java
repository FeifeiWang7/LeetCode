if(s.length() == 0) return true;

    Map<Character, Integer> m1 = new HashMap<Character, Integer>();
    Map<Character, Integer> m2 = new HashMap<Character, Integer>();

    for(int i = 0; i < s.length(); i++) {
        if(!m1.containsKey(s.charAt(i))) m1.put(s.charAt(i), i);
        if(!m2.containsKey(t.charAt(i))) m2.put(t.charAt(i), i);
        if(m1.size() != m2.size()) {
            return false;
        } else {
            if(m1.get(s.charAt(i)) != m2.get(t.charAt(i))) return false;
        }
    }

    return true;
//////
you can simplify it to use a single hashmap, more efficient

import java.util.*;
public class Solution {
    public boolean isIsomorphic(String s, String t) {
        HashMap<Character, Character> charMap = new HashMap<Character, Character>();
        for(int i = 0; i < s.length(); i++)
        {
            if (charMap.containsKey(s.charAt(i)))
            {
                if (t.charAt(i) != charMap.get(s.charAt(i)))
                     return false;
            }
            else if (charMap.containsValue(t.charAt(i)))
                return false;
            else
                charMap.put(s.charAt(i), t.charAt(i));
        }
        return true;
    }
}
//////
public class Solution {
    public boolean isIsomorphic(String s, String t) {
        if(s.equals(t)){
            return true;
        }
        if(s.length() != t.length()){
            return false;
        }
        if(s == null && t == null){
            return false;
        }
        HashMap<Character, Character> map = new HashMap<Character, Character>();
        char[] s_array = s.toCharArray();
        char[] t_array = t.toCharArray();
        for(int i = 0; i < s_array.length; i++){
            if(!map.containsKey(s_array[i])){ // if map does not contain current key
                if(map.containsValue(t_array[i])){ // if the current value has been mapped by other keys
                    return false;
                }
                map.put(s_array[i], t_array[i]);
            }else{ // if map contains current key, judge whether current value equals the mapped value
                if(!(map.get(s_array[i]) == t_array[i])){
                    return false;
                }
            }
        }
        return true;        
    }
}
//////
public class Solution {
public boolean isIsomorphic(String s, String t) {

    if(s.length() != t.length())
        return false;

    //using ASCII code to map the char
    int S[] = new int[256];
    int T[] = new int[256];

    for(int i=0; i<256; i++){
        S[i] = -1;
        T[i] = -1;

    }

    char[] sarr = s.toCharArray();
    char[] tarr = t.toCharArray();

    int len = sarr.length;

    for(int i=0; i<len; i++){

        int sn = (int)sarr[i]; 
        int tn = (int)tarr[i];

        if( S[sn]==-1 && T[tn]==-1 ){
            S[sn]=tn;
            T[tn]=sn;
        }else if(S[sn]!=tn || T[tn]!=sn)
            return false;
    }

    return true;

}
}
/////
public boolean isIsomorphic(String s, String t) {
    if(s == null || t == null){
        return false;
    }

    if(s.length() == 0 && t.length() == 0){
        return true;
    }

    int len = s.length();
    HashMap<Character, Character> map = new HashMap<Character, Character>();

    for(int i = 0; i < len; i++){
        char sc = s.charAt(i);
        char st = t.charAt(i);

        if(map.containsKey(sc)){
            if(st != map.get(sc)){
                return false;
            }

        }else{
            if(map.containsValue(st)){
                return false;
            }
            map.put(sc, st);
        }
    }

    return true;
}
////
288ms Java solution. OJ told me this is fastest so far (at least one of the fastest). Please do point out where improvement can be made.

public boolean isIsomorphic(String s, String t) {
        if (s.length() == 0) return true;

        char[] stable = new char[128];
        char[] ttable = new char[128];
        for (int i = 0; i < 128; ++i){
            stable[i] = 0;
            ttable[i] = 0;
        }

        char[] sc = s.toCharArray();
        char[] tc = t.toCharArray();

        for (int i = 0; i < s.length(); ++i){
            char schar = sc[i];
            char tchar = tc[i];
            if (stable[schar] == 0 && ttable[tchar] == 0){
                stable[schar] = tchar;
                ttable[tchar] = schar;
            }else if(stable[schar] == tchar && ttable[tchar] == schar){
                continue;
            }else{
                return false;
            }
        }

        return true; 

    }

/////
public boolean isIsomorphic(String s, String t) {
    if(s.length() != t.length()) return false;
    HashMap<Character, Character> hash = new HashMap<Character, Character>();
    for(int i = 0; i < s.length(); i++){
        if(hash.containsKey(s.charAt(i))){
            if(t.charAt(i) != hash.get(s.charAt(i))) return false;
        }else{
            if(hash.containsValue(t.charAt(i))) return false;
            else hash.put(s.charAt(i), t.charAt(i));
        }
    }
    return true;
}
/////
public static boolean isIsomorphic(String s, String t) {
    if(s.length() != t.length()) return false;
    Map<Character, Character> mapStoT = new HashMap<>();
    Map<Character, Character> mapTtoS = new HashMap<>();
    char[] chars1 = s.toCharArray();
    char[] chars2 = t.toCharArray();
    int[] compare = new int[chars1.length];
    for (int i = 0; i < chars1.length; i++) {
        char c1 = chars1[i];
        char c2 = chars2[i];
        mapStoT.putIfAbsent(c1, c2);
        mapTtoS.putIfAbsent(c2, c1);

        if(c1 != mapTtoS.get(c2) || c2 != mapStoT.get(c1)) return false;

    }
    return true;

}
////
Hi,

After submitting my code, I saw there are some c solution can achieve 0ms. So, I'm wondering how it could be? Shouldn't we at least iterate all the chars before we know the answer and thus at least O(N) solution at the worst case?

Bellow are my 2 pass solution, without using a formal Hash. It is benchmarked as 8ms.

    class Solution {
    public:
    bool isIsomorphic(string s, string t) {
       if(doo(s,t) && doo(t,s)) return true;
       return false;
    }

    bool doo(string& s, string& t){
        int h[256] = {0};
        int N = s.length();
        for (int i = 0 ; i < N; i++) {
            int j = s[i];
            if (h[j] == 0) {h[j] = t[i];}
            if ((h[j] != 0) && (h[j] != t[i])) {return false;}
        }
        return true; 
    }
    };
/////
bool isIsomorphic(string a, string b) {
    if(a.size()!=b.size()) return false;
    vector<char> aTob(128, NULL);
    vector<char> bToa(128, NULL);
    for (int i=0; i<a.size(); i++) {
        if(!aTob[a[i]] && !bToa[b[i]]) {
            aTob[a[i]] = b[i];
            bToa[b[i]] = a[i];
        }
         else if(aTob[a[i]]!=b[i] || bToa[b[i]]!=a[i])
         return false;
    }
    return true;
}
////
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        char shash[256] = {0};
        char thash[256] = {0};

        //Complexity : O(n)
        for(int i = 0;i < s.length();++i) {
            //Bi-direction hashing

            /* Hash From s to t */
            if(shash[s[i]] != 0) {
                if(shash[s[i]] != t[i])return false;
            }
            else shash[s[i]] = t[i];

            /* Hash From t to s */
            if(thash[t[i]] != 0) {
                if(thash[t[i]] != s[i])return false;
            }
            else thash[t[i]] = s[i];
        }
        return true;
    }
};
////
The general strategy is to traverse the two strings and make sure that there exists a one-to-one mapping between the character set of one string and the character set of the other. There's no real need for an unordered_map or other hash map because the range of values we're dealing with (characters) is relatively small.

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        array<char, 128> mp_f {0}, mp_r{0};
        for (int i = 0; i < s.size(); ++i) {
            char c = s[i], d = t[i];
            if (mp_f[c] && mp_f[c] != d) { return false; }
            if (mp_r[d] && mp_r[d] != c) { return false; }
            mp_f[c] = d, mp_r[d] = c;
        }
        return true;
    }
};
///
bool isIsomorphic(string s, string t) {
        char map_s[128] = { 0 };
        char map_t[128] = { 0 };
        int len = s.size();
        for (int i = 0; i < len; ++i)
        {
            if (map_s[s[i]]!=map_t[t[i]]) return false;
            map_s[s[i]] = i+1;
            map_t[t[i]] = i+1;
        }
        return true;    
    }

////
public class Solution {
    public boolean isIsomorphic(String s, String t) {
        if(s == null || s.length() <= 1) return true;
        HashMap<Character, Character> map = new HashMap<Character, Character>();
        for(int i = 0 ; i< s.length(); i++){
            char a = s.charAt(i);
            char b = t.charAt(i);
            if(map.containsKey(a)){
                 if(map.get(a).equals(b))
                continue;
                else
                return false;
            }else{
                if(!map.containsValue(b))
                map.put(a,b);
                else return false;

            }
        }
        return true;

    }
}

////
onePass only validates whether source can be translated into target, which does not necessarily lead to the conclusion source and target are isomorphic. But it does if target can be translated into source as well.

public boolean isIsomorphic(String s, String t) {
    return onePass(s,t) && onePass(t,s);
}

public boolean onePass(String s, String t)
{
    HashMap<Character, Character> map = new HashMap<Character, Character>();
    for(int i = 0; i < s.length(); i++)
    {
        char cs = s.charAt(i);
        char ct = t.charAt(i);
        if(!map.containsKey(cs)){
            map.put(cs, ct);
        }else{
            if(map.get(cs) != ct)
                return false;
        }
    }
    return true;
}
///
public boolean isIsomorphic(String s, String t) {
char[] maps = new char[128];
char[] mapt = new char[128];
for (int i = 0; i < s.length(); i++) {
    if ((maps[s.charAt(i)] != 0 && maps[s.charAt(i)] != t.charAt(i)) || (mapt[t.charAt(i)] != 0 && mapt[t.charAt(i)] != s.charAt(i))) {
    return false;
    }
    maps[s.charAt(i)] = t.charAt(i);
    mapt[t.charAt(i)] = s.charAt(i);
}
return true;
}

////
public class Solution {
public boolean isIsomorphic(String s, String t) {
    if(s.length() == 0)
        return true;
    HashMap<Character, Character>map = new HashMap<Character, Character>();
    HashSet<Character> keys = new HashSet<Character>();
    HashSet<Character> values = new HashSet<Character>();
    char[] chs = s.toCharArray();
    char[] cht = t.toCharArray();
    for (int i = 0; i < chs.length; i++) {
        if(!keys.contains(chs[i])) {
            if(values.contains(cht[i]))
                return false;
            map.put(chs[i], cht[i]);
            keys.add(chs[i]);
            values.add(cht[i]);
        } else {
            if(cht[i] != map.get(chs[i]))
                return false;
        }
    }
    return true;
}
}
////
public class Solution {
    public boolean isIsomorphic(String s, String t) {
        if(s.length()!=t.length()){
            return false;
        }
      //to check case like "ab" "aa". Need to replace key&value and check it again.
        return checkIsomorphic(s,t)&&checkIsomorphic(t,s);

    }

    private boolean checkIsomorphic(String s, String t) {
        HashMap<Character,Character> occMap = new HashMap<Character,Character>();
        for(int i=0;i<s.length();i++){
            char cs = s.charAt(i);
            char ct = t.charAt(i);
            if(!occMap.containsKey(cs)){
                occMap.put(cs, ct);
            }else{
                char val1 = occMap.get(cs);
                if(ct!=val1)
                    return false;
            }
        }
        return true;
    }
}
///
Hi guys!

The main idea is to store the last seen positions of current (i-th) characters in both strings. If previously stored positions are different then we know that the fact they're occuring in the current i-th position simultaneously is a mistake. We could use a map for storing but as we deal with chars which are basically ints and can be used as indices we can do the whole thing with an array.

Check the code below. Happy coding!

public class Solution {
    public boolean isIsomorphic(String s1, String s2) {
        int[] m = new int[512];
        for (int i = 0; i < s1.length(); i++) {
            if (m[s1.charAt(i)] != m[s2.charAt(i)+256]) return false;
            m[s1.charAt(i)] = m[s2.charAt(i)+256] = i+1;
        }
        return true;
    }
}
///
public class Solution {
    public boolean isIsomorphic(String s, String t) {
        if(s == null || t == null){
            return false;
        }
        if(s.length() == 0 || t.length() == 0){
            return true;
        }

        Map<Character,Character> corr = new HashMap<Character,Character>();
        for(int i = 0; i < s.length(); i ++){
            char sc = s.charAt(i);
            char tc = t.charAt(i);
            if(corr.containsKey(sc)){
                if(corr.get(sc) != tc){
                    return false;
                }
            }
            else{
                if(corr.containsValue(tc)){
                    return false;   
                }
                else{
                    corr.put(sc,tc);
                }
            }
        }
        return true;
    }
}
///
I used two maps for the one-one mapping relation for the two strings. This may waste more memory, but the logic is really simple.

public boolean isIsomorphic(String s, String t) {
    if(s == null)
        return t == null;

    Map<Character, Character> map = new HashMap<>(), 
            mapR = new HashMap<>();
    for(int i = 0; i < s.length(); i++){
        char cS = s.charAt(i), cT = t.charAt(i);
        map.putIfAbsent(cS, cT);
        mapR.putIfAbsent(cT, cS);
        if(map.get(cS) != cT || mapR.get(cT) != cS)
            return false;
    }
    return true;
}
