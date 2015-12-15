public class Solution {
    public boolean isNumber(String s) {
        s = s.trim();
        if (s.length() == 0) return false;          
        if (s.matches("[+-]?(([0-9]*\\.?[0-9]+)|([0-9]+\\.?[0-9]*))([eE][+-]?[0-9]+)?")) return true;
        else return false;
    }
}
