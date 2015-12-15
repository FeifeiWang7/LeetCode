public class Solution {
public int titleToNumber(String s) {
    return s.length()==0?0:titleToNumber(s.substring(0,s.length()-1))*26+(s.charAt(s.length()-1)-'A'+1);
}
}

/////
public class Solution {
    public int titleToNumber(String s) {
        int l = s.length();
        int count = 0;
        for(int i = 0; i<l;i++ ){
            count = count*26  +s.charAt(i)-'A' + 1;
        }
        return count;
    }
}
