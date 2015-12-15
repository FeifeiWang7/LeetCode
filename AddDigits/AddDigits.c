int addDigits(int num) {
if (num == 0) return 0;
 int result = num %9;
 if(result == 0) return 9;
 else return result;
}
