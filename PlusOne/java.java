public int[] plusOne(int[] digits) {
    int pointer = digits.length - 1;
    while (pointer >= 0 && digits[pointer] == 9) pointer--;
    if (pointer == -1) {
        int[] ret = new int[digits.length + 1];
        ret[0] = 1;
        return ret;
    }
    digits[pointer] = digits[pointer] + 1;
    pointer++;
    if (pointer < digits.length) Arrays.fill(digits, pointer, digits.length, 0);
    return digits;
}
