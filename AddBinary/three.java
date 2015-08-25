public String addBinary(String a, String b){
    int carry = 0;
    String result = "";
    for(int i=a.length()-1, j=b.length()-1; i>=0||j>=0; i--,j--) {
        int ai= i>=0? a.charAt(i)-'0':0;
        int bj= j>=0? b.charAt(j)-'0':0;
        int val = (ai + bj + carry) %2;
        carry = (ai + bj + carry)/2;
        result = result + val;
    }

    if(carry == 1) {
        result += 1;
    }

    return new StringBuilder(result).reverse().toString();
}
