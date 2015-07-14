class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        array<bitset<9>, 9> row, col;
        array<array<bitset<9>, 3>, 3> box;

        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                if (board[i][j] != '.') {
                    int n = board[i][j] - '0' - 1;
                    if (row[i].test(n) || col[j].test(n) || box[i / 3][j / 3].test(n)) {
                        return false;
                    }
                    row[i].set(n), col[j].set(n), box[i / 3][j / 3].set(n);
                }
            }
        }
        return true;
    }
};
