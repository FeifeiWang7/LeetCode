class Solution:
    # @param {character[][]} board
    # @return {boolean}
    def isValidSudoku(self, board):
        if not board or not board[0]:
            return True

        # map 1 - 9 to the first 9 primes
        PRIMES = [1, 2, 3, 5, 7, 11, 13, 17, 19, 23]

        rows = [1] * 9
        cols = [1] * 9
        square = [1] * 9

        for i in range(0, 9):
            for j in range(0, 9):
                if board[i][j] == '.':
                    continue

                d = PRIMES[int(board[i][j])]
                if rows[i] % d == 0 or cols[j] % d == 0 or square[i - i % 3 + j / 3] % d == 0:
                    return False

                rows[i] *= d
                cols[j] *= d
                square[i - i % 3 + j / 3] *= d

        return True
