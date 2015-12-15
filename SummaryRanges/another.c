///Dynamically allocate the 2-dimentional array.

char** summaryRanges(int* nums, int numsSize, int* returnSize) {

char **result = (char **)malloc(sizeof(char *));
*returnSize = 0;
int s = 0, e = 0;

while (s < numsSize)
{
    if ((e + 1 < numsSize) && (nums[e + 1] == nums[e] + 1))
        e++;
    else
    {
        if (s == e)
        {
            (*returnSize)++;
            result = (char **)realloc(result, (*returnSize)*sizeof(char *));
            result[*returnSize - 1] = (char *)malloc(12 * sizeof(char));//integer may have many decimal bits
            sprintf(result[*returnSize - 1], "%d", nums[s]);
        }
        else
        {
            (*returnSize)++;
            result = (char **)realloc(result, (*returnSize)*sizeof(char *));
            result[*returnSize - 1] = (char *)malloc(25 * sizeof(char)); //integer may have many decimal bits
            sprintf(result[*returnSize - 1], "%d->%d", nums[s], nums[e]);
        }
        s = e + 1;
        e = s;
    }
}
return result;
}
