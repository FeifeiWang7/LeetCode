class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int len = nums.size();
        int d = gcd(len, k=k%len);
        int pos, next_pos;
        int tmp, tmp_next;

        for (int i = 0; i < d; ++i) {
            pos = i;
            tmp = nums[pos];
            do {
                next_pos = (pos+k) % len;
                tmp_next = nums[next_pos];
                nums[next_pos] = tmp;

                pos = next_pos;
                tmp = tmp_next;
            } while (pos != i);
        }
    }

    int gcd(int a, int b)
    {
        int t;

        while (b != 0) {
            t = a%b;
            a = b;
            b = t;
        }
        return a;
    }
};
