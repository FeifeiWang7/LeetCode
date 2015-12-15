public boolean wordPattern(String pattern, String str) {

    String[] arr = str.split(" ");
    char[] patternarr = pattern.toCharArray();
    if(arr.length!= patternarr.length)
        return false;
    HashMap<Character, String> h = new HashMap<Character, String>();
    for(int i=0;i<patternarr.length;i++)
    {
        char c = patternarr[i];
        String temp = arr[i];
        if(!h.containsKey(c))
        {
            if(h.containsValue(temp))
                return false;
            else
                h.put(c,temp);
        }
        else
        {
            if(h.get(c).equals(temp))
                continue;
            else
                return false;
        }
    }
    return true;  
}
///
public boolean wordPattern(String pattern, String str) {

    Map<Character, String> map1 = new HashMap<>();
    Map<String, Character> map2 = new HashMap<>();
    String[] words = str.split(" +");
    if(pattern.length() != words.length) return false;

    for(int i = 0; i < pattern.length(); ++i) {
        char c = pattern.charAt(i);
        String word = words[i];

        if(map1.containsKey(c) && !map1.get(c).equals(word)) {
            return false;
        }
        if(map2.containsKey(word) && map2.get(word) != c) {
            return false;
        }
        map1.put(c, word);
        map2.put(word, c);
    }
    return true;
}
///
public class Solution {
public boolean wordPattern(String pattern, String str) {
    String[] words =str.split(" ");
    if(words.length!=pattern.length()) return false;
    Map<Character,String> map =new HashMap();
    Set<String> set =new HashSet();
    int index=0;
    for(String word: words){
        String pre = map.put(pattern.charAt(index++),word); // previous word related to the key
        if((pre!=null && !pre.equals(word)) || (pre==null && set.contains(word))) return false; 
        set.add(word);
    }
    return true;
}
}
/////
public boolean wordPattern(String pattern, String str) {
    String[] words = str.split(" ");
    if (words.length != pattern.length())
        return false;
    Map index = new HashMap();
    for (int i=0; i<words.length; ++i)
        if (!Objects.equals(index.put(pattern.charAt(i), i),
                            index.put(words[i], i)))
            return false;
    return true;
}
////
public class Solution {
public boolean wordPattern(String pattern, String str) {
    String[] array = str.split(" ");
    int size = pattern.length();

    if (array.length != size) return false;

    Map<Character, String> map = new HashMap<>();
    Map<String, Character> dup = new HashMap<>();

    for (int i=0; i<size; i++) {
        char c = pattern.charAt(i);
        String s = array[i];
        if (map.containsKey(c) && !s.equals(map.get(c))) {
            return false;
        }
        if (dup.containsKey(s) && c != dup.get(s)) {
            return false;
        }
        map.put(c, s);
        dup.put(s, c);
    }
    return true;
}
}
/////
class Solution {
public:
    bool wordPattern(string pattern, string str) {
    int pnum=pattern.size();
    int strnum=1;
    for(int i=0;i<str.size();i++)
        if(str[i]==' ')
            strnum++;
    if(strnum!=pnum) return false;
    map<char,string> ptostr;
    map<string,char> strtop;
    istringstream is(str);
    for(int i=0;i<pattern.size();i++)
    {
        string curstr;
        is>>curstr;
        if(!ptostr.count(pattern[i])&&!strtop.count(curstr))
        {
            ptostr[pattern[i]]=curstr;
            strtop[curstr]=pattern[i];
        }
        else if(curstr!=ptostr[pattern[i]]||pattern[i]!=strtop[curstr])
            return false;
    }
    return true;
    }
};
///
public boolean wordPattern(String pattern, String str) {
    if(pattern == null || pattern.length() == 0|| str == null ||  str.length() == 0)
        return false;
    String s[] = str.split(" ");
    if(s.length != pattern.length())
        return false;
    Map<String, Character> memo = new HashMap<>();
    Set<Character> exist = new HashSet<>();
    for(int i = 0 ; i < s.length ; i++){
        if(memo.containsKey(s[i])){
            if(memo.get(s[i]) != pattern.charAt(i))
                return false;
        }else{
            if(!exist.contains(pattern.charAt(i))){
                memo.put(s[i], pattern.charAt(i));
                exist.add(pattern.charAt(i));
            }
            else
                return false;
        }
    }
    return true;
}
