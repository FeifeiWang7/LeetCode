class Solution:
        # @param board, a 9x9 2D array
        # @return a boolean
        def isValidSudoku(self, board):
            if board == None:
                return False

            _row= [0 for i in range(9)]
            _col= [0 for i in range(9)]
            _blo= [0 for i in range(9)]

            for i in range(len(board)):
                for j in range(len(board[0])):

                    if board[i][j] != ".":
                        _tem = 1<< (int)(board[i][j])
                        _ind = (i/3) * 3 + j/3
                        if _tem & _row[j] or _tem & _col[i] or _tem & _blo[_ind]:
                            return False
                        else:
                            _col[i] = _col[i] | _tem
                            _row[j] = _row[j] | _tem
                            _blo[_ind] = _blo[_ind] | _tem
            return True
