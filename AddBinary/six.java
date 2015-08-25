public String addBinary(String a, String b) {
    int carry = 0;
    int l1 = a.length() - 1;
    int l2 = b.length() - 1;
    StringBuilder sb = new StringBuilder();
    while (l1 >= 0 || l2 >= 0 || carry != 0) {
        int tmp = (l1 >= 0 ?  Integer.parseInt(a.charAt(l1--)+"") : 0) + (l2 >= 0 ?  Integer.parseInt(b.charAt(l2--)+"") : 0) + carry;
        carry = tmp >= 2 ? 1 : 0;
        sb.insert(0, tmp % 2 == 0 ? '0' : '1');
    }
    if (sb.charAt(0) == '0') {
        return "0";
    }
    return sb.toString();
}
