class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& grid) {
        int N = 9;
        int VAL_TO_PRIME[9] = {2, 3, 5, 7, 11, 13, 17, 19, 23};
        int rows[N]; 
        int cols[N]; 
        int boxes[N]; 

        for(int i = 0; i < N; ++i) {
            rows[i] = cols[i] = boxes[i] = 1;
        }

        for(int i = 0; i < N; ++i) {
            for(int j = 0; j < N; ++j) {
                if(grid[i][j] == '.') continue;
                int d = VAL_TO_PRIME[grid[i][j] - 1 - '0'];
                if(rows[i] % d == 0 || cols[j] % d == 0 || boxes[i - i % 3 + j / 3] % d == 0){
                    return false;
                }
                rows[i] *= d;
                cols[j] *= d;
                boxes[i - i % 3 + j / 3] *= d;
            }
        }
        return true;
    }
};
