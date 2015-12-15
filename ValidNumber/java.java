public boolean isNumber(String s) {
    String ss=s.trim();
    int state=1; boolean canSymbolAppear=true; boolean valid=false; boolean canPointAppear=true;
    for(int i=0;i<ss.length();i++){
        char c=ss.charAt(i);
        if((c=='+' || c=='-') && canSymbolAppear ) {
            canSymbolAppear=false;
            continue;
        }
        switch(state){
         case 1:
             if(isDigit(c)) {
                 valid=true;
                 canSymbolAppear=false;
                 continue;
             }
             else if(isPoint(c) && canPointAppear) {
                 canPointAppear=false;
                 canSymbolAppear=false;
                 continue;
             }
             else if(isE(c) && valid){
                 state=2;
                 canSymbolAppear=true;
                 valid=false;
                 continue;
             }
             else return false;

        case 2:
             if(isDigit(c)) {
                 valid=true;
                 canSymbolAppear=false;
                 continue;
             }
             else return false;
        default: return false;
        }

    }
    if(valid) return true;
    else return false;

}
public boolean isDigit(char s){
    return (s>='0' && s<='9');
}
public boolean isPoint(char s){
    return s=='.';
}
public boolean isE(char s){
    return (s=='e' || s=='E');
}
////////
It first checks whether it contains an 'e': if yes, then left side should be a float or an integer and right side should be an integer. If no 'e' was found then whole string should be a float or an integer. And so on...

public boolean isNumber(String str) {
    if (str == null) {
        return false;
    }
    str = str.trim();
    if (str.isEmpty()) {
        return false;
    }
    int index;
    if ((index=str.indexOf('e')) != -1) {
        return isFloatOrInteger(str, 0, index-1) && 
               isInteger(str, index+1, str.length()-1);
    } else {
        return isFloatOrInteger(str, 0, str.length()-1);
    }
}

private boolean isInteger(String str, int from, int to) {
    if (from > to) {
        return false;
    }
    if (str.startsWith("+", from) || str.startsWith("-", from)) {
        return isUnsignedInteger(str, from+1, to);
    } else {
        return isUnsignedInteger(str, from, to);
    }
}

private boolean isUnsignedInteger(String str, int from, int to) {
    if (from > to) {
        return false;
    }
    for (int i=from; i<=to; i++) {
        if (str.charAt(i) < '0' || str.charAt(i) > '9') {
            return false;
        }
    }
    return true;
}

private boolean isFloatOrInteger(String str, int from, int to) {
    if (from > to) {
        return false;
    }
    if (str.startsWith("+", from) || str.startsWith("-", from)) {
        return isUnsignedFloatOrInteger(str, from+1, to);    
    } else {
        return isUnsignedFloatOrInteger(str, from, to);    
    }
}

private boolean isUnsignedFloatOrInteger(String str, int from, int to) {
    if (from > to) {
        return false;
    }
    int index = str.indexOf('.', from);
    if (index > -1 && index <= to) {
        return (from != index || to != index) && 
               (isUnsignedInteger(str, from, index-1) || from == index) && 
               (isUnsignedInteger(str, index+1, to) || index == to);
    } else {
        return isUnsignedInteger(str, from, to);
    }
}
/////////
public boolean isNumber(String s) {
      s = s.trim();
      if (s.length() == 0 || s.equals("e")  || s.equals(".")) return false;
      return isFloating(s) || isRegular(s);
   }

   // parses non-floating point literals
   private boolean isRegular(String s) {
      return (s.matches("[+-]?[0-9]+[.]?[0-9]*") || s.matches("[+-]?[0-9]*[.]?[0-9]+"));
   }

    // parses floating point literals as defined here: http://en.cppreference.com/w/cpp/language/floating_literal
   private boolean isFloating(String s) {
      //first one enforces an number after ., the second one enforces a number before .
      // we want to make sure there's at least one number present.
      return (s.matches("[+-]?[0-9]*[.]?[0-9]+[eE][-+]?[0-9]+[f]?") || s.matches("[+-]?[0-9]+[.]?[0-9]*[eE][-+]?[0-9]+[f]?"));
   }
/////
The method is splitting the input by 'e', and the 1st part can be any kind of number and the 2nd part (if exists) must be an integer.

Here it is:

public class Solution {

public boolean valid(String s, boolean integer) {
    int i = 0, start = 0;
    if (s.length() < 1) return false;
    if (s.charAt(0) == '-' || s.charAt(0) == '+') i = start = 1;
    if (start == s.length()) return false;
    char c;
    boolean flag = false, hasnumber = false;;
    for (; i < s.length(); ++i) {
        c = s.charAt(i);
        if (c == '.') {
            if (!flag && !integer) flag = true;
            else return false;
            continue;
        }
        if (c < '0' || c > '9') return false;
        hasnumber = true;
    }
    return hasnumber;
}

public boolean isNumber(String s) {
    s = s.trim();
    if (s.length() < 1 || s.charAt(s.length()-1) == 'e') return false;
    String[] sp = s.split("e");
    if (sp.length > 2 || sp.length < 1) return false;
    if (!valid(sp[0], false)) return false;
    if (sp.length == 1 || (sp.length == 2 && valid(sp[1], true))) return true;
    return false;
}

public static void main(String[] args) {
    System.out.println((new Solution()).isNumber(""));
}
}

///////
public boolean isNumber(String s) {
    s = s.trim();

    boolean pointSeen = false;
    boolean eSeen = false;
    boolean numberSeen = false;
    boolean numberAfterE = true;
    for(int i=0; i<s.length(); i++) {
        if('0' <= s.charAt(i) && s.charAt(i) <= '9') {
            numberSeen = true;
            numberAfterE = true;
        } else if(s.charAt(i) == '.') {
            if(eSeen || pointSeen) {
                return false;
            }
            pointSeen = true;
        } else if(s.charAt(i) == 'e') {
            if(eSeen || !numberSeen) {
                return false;
            }
            numberAfterE = false;
            eSeen = true;
        } else if(s.charAt(i) == '-' || s.charAt(i) == '+') {
            if(i != 0 && s.charAt(i-1) != 'e') {
                return false;
            }
        } else {
            return false;
        }
    }

    return numberSeen && numberAfterE;
}
We start with trimming.

If we see [0-9] we reset the number flags.
We can only see . if we didn't see e or ..
We can only see e if we didn't see e but we did see a number. We reset numberAfterE flag.
We can only see + and - in the beginning and after an e
any other character break the validation.
At the and it is only valid if there was at least 1 number and if we did see an e then a number after it as well.

So basically the number should match this regular expression:

[-+]?[0-9]*(.[0-9]+)?(e[-+]?[0-9]+)?
///////
public class Solution {
    public boolean isNumber(String s) {
        if (s == null) return false;

        s = s.trim();
        int n = s.length();

        if (n == 0) return false;

        // flags
        int signCount = 0;
        boolean hasE = false;
        boolean hasNum = false;
        boolean hasPoint = false;

        for (int i = 0; i < n; i++) {
            char c = s.charAt(i);

            // invalid character
            if (!isValid(c)) return false;

            // digit is always fine
            if (c >= '0' && c <= '9') hasNum = true;

            // e or E
            if (c == 'e' || c == 'E') {
                // e cannot appear twice and digits must be in front of it
                if (hasE || !hasNum) return false;
                // e cannot be the last one
                if (i == n - 1) return false;

                hasE = true;
            }

            // decimal place
            if (c == '.') {
                // . cannot appear twice and it cannot appear after e
                if (hasPoint || hasE) return false;
                // if . is the last one, digits must be in front of it, e.g. "7."
                if (i == n - 1 && !hasNum) return false;

                hasPoint = true;
            }

            // signs
            if (c == '+' || c == '-') {
                // no more than 2 signs
                if (signCount == 2) return false;
                // sign cannot be the last one
                if (i == n - 1) return false;
                // sign can appear in the middle only when e appears in front
                if (i > 0 && !hasE) return false;

                signCount++;
            }
        }

        return true;
    }

    boolean isValid(char c) {
        return c == '.' || c == '+' || c == '-' || c == 'e' || c == 'E' || c >= '0' && c <= '9';
    }
}
