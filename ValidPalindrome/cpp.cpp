Move two pointers (start & end) towards the middle, skip non alphanumeric characters, if they are not equal to each other, return false;

class Solution {
public:
    bool isPalindrome(string s) {
        int start = 0, end = s.size()-1;
        while(start<end)
        {
            if(!isalnum(s[start])) ++start; // skip non alphanumerical characters
            else if(!isalnum(s[end])) --end;
            else if(tolower(s[start++]) != tolower(s[end--])) return false; // return false when nonequal is found
        }
        return true;
    }
};

/////
The suggested solution to this problem has given a clear idea. The tricky part of this problem is to handle all the edge cases carefully and write a clean code.

The following code should be self-explanatory. Note that the use of toupper avoids some messy if-else statements.

class Solution {
public:
    bool isPalindrome(string s) {
        int l = 0, r = s.length() - 1; 
        while (l < r) {
            while (l < r && !isalnum(s[l])) l++;
            while (r > l && !isalnum(s[r])) r--; 
            if (toupper(s[l++]) != toupper(s[r--]))
                return false;
        }
        return true; 
    }
};
