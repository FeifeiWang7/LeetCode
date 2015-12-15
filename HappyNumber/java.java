class Solution {
public:
    bool isHappy(int n){
        int low=n,fast=n;
        while(1)
        {
            int temp=0;
            while(low)
            {
                int l=low%10;
                temp+=l*l;
                low/=10;
            }
            low=temp;
            temp=0;
            while(fast)
            {
                int f=fast%10;
                temp+=f*f;
                fast/=10;
            }
            fast=temp;
            temp=0;
            while(fast)
            {
                int f=fast%10;
                temp+=f*f;
                fast/=10;
            }
            fast=temp;
            if(low==1 || fast==1) return true;
            if(fast==low) return false;
        }
    }
};
/////
public boolean isHappy(int n) {
        int result = 0;
        while (n > 9) {
            result += Math.pow(n % 10, 2);
            n = n / 10;
        }
        result += Math.pow(n, 2);
        if (result > 9) {return isHappy(result);}
        if (result == 1) {
            return true;
        } else {
            return false;
        }
}
/////
public class Solution {

public boolean isHappy(int n) {

    boolean isHappyNum = false;
    if(n<0) return isHappyNum;

    List<Integer> contained = new ArrayList<Integer>();

    int sum = n;

    while(sum!=-1){
        sum = calculateHappyNum(sum,contained);
        if(sum==1){
            isHappyNum = true;
            break;
        }
    }

    return isHappyNum;

}


public int calculateHappyNum(int sum,List<Integer> contained){

    if(sum==-1)return -1;

    if(sum==1)return 1;

    int temp = 0;

    while(sum>=1){
        int digit = sum%10;
        temp+= digit * digit;
        sum-= digit;
        sum/=10;
    }

    if(temp==1){
        return 1;
    }

    if(contained.contains(temp)){
        return -1;
    }else{
        contained.add(temp);
        return temp;
    }

}
}
/////
Set<Integer> set=new HashSet<Integer>();
public boolean isHappy(int n){
    if(n==1)return true;
    if(squre(n)==1)return true;
    return false;
}
public int squre(int n){
    int sum=0,i=0;
    if (!set.add(n))return -1;
    if(n<4)return n;
    while (n/10!=0){
        i=n%10;
        sum+=i*i;
        n=n/10;
    }
    sum+=n*n;
   return squre(sum);
}
/////
The idea is to use one hash set to record sum of every digit square of every number occurred. Once the current sum cannot be added to set, return false; once the current sum equals 1, return true;

public boolean isHappy(int n) {
    Set<Integer> inLoop = new HashSet<Integer>();
    int squareSum,remain;
    while (inLoop.add(n)) {
        squareSum = 0;
        while (n > 0) {
            remain = n%10;
            squareSum += remain*remain;
            n /= 10;
        }
        if (squareSum == 1)
            return true;
        else
            n = squareSum;

    }
    return false;

}
////
public class Solution {
    public boolean isHappy(int n) {

        String num = Integer.toString(n);
        int sum = 0;
        HashMap<HashMap<Character, Integer>, Integer > map = new HashMap< HashMap<Character, Integer>, Integer>();

        while(sum != 1){
            HashMap<Character, Integer> map2 = new HashMap<Character, Integer>();
            sum = 0; // every summation needs to clear sum;
            for(char a: num.toCharArray()){
            map2.put(a, map2.getOrDefault(a, 0) + 1);
            sum += Character.getNumericValue(a)*Character.getNumericValue(a);
        }   

            if(!map.containsKey(map2)){
                map.put(map2, map.getOrDefault(map2, 0) + 1 );
            }else{
                return false;
            }

            num = Integer.toString(sum);
        }

        return true;

    }
}
/////
class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> loop;
        /* use the set to record whether there is a infinite loop:
       the values have reach before has reached again*/
        if(n == 1) return 1;

        while(1){
            int sum = 0;
            while(n){
                /* sum all the digits in n */
                int temp = n % 10;
                n /= 10;
                sum += temp * temp;
            }
            if(sum == 1) return 1;
            /* the succeed condition */
            if(loop.find(sum) != loop.end()) return 0;
            /* the set indicates that there is a repetition */

            loop.insert(sum); // do not forget to insert into the set

            n = sum;
        }
    }
};
////
public boolean isHappy2(int n) {
    if(n == 1) return true;//1 is included in happy number loop
    if(n == 4) return false;//4 is included in unhappy number loop

    int sum = 0;
    while(n > 0){
        sum += (int) Math.pow(n%10, 2);
        n /= 10;
    }
    return isHappy(sum);
}
///
public class Solution {

int[] arr = new int[10000];
int count = -1;

public boolean isHappy(int n) {

    int next = 0;

    while(n!=1){

        while(n!=0){
            next = next + (n%10)*(n%10);
            n=n/10;
        }

        if(isInArr(next, arr, count))
            return false;

        arr[++count]=next;
        n = next;
        next=0;

    }

    return true;
}


public boolean isInArr(int n , int[] a, int count){

    for(int i=0; i<=count; i++)
        if(a[i]==n)
            return true;

    return false;
}
}
////
public class Solution {
    public boolean isHappy(int n) {
        /* Base cases */

        // A negative or zero value
        // is not a valid input
        // Return grumpily
        if (n < 1) {
            return false;
        }

        // You have entered
        // the chain of despair.
        // You will never be 
        // happy again
        if (n == 4
        ||  n == 16
        ||  n == 20
        ||  n == 37
        ||  n == 42
        ||  n == 58
        ||  n == 89
        ||  n == 145) {
            return false;
        }
        // Check Wikipedia for 
        // the explanation of despairing numbers
        // You don't need to remember all of them.
        // Just remembering one of them will do

        // You have achieved bliss
        if (n == 1) {
            return true;
        }

        // If none of the above
        // Keep searching
        return isHappy(getSumOfSquares(n));
    }

    private int getSumOfSquares(int num) {
        int sum = 0;
        while (num > 0) {
            int digit = num % 10;
            sum += digit * digit;
            num /= 10;
        }

        return sum;
    }
}
///
My solution using hashSet.

public class Solution {
    public boolean isHappy(int n) {

        // Initialize a hashset.
        HashSet<Integer> hashSet = new HashSet<Integer>();

        // Loop the calculation until we find happy number of we learn that it loops
        int temp = n;
        while (true) {
            temp = squareDigits(temp);
            if (hashSet.contains(temp)) return false;
            else if (temp == 1) return true;
            else hashSet.add(temp);
        }
    }

    private int squareDigits(int n) {

        // Initialize useful variables (num array and length)
        String str = Integer.toString(n);
        int length = str.length();

        // Initialize sum
        int sum = 0;
        int temp = 0;

        // Convert to a list of digits, square it and add to sum
        for (int i = 0; i < length; i++) {
            temp = Integer.parseInt("" + str.charAt(i));
            temp = temp * temp;
            sum += temp;
        }

        // Return sum
        return sum;
    }
}
////
public class Solution {

ArrayList<Integer> array = new ArrayList<Integer>();

public boolean isHappy(int n) {
    if(n == 1) {
        return true;
    }
    if(array.contains(n)) {
        return false;
    }
    array.add(n);
    int sum = 0;
    int elem;
    while(n != 0) {
        elem = n % 10;
        n = n / 10;
        sum += elem * elem;
    }
    return isHappy(sum);
}
}

////
public boolean isHappy(int n) {
    HashSet<Integer> hash = new HashSet<Integer>();
    if(n <= 0) return false;
    while(n < Integer.MAX_VALUE){
        int i = 0;
        int j = 10;
        if(n == 1) return true;
        if(hash.contains(n)) return false;
        else hash.add(n);
        while(n != 0){
            i += (n % j) * (n % j);
            n = (n - n % j) / 10;
        }
        n = i;
    }
    return false;
}
////
public class Solution {
    public boolean isHappy(int n) {
        Set<Integer> track = new HashSet<>();
        return happy(n, track);
    }
    private boolean happy(int n, Set<Integer> track){
        if(n == 1) return true;
        if(track.contains(n)) return false;
        track.add(n);
        char[] nums = Integer.toString(n).toCharArray();
        int sum = 0;
        int num = -1;
        for(int i=0; i<nums.length;i++){
            num = Character.getNumericValue(nums[i]);
            sum += num*num;
        }
        return happy(sum, track);
    }
}
/////
public boolean isHappy(int n) {
        if(n <= 0) return false;
        Set<Integer> set = new HashSet<Integer>();
        set.add(1);
        while(set.add(n)) {
            int next = 0;
            while(n != 0) {
                int i = n % 10;
                next += i * i;
                n = n / 10;
            }
            n = next;
        }
        return n == 1;
    }
/////////
public class Solution {
    public boolean isHappy(int n) {
        HashSet hs= new HashSet();
        while(n!=1){
        if(!hs.add(n)){
            return false;
        }
        String number=Integer.toString(n);
        int newNumber=0;
        for(int i=0;i<number.length();i++){
            newNumber+=(int) Math.pow(number.charAt(i)-'0', 2);
        }
        n=newNumber;
    }
    return true;
}
}
/////
public boolean isHappy(int n) {
        int nn = n,temp = 0;
        Set<Integer> set = new HashSet<Integer>();
        set.add(n);
        if(n == 1)
            return true;
        while(temp!=1) {
            temp = 0;
            while (nn != 0) {
                temp += Math.pow(nn % 10, 2);
                nn = nn / 10;
            }
            if(set.contains(temp))
                return false;
            set.add(temp);
            nn = temp;
        }
        return true;
    }
