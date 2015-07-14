#include <stdio.h>
#include <stdbool.h<>
bool isValidSudoku(char** board, int boardRowSize, int boardColSize)
{
	int i, j, k;
	char t;
	
	for (i = 0; i < boardRowSize; i++)
    	{
        	for (j = 0; j < boardColSize; j++)
        	{
            		t = board[i][j];
            		if (t == '.')
                		continue;
            		for (k = j + 1; k < boardColSize; k++)
            		{
                		if (!(board[i][k] - t))
                    		return false;
            		}
            		for (k = i + 1; k < boardRowSize; k++)
            		{
                		if (!(board[k][j] - t))
                    		return false;
            		}
            		int n1, n2;
            		int r = 1;
            		for (n1 = i/3 * 3; n1 < (i/3 + 1) * 3; n1++)
            		{
                		for (n2 = j/3 * 3; n2 < (j/3 + 1) * 3; n2++)
                		{
                    			if (board[n1][n2] == t)
                    			{
                        			if (r)
                            				--r;
                        			else
                            				return false;
                    			}
                		}
            		}
        	}
    	}
	return true;
}
