class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for (int i=0;i<9;i++){
            for (int j=0;j<9;j++){
                if (board[i][j]=='.'){
                    continue;
                }
                for (int k=0;k<9;k++){
                    if (j<k&&board[i][j]==board[i][k]){
                        return false;
                    }
                    if (i<k&&board[i][j]==board[k][j]){
                        return false;
                    }
                    if (board[i][j]==board[i-i%3+k/3][j-j%3+k%3]){
                        if (i-i%3+k/3!=i||j-j%3+k%3!=j){
                            return false;
                        }
                    }
                }
            }
        }
        return true;
    }
};
