public class Solution {
    public String addBinary(String a, String b) {

        StringBuilder sa = new StringBuilder(a);
        sa.reverse();
        StringBuilder sb = new StringBuilder(b);
        sb.reverse();
        int maxLen = Math.max(a.length(), b.length());
        StringBuilder ret = new StringBuilder();
        int carry = 0;

        for(int i = 0; i < maxLen; i++){
            char ca = (i < sa.length()) ? sa.charAt(i) : '0';
            char cb = (i < sb.length()) ? sb.charAt(i) : '0';
            if(ca == cb){
                ret.append(carry);
                carry = (ca == '0') ? 0 : 1;
            }else{
                ret.append(1 - carry);
                carry = (carry == 1) ? 1 : 0;
            }
        }

        ret = (carry == 0) ? ret : ret.append(1);
        ret.reverse();
        return ret.toString();

    }
}
