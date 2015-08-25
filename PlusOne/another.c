int* plusOne(int* digits, int digitsSize, int* returnSize) {
    int tmp = 1, idx = digitsSize - 1 ;
    while(tmp  && idx >= 0)
    {
        digits[idx] += tmp;
        if(digits[idx] >= 10)
        {
            tmp = 1;
            digits[idx] -= 10;
        }
        else
        {
            tmp = 0;
        }
        idx--;
    }

    int *result;
    if(tmp)
    {
        *returnSize = digitsSize+1;
        result = malloc(sizeof(int) * (*returnSize));
        memcpy(result + 1, digits, digitsSize * sizeof(int));
        result[0] = 1;
    }
    else
    {
        *returnSize = digitsSize;
        result = digits;
    }
    return result;
}
