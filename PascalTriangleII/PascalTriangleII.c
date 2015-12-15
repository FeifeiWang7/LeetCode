/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* getRow(int rowIndex, int* returnSize) {
        int i, j, k;
        int **result;
        result = (int **)malloc(sizeof(int*)*(rowIndex+1));
        result[0] = (int*)malloc(sizeof(int));
        result[0][0] = 1;
        for( i = 1; i < rowIndex+1; i ++)
        {
                result[i] = (int*)malloc(sizeof(int)*(i+1));
                result[i][0] = 1;
                result[i][i] = 1;
                for(j = 1; j < i; j++)
                {
                        result[i][j] = result[i-1][j-1] + result[i-1][j];
                }
        }
        *returnSize = rowIndex+1;
        return result[rowIndex];
}
