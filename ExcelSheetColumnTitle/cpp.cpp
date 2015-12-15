///
class Solution {
public:
    string convertToTitle(int n) {
        return (n>26?convertToTitle((n-1)/26):"")+(char)((n-1)%26+'A');
    }
};
///////
class Solution {
public:
string convertToTitle(int n) {
    //return solution1(n);    //recursive
    return solution2(n);    //iterative
}
private:
string solution1(int n){
    string s;
    if(!n) return s;
    int rem = (n - 1) % 26 + 1;
    s = solution1((n - rem) / 26) + (char)(rem + 64);
    return s;
}
string solution2(int n){
    string s;
    if(!n) return s;
    int rem;
    while(n){
        rem = (n - 1) % 26 + 1;
        s.insert(s.begin(), (char)(rem + 64));
        n = (n - rem) / 26;
    }
    return s;
}
};

//////////////////////////
string convertToTitle(int n) {
    string res;
    while(n>=1){
        res=(char)('A'+(n-1)%26)+res;
        n=(n-1)/26;
    }
    return res;
}
/////
class Solution {
public:
    string convertToTitle(int n) {
        string result;
        while (n) {
            result.push_back('A' + (n - 1) % 26), n = (n - 1) / 26;    
        }
        reverse(result.begin(), result.end());
        return result;
    }
};
