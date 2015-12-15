bool isNumber(char* s) 
{
        char fsm[10][128];
        memset(fsm, 10, sizeof(fsm));
        for (char i = '0'; i <= '9'; i++) 
        {
            fsm[0][i] = 1;
            fsm[1][i] = 1;
            fsm[2][i] = 3;
            fsm[3][i] = 3;
            fsm[5][i] = 3;
            fsm[6][i] = 1;
            fsm[7][i] = 8;
            fsm[8][i] = 8;
            fsm[2][i] = 8;
            fsm[9][i] = 8;
        }
        fsm[0][' '] = 0;
        fsm[1][' '] = 4;
        fsm[3][' '] = 4;
        fsm[4][' '] = 4;
        fsm[8][' '] = 4;
        fsm[1]['e'] = 2;
        fsm[3]['e'] = 7;
        fsm[1]['.'] = 3;
        fsm[0]['.'] = 5;
        fsm[0]['-'] = 6;
        fsm[0]['+'] = 6;
        fsm[6]['.'] = 5;
        fsm[7]['+'] = 9;
        fsm[7]['-'] = 9;
        fsm[2]['+'] = 9;
        fsm[2]['-'] = 9;
        int state = 0;
        char *p = s;
        while(*p != '\0') 
        {
            state = fsm[state][*p++];
            if (state > 9) 
                return false;
        }
        if (state == 1 || state == 3 || state == 4 ||state == 8 ) 
        {
            return true;
        } 
        else 
        {
            return false;
        }
}
