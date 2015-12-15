public String convertToTitle(int n) {
    return n==0?"":convertToTitle((n-1)/26)+String.valueOf((char)((n-1)%26+65));
}

//////

public String convertToTitle(int n) {

    StringBuilder s = new StringBuilder();
    while (n > 0){
        s.insert(0, (n % 26 == 0)? 'Z' : (char)(64 + n % 26));
        n = (n % 26 == 0)?  n / 26 - 1 : n / 26;
    }
    return s.toString();
}
