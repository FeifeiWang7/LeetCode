class Solution {
public:
    string countAndSay(int n) {
        string result = "1";
        for (int i = 1; i < n; ++i) {
            stringstream next;
            char u;
            int count = 0;
            for (const char& c : result) {
                if (count == 0) {
                    u = c, count = 1;
                } else if (u != c) {
                    next << count << u;
                    u = c, count = 1;
                } else {
                    count++;
                }
            }
            if (count != 0) { next << count << u; }
            result = next.str();
        }
        return result;
    }
};
