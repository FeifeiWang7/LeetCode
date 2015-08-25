public class Solution {
        public String addBinary(String a, String b) {
            StringBuilder sb = new StringBuilder();
            int i = a.length()-1, j = b.length()-1;
            int carry = 0;
            while (i >= 0 || j >= 0 || carry > 0) {
                int sum = carry + 
                      (i < 0 ? 0 : a.charAt(i--)-'0') + 
                      (j < 0 ? 0 : b.charAt(j--)-'0');
                sb.insert(0, (char)(sum % 2 + '0'));
                carry = sum / 2;
            }
            return sb.toString();
        }
    }
