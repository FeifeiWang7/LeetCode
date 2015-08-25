public String addBinary(String a, String b) {
        StringBuilder res = new StringBuilder(Math.max(a.length(), b.length()) +1 );
        int carry = 0, sum = 0;
        int i = a.length() - 1, j = b.length() - 1;
        for(; i >= 0||j >= 0; i--, j--){
            sum = (i>= 0 ? (a.charAt(i) - '0') : 0) + (j >= 0? (b.charAt(j) - '0'): 0) + carry;
            if(sum >= 2 ){
                res.insert(0,sum-2);
                carry = 1;
            }
            else {
                res.insert(0,sum);
                carry = 0;
            }
        }
        if(carry != 0) res.insert(0,1);
        return res.toString();
    }
