/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *columnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

int** generate(int numRows, int** columnSizes, int* returnSize)
{
        int i, j, k;
        int **result;
        (*columnSizes) = (int *)malloc(sizeof(int)*numRows);
        result = (int **)malloc(sizeof(int*)*numRows);
        result[0] = (int*)malloc(sizeof(int));
        result[0][0] = 1;
        (*columnSizes)[0] = 1;
        for( i = 1; i < numRows; i ++)
        {
                (*columnSizes)[i] = i+1;
                result[i] = (int*)malloc(sizeof(int)*(i+1));
                result[i][0] = 1;
                result[i][i] = 1;
                for(j = 1; j < i; j++)
                {
                        result[i][j] = result[i-1][j-1] + result[i-1][j];
                }
        }
        *returnSize = numRows;
        return result;
}
