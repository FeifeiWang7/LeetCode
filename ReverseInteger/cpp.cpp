//
class Solution {
public:
    int reverse(int x) {
        int re;
        string s = to_string(x);
        auto l = s.begin();
        auto r = prev(s.end());
        if(*l=='-')l++;
        while(l<r){
            char temp = *l;
            *l = *r;
            *r = temp;
            l++;
            r--;
        }
        try{
          re =  stoi(s);
        }catch(exception e){
            re = 0;
        }
        return re;
    }
};
///
class Solution {
 public:
    int reverse(int x) {
        long result = 0;           // Final result
        long op = x < 0 ? -1 : 1;  // Get the operator

        long tmp = abs((long)x);  // Avoid too many type conversions and work with positive number
        while (tmp) {             // When tmp is zero, stops
            result += tmp % 10;   // Get the last number
            result *= 10;
            tmp /= 10;
        }
        result /= 10;  // Remove the last zero

        return result > (long)INT_MAX ? 0 : result * op;
    }
};
///
class Solution {
public:
    int reverse(int x) {
        if(x<10&&x>-10)
         return x;
        int abs_x=x,flag=1,temp=0,result=0,previous_result=0;
        if(x<0)
         {
             abs_x=-x;
             flag=-1;
         }
         while(abs_x!=0)
         {
             temp=abs_x%10;
             previous_result=result;
             result=result*10+temp;
             abs_x/=10;
         }
        if(result/10!=previous_result)
            return 0;
        else
            return flag*result;
    }
};
