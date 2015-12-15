public class Solution {
    public boolean isPalindrome(String s) {
        if(s == null) return true;
        for(int i = 0, j = s.length - 1; i < j ; i++,j--){
            while(!isLegal(s.charAt(i)) && i < j)i++;
            while(!isLegal(s.charAt(j)) && i < j)j--;
            int temp = s.charAt(i) - s.charAt(j);
            if(temp != 0 && temp != 32 && temp != -32) return false;
        }
        return true;
    }
    public boolean isLegal(char c){
        return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z' || (c >= '0' && c <= '9'));
    }
}
///
public boolean isPalindrome(String s) {
        s = s.replaceAll("\\W","");
        s = s.toLowerCase();
        if(s==null)   return false;
        for(int i=0,j=s.length()-1;i<j;i++,j--){
            if(s.charAt(i)!=s.charAt(j))    return false;
        }
        return true;
    }

    //without regex
    public boolean isPalindrome(String s) {
        s = s.toLowerCase();
        if(s==null)   return false;
        for(int i=0,j=s.length()-1;i<j;i++,j--){
            while(i<s.length()&&!(Character.isAlphabetic(s.charAt(i))||Character.isDigit(s.charAt(i)))) i++;
            while(j>=0&&!(Character.isAlphabetic(s.charAt(j))||Character.isDigit(s.charAt(j)))) j--;
            if(i<j&&s.charAt(i)!=s.charAt(j))    return false;
        }
        return true;
    }
////
s=s.toLowerCase().replaceAll("[^a-z0-9]", "");
return new StringBuilder(s).reverse().toString().equals(s);
