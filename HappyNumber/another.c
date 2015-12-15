You could refer to wikipedia, search for 'happy number', then you could find that for any unhappy number, they will fall into one specific loop "4->16->37->...->2->4"

int crazy(int num) {
    int sum = 0;
    while (num > 0) {
        int mod = num % 10;
        sum += mod * mod;
        num /= 10;
    }
    return sum;
}

bool isHappy(int n) {
    while (n != 1) {
        n = crazy(n);
        if (n == 4) {
            return false;
        }
    }
    return true;
}

///////
int calculate(int input){
       int tmp, ret = 0;
       while (input > 0){
           tmp = input % 10;
           input /= 10;
           ret += tmp * tmp;
       }
       return ret;
   }

    bool isHappy(int n) {
        int tmp;
        do{
            tmp = calculate(n);
            /**
             ** If n is an unhappy num，the final loop would be
             ** 4 → 16 → 37 → 58 → 89 → 145 → 42 → 20 → 4.
             ** So here we just need to verify whether these number 
             ** will appear in the calculate process 
             **/
            if (tmp == 4 || tmp == 16 || tmp == 37 || tmp == 42 || 
                tmp == 20 || tmp == 58 || tmp == 89 || tmp == 145)
                return false;
            else
                n = tmp;
        } while (tmp != 1);
        return true;
    }
