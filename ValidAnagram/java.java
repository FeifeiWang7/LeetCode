public class Solution {

public boolean isAnagram(String s, String t) {
    if (s.length() != t.length() ) return false;
    int[] alphabet = new int[26];
    for(int i = 0; i< 26; i++) {
        alphabet[i] = 0;
    }
    for(int i = 0; i < s.length(); i++) {
        alphabet[s.charAt(i) - 'a']++;
    }
    for(int i = 0; i < t.length(); i++) {
        alphabet[t.charAt(i) - 'a']--;
        if(alphabet[t.charAt(i) -'a'] < 0) return false;
    }
    return true;


}
}
//////
public class Solution {
    public boolean isAnagram(String s, String t) {
        if(s==null && t == null) return true;
        if(s==null || t == null) return false;
        if(s.length()!=t.length()) return false;

        int[] ct= new int[26];

        for(int i=0; i<s.length();i++){
            ct[s.charAt(i)-'a']++;
        }
        for(int i=0; i<t.length();i++){
            ct[t.charAt(i)-'a']--;
            if(ct[t.charAt(i)-'a']<0) return false;
        }

        return true;
    }
}
///
public class Solution {
public boolean isAnagram(String s, String t) 
{
    char[] sChar = s.toCharArray();
    char[] tChar = t.toCharArray();

    Arrays.sort(sChar);
    Arrays.sort(tChar);

    return Arrays.equals(sChar, tChar);   
}
}

///
public class Solution {
    public boolean isAnagram(String s, String t) {
        if(s.length() != t.length() ){
            return false;
        }

        if(s == null && t == null){
            return false;
        }

        if(s.equals(t)){
            return true;
        }

        Map<Character, Integer> map = new HashMap<Character, Integer>();

        for(char a : s.toCharArray()){
            map.put(a, map.getOrDefault(a, 0) + 1);
        }

        for(char b : t.toCharArray()){
            if(map.containsKey(b)){
                map.put(b, map.get(b) - 1);
                if(map.get(b) == 0){
                    map.remove(b);
                }
            }else{
                map.put(b, map.getOrDefault(b, 0) + 1);
            }
        }

        if(map.isEmpty()){
            return true;
        }else{
            return false;
        }

    }
}
///
public class Solution {
public boolean isAnagram(String s, String t) {
    if(s.length() != t.length()) return false;
    int[] charArray = new int[256];
    for(int flag : charArray) flag = 0;
    for(char ch : s.toCharArray()) charArray[ch]++;
    for(char ch :t.toCharArray()){
        if(charArray[ch] == 0)
            return false;
        charArray[ch]--;
    }
    return true;
}
}
///
public class Solution {
public boolean isAnagram(String s, String t) {

    if (s.length() != t.length())
        return false ;

    //convert string into char array
    char[] cs = s.toCharArray() ; 
    char[] ct = t.toCharArray() ;

    qsort(cs, 0, cs.length-1);
    qsort(ct, 0, ct.length-1);

    for(int i=0 ; i< cs.length ; i++){
        if(cs[i] != ct[i])
            return false ;
    }

    return true;

}


public void qsort(char[] c , int l , int r){
    if(r<=l)
        return ;

    int p = partition(c,l,r);

    qsort(c,l,p-1);
    qsort(c,p+1,r);


}

public int partition(char[] c, int l, int r){

    int p = l-1;

    for(int i=l ; i<=r-1 ; i++){
        if(c[i] < c[r]){
            //swqp c[p+1] & c[i]
            char tmp = c[p+1] ; 
            c[p+1] = c[i];
            c[i] = tmp;

            p++;
        }
    }

    //swqp c[p+1] & c[r]
    char tmp = c[p+1] ; 
    c[p+1] = c[r];
    c[r] = tmp;

    return p+1 ;

}
}
///
I know it should be O(NlgN) solution. Just offer you another way.

   public class Solution {
        public boolean isAnagram(String s, String t) {
            char[] schar = s.toCharArray();
            char[] tchar = t.toCharArray();
            Arrays.sort(schar);
            Arrays.sort(tchar);
            s = new String(schar);
            t = new String(tchar);
            return s.equals(t);
        }
    }
///
public class Solution {
    public boolean isAnagram(String s, String t) {

        char[] charArr = s.toCharArray(); //Convert both strings to arrays
        Arrays.sort(charArr);             //Sort the arrays alphabetically
        String result = new String(charArr); //Create new strings to hold the values of the sorted arrays

        char[] charArr2 = t.toCharArray(); 
        Arrays.sort(charArr2); 
        String result2 = new String(charArr2); 

        return result.equals(result2); //Compare the two strings, if they are equal, they are anagrams of eachother
        }
}
///
public boolean isAnagram(String s, String t) {
        if(s.length() != t.length()) return false;

        int[] res1 = new int[26];
        int[] res2 = new int[26];

        for(int i = 0; i< s.length(); i++){
            char c = s.charAt(i);
            int index = c - 97;
            res1[index] += 1;
        }

        for(int i = 0; i< t.length(); i++){
            char c = t.charAt(i);
            int index = c - 97;
            res2[index] += 1;
        }

        for(int i = 0; i< 26; i++){
            if(res1[i] != res2[i]){
                return false;
            }
        }
        return true;
    }
///
public boolean isAnagram(String s, String t) {
        if(s == null || t == null || s.length() != t.length()) return false;
        int[] count = new int[26];
        int len = t.length();
        for(int i = 0; i < len; i++) {
            count[t.charAt(i) - 'a']++;
        }
        for(int i = 0; i < len; i++) {
            char c = s.charAt(i);
            if(count[c - 'a'] > 0) {
                count[c - 'a']--;
            } else {
                return false;
            }
        }
        return true;
    }
///
public boolean isAnagram(String s, String t) {
    char[] sChar = s.toCharArray();
    char[] tChar = t.toCharArray();
    Arrays.sort(sChar);
    Arrays.sort(tChar);
    return Arrays.equals(sChar, tChar);
}
///
public boolean isAnagram(String s, String t) {
    if(s.length() != t.length()){
        return false;
    }
    int []count = new int[26];
    for(int i = 0; i < s.length(); i++){
        count[s.charAt(i) - 'a']++;
        count[t.charAt(i) - 'a']--;
    }
    for(int i = 0; i < 26; i++){
        if(count[i] != 0){
            return false;
        }
    }
    return true;
}

