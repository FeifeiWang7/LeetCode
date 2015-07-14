public class Solution {
    public boolean isValidSudoku(char[][] board) {
        if(board == null ||board.length != 9 || board[0].length != 9) return false;
        Set<Character> rowSet = new HashSet<Character>();
        Set<Character> colSet = new HashSet<Character>();
        for(int i = 0;i< 9;i++){
            for(int j = 0;j < 9;j++){
                // 验证每一行是否满足数独条件
                if(board[i][j] != '.'){
                    if(!rowSet.add(board[i][j])){
                        return false;
                    }
                }
                //验证每一列是否满足数独条件
                if(board[j][i] !='.'){
                    if(!colSet.add(board[j][i])){
                      return false;
                    }
                }
            }
            rowSet.clear();
            colSet.clear();
        }
        rowSet.clear();
        //验证每个9宫格是否满足数独条件
        for(int i = 0;i< 3;i++){
            for(int j = 0;j<3;j++){
                for(int m = 3*i; m < (3 +3*i); m++){
                    for(int n = 3*j; n < (3 + 3*j); n++){
                        if(board[m][n] != '.'){
                            if(!rowSet.add(board[m][n])){
                                return false;
                            }
                        }
                    } 
                }
                rowSet.clear();
            }
        }
        return true;
    }
}
