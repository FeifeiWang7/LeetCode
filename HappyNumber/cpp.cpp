bool isHappy( int n ) {

        if( n == 1 ) return 1;

        unordered_map< int, bool > m;

        int i, temp;

        m[n] = 1;

        for( ;; ) {
            temp = 0;
            for( ; n; n /= 10 ) {
                i = n % 10;
                temp += i * i;
            }
            if ( temp == 1 ) return 1;
            if( m[temp]++ ) return 0;
            n = temp;
        }
    }
/////
class Solution {
public:
    bool isHappy(int n) {
        map<int, bool> m;
        while(1){
            if(m.find(n)!=m.end()) return false;
            int tmpbase = n;
            int tmp = n % 10;
            int sum = 0;
            sum += tmp * tmp;
            tmpbase -= tmp;
            tmpbase/=10;
            while(1){
                if(tmpbase==0) break;
                tmp = tmpbase % 10;
                sum += tmp * tmp;
                tmpbase -= tmp;
                tmpbase/=10;
            }

            if(sum == 1) return true;
            m[n] = false;
            n = sum;
        }
    }
};
/////
class Solution {
public:
    vector<int> solutions;
    bool isRepeat(int n, vector<int> solutions){
        for(int i=0;i!=solutions.size();i++){
            if(solutions[i]==n)
                return true;
        }
        return false;
    }

    bool isHappy(int n) {
        if(n==1)
            return true;
        else if(isRepeat(n,solutions))
            return false;
        else{
            solutions.push_back(n);
            int nn=0;
            while(n!=0){
                nn+= (n%10)*(n%10);
                n = n/10;
            }
            return isHappy(nn);
        }

    }
};
////
class Solution{

public:
bool isHappy(int n) {
    vector<int>v;
    n=Next(n);
    v.push_back(n);
    while(n!=1&&n!=4){
        n=Next(n);
        v.push_back(n);
    }
    if(find(v.begin(),v.end(),1) != v.end())
        return true;
    return false;
}
private:
int Next(int n){
    int res=0;
    while(n){
        res += pow(n%10,2);
        n /= 10;
    }
    return res;
}
};
/////
class Solution {
public:
    bool isHappy(int n) {
        unordered_map<int, int> M;
        M[0] = 0, M[1] = 1, M[2] = 4, M[3] = 9, M[4] = 16, M[5] = 25,\
        M[6] = 36, M[7] = 49, M[8] = 64, M[9] = 81;
        int temp, mark = 0;   //temp is next n, mark is for detect circle 
        while(n){
            temp = 0;
            if(n == 1) return true;
            if(n < 10){
                if(mark == n)
                   return false;
                mark = n;
            }
            //calc next n
            while(n){
                temp += (n%10)*(n%10); // 4 ms
               // temp += M[n%10];       // 8 ms
                n /= 10;
            }
            n = temp;
        }
    }
};
////
public boolean isHappy(int n) {
  Set<Integer> set = new HashSet<Integer>();

  while (n > 1) {
    int m = 0;

    while (n > 0) {
      int d = n % 10;
      m += d * d;
      n /= 10;
    }

    if (set.contains(m))
      return false;

    set.add(m);

    n = m;
  }

  return true;
}
