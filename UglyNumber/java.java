public boolean isUgly(int num) {
        if(num <= 0){
            return false;
        }
        //remove 2's.
        num >>>=  Integer.numberOfTrailingZeros(num);

        //remove 3's
        while(num % 3 == 0){
            num = num/3;
        }
        //remove 5's
        while(num %5 == 0){
            num = num /5;
        }
        return num == 1;
    }
/////
public boolean isUgly(int num) {
    if (num <= 0) {return false;}
    if (num == 1) {return true;}
    if (num % 2 == 0) {
        return isUgly(num/2);
    }
    if (num % 3 == 0) {
        return isUgly(num/3);
    }
    if (num % 5 == 0) {
        return isUgly(num/5);
    }
    return false;
}
