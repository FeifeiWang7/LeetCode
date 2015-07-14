typedef unsigned int mytype;
class Solution {
public:
    int strStr(string haystack, string needle) {
        if(needle.length() == 0) return 0;
        mytype hash_needle = 0;
        for(int i=0; i<needle.length(); i++) {
            hash_needle = hash_needle * 97 + needle[i];
        }


        mytype factor = 1;
        mytype hash_haystack = 0;
        for(int i=0; i<needle.length() && i<haystack.length(); i++) {
            hash_haystack = hash_haystack * 97 + haystack[i];
            //factor = factor * 13;
        }
        for(int i=0; i<needle.length() -1; i++) {
            factor *= 97;
        }


        if(hash_haystack == hash_needle) return 0;
        for(int i=needle.length(); i<haystack.length(); i++) {
            hash_haystack = (hash_haystack - factor * haystack[i - needle.length()]) * 97 + haystack[i];

            if(hash_haystack == hash_needle && haystack.substr(i - needle.length() + 1, needle.length()) == needle) {
                return i - needle.length() + 1;
            }
        }
        return -1;
    }
};
