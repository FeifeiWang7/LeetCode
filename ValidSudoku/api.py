class Solution:
    # @param board, a 9x9 2D array
    # @return a boolean
    def isValidSudoku(self, board):
        # check row
        for row in board:
            if self.isDuplicate(row):
                return False

        # check column
        for i in xrange(0,9):
            if self.isDuplicate([board[j][i] for j in range(0,9)]):
                return False

        # check 3x3
        index = [[0,1,2],[3,4,5],[6,7,8]]
        for x3 in index:
            for y3 in index:
                if self.isDuplicate([board[i][j] for i in x3 for j in y3]):
                    return False

        return True


    def isDuplicate(self, *args):
        l = filter(lambda a: a != '.', args[0])
        return (len(set(l)) - len(l)) != 0
