class Solution {
public:
    bool isValidSudoku(vector<vector<char> > &board) {
        char existNum[10][10]={0};
        int i,j;

        for(i=0; i<9; i++)
        {
            for(j=0; j<9; j++)
            {
                if(board[i][j]!='.')
                {
                    if(existNum[i][board[i][j] - '0'] & 0x1)return false; // check if the i-row already has such number, LSB
                    if(existNum[j][board[i][j] - '0'] & 0x2) return false; // check if the j-col already has such number, 2-LSB
                    if(existNum[(i/3) *3 + j/3][board[i][j] - '0'] & 0x4) return false; // check if the k-subblock already has such number, 3-LSB
                    existNum[i][board[i][j] - '0'] ^=0x1;
                    existNum[j][board[i][j] - '0'] ^=0x2;
                    existNum[(i/3) *3 + j/3][board[i][j] - '0'] ^=0x4;
                }

            }
        }

        return true;
    }
};
