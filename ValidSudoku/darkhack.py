def isValid(self, lst):
    lst = filter(lambda x: x != '.', lst)
    return len(lst) == len(set(lst))

def isValidSudoku(self, board):
    for x in range(9):
        if not self.isValid(board[x]):
            return False
    for y in range(9):
        if not self.isValid(zip(*board)[y]):
            return False
    point = [(3 * i, 3 * j) for i in range(3) for j in range(3)]
    for each in point:
        if not self.isValid([board[each[0] + x][each[1] + y] for x in range(3) for y in range(3)]):
            return False
    return True
