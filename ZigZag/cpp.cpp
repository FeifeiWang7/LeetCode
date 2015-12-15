intermidate character in the slop downward or upward, the downward step is 2 * (numRows - 1 - i), the upward step is 2 *(i)
.

class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1 || s.size() <= numRows) return s; //if zigzag to one line or the string's size is less than numRows, then no replacement is needed
        string res = s;
        size_t res_pos = 0;
        for(size_t i = 0; i < numRows; ++i){
            if (i == 0 || i == numRows - 1){
                for(size_t j = i; j < s.size();){
                    res[res_pos++] = s[j];
                    j += 2 * (numRows - 1);
                }
            } else {
                bool downward = true;
                for(size_t j = i; j < s.size();){
                    res[res_pos++]= s[j];
                    j +=  2 * (downward ?  *(numRows - 1 - i) : i);
                    downward = !downward;
                }
            }
        }
        return res;
    }
};
///
/*n=numRows
Δ=2n-2    1                           2n-1                         4n-3
Δ=        2                     2n-2  2n                    4n-4   4n-2
Δ=        3               2n-3        2n+1              4n-5       .
Δ=        .           .               .               .            .
Δ=        .       n+2                 .           3n               .
Δ=        n-1 n+1                     3n-3    3n-1                 5n-5
Δ=2n-2    n                           3n-2                         5n-4
*/
that's the zigzag pattern the question asked! Be careful with nR=1 && nR=2

my 16ms code in c++:

class Solution {
public:
    string convert(string s, int numRows) {
        string result="";
        if(numRows==1)
            return s;
        int step1,step2;
        int len=s.size();
        for(int i=0;i<numRows;++i){
            step1=(numRows-i-1)*2;
            step2=(i)*2;
            int pos=i;
            if(pos<len)
                result+=s.at(pos);
            while(1){
                pos+=step1;
                if(pos>=len)
                    break;
                if(step1)
                    result+=s.at(pos);
                pos+=step2;
                if(pos>=len)
                    break;
                if(step2)
                    result+=s.at(pos);
            }
        }
        return result;
    }
};
///
The distribution of the elements is period.

P   A   H   N
A P L S I I G
Y   I   R
For example, the following has 4 periods(cycles):

P   | A   | H   | N
A P | L S | I I | G
Y   | I   | R   |
The size of every period is defined as "cycle"

cycle = (2*nRows - 2), except nRows == 1.
In this example, (2*nRows - 2) = 4.

In every period, every row has 2 elements, except the first row and the last row.

Suppose the current row is i, the index of the first element is j:

j = i + cycle*k, k = 0, 1, 2, ...
The index of the second element is secondJ:

secondJ = (j - i) + cycle - i
(j-i) is the start of current period, (j-i) + cycle is the start of next period.

string convert(string s, int nRows) {
        if(nRows <= 1) return s;
        string result = "";
        //the size of a cycle(period)
        int cycle = 2 * nRows - 2;
        for(int i = 0; i < nRows; ++i)
        {
            for(int j = i; j < s.length(); j = j + cycle){
               result = result + s[j];
               int secondJ = (j - i) + cycle - i;
               if(i != 0 && i != nRows-1 && secondJ < s.length())
                   result = result + s[secondJ];
            }
        }
        return result;
    }
/////
class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows<2 || s.size()<=numRows) return s;
        string res(s.size(),0);
        char *p=&res[0];
        for(int i=0, j,k, step=(numRows-1)*2;i<numRows;++i) {
            if(i==0 || i==numRows-1) 
                for(j=i;j<s.size();j+=step) *p++=s[j];
            else
                for(j=i, k=i<<1;j<s.size();k=step-k,j+=k) *p++=s[j];
        }
        return res;
    }
};
///
class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows == 1 || numRows > s.length() ) return s;
        string tmp;
        string result;
        int length = s.length();
        for(int i = 0; i < numRows; ++i){
            if(i == 0 || i == numRows -1){
                for(int j = i; j < length; j = j + 2 * (numRows -1 ) ){
                    result.push_back(s[j]);
                }
                continue;
            }
            int x = 2* (numRows - i -1 );
            for(int j = i; j < length; j = j+2*(numRows - 1) - x){
                result.push_back(s[j]);
                x = 2*(numRows - 1 ) - x;
            }
        }
        return result;
    }
};
