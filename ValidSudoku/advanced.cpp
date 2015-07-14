static inline bool checkDup(unsigned *m, char x) {
    if (x == '.')
        return false;
    if (*m & 1<< (x - '0'))
        return true;
    *m |= (1 << (x - '0'));
    return false;
}

bool isValidSudoku(char board[9][9]) {
    short cols[] = {0,0,0,0,0,0,0,0,0};
    short blocks[]= {0,0,0,0,0,0,0,0,0};
    for(unsigned i = 0; i < 9; ++i) {
        for(unsigned j = 0, r = 0; j < 9; ++j)
            if (checkDup(&r, board[i][j]) /*check row*/ || checkDup(cols+j, board[i][j]) /*check col */
                || checkDup(blocks + (i/3) * 3 + j/3, board[i][j]) /* check sub block */)
                return false;
    }
    return true;
}
