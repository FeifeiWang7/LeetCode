public String addBinary(String a, String b) {
    int lena = a.length();
    int lenb = b.length();
    int i =0, carry = 0;
    String res = "";
    while(i<lena || i<lenb || carry!=0){
        int x = (i<lena) ? Character.getNumericValue(a.charAt(lena - 1 - i)) : 0;
        int y = (i<lenb) ? Character.getNumericValue(b.charAt(lenb - 1 - i)) : 0;
        res = (x + y + carry)%2 + res;
        carry = (x + y + carry)/2;
        i++;
    }
    return res;
}
