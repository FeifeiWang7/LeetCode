class Solution {
public:
    int strStr(char *haystack, char *needle) {
        int i = 0;
        while (true) {
            char *p1 = haystack;
            char *p2 = needle;
            for (; *p1 == *p2 && *p1 != 0 && *p2 != 0; p1++, p2++) {}
            if (*p2 == 0) return i;
            if (*p1 == 0) return -1;
            haystack++;
            i++;
        }
        return -1;
    }
};
