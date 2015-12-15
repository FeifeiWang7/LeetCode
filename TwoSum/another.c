void swap(int *x, int *y)
{
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
    return;

}
int search(int numbers[], int target, int low, int high)
{
    if (low > high)
        return -1;
    int mid = low + (high - low) / 2;
    if (target < numbers[mid])
        return search(numbers, target, low, mid - 1);
    else if (target > numbers[mid])
        return search(numbers, target, mid + 1, high);
    else
        return mid;
}
void sort(int numbers[], int orders[], int low, int high)
{
    int key, keyOrder, i, j, ran;
    if (low < high)
    {
        ran = (low + high) / 2;
        swap(&numbers[ran], &numbers[low]);
        swap(&orders[ran], &orders[low]);
        key = numbers[low];
        keyOrder = orders[low];
        i = low + 1;
        j = high;
        while (i <= j)
        {
            while ((i <= high) && (numbers[i] <= key))
                i++;
            while ((j >= low) && (numbers[j] > key))
                j--;
            if (i < j)
            {
                swap(&numbers[i], &numbers[j]);
                swap(&orders[i], &orders[j]);
            }

        }
        swap(&numbers[low], &numbers[j]);
        swap(&orders[low], &orders[j]);
        sort(numbers, orders, low, j - 1);
        sort(numbers, orders, j + 1, high);
    }

}
int *twoSum(int numbers[], int n, int target) {
    int i = 0, j = -1;
    int *index = (int *)malloc(2 * sizeof(int));
    int len = n;
    int *orders = (int *)malloc(n * sizeof(int));
    for (i = 0; i < len; i++)
    {
        orders[i] = i + 1;
    }
    sort(numbers, orders, 0, len - 1);
    for (i = 0; i < len; i++)
    {
        j = search(numbers, target - numbers[i], i + 1, len - 1);
        if (j > -1)
            break;
    }
    if (j > -1)
    {
        if (orders[i] > orders[j])
        {
            index[0] = orders[j]; index[1] = orders[i];
        }
        else
        {
            index[0] = orders[i]; index[1] = orders[j];
        }
        return index;
    }
    else
        return NULL;
}
///
typedef struct Node {
    int value;
    int pos;
} Node;

int cmp(const void* a, const void* b) {
    return ((Node*)a)->value - ((Node*) b)->value;
}

// recusively binary search for a node which + baseNode = target
int* twoSumHelper(Node* nodeArr, int start_pos, int end_pos, Node* baseNode, int target) {
    int pos = (start_pos + end_pos) / 2;
    int sum = nodeArr[pos].value + baseNode->value;
    if (sum == target) {
        int* result = malloc(sizeof(int) * 2);
        result[0] = baseNode->pos;
        result[1] = nodeArr[pos].pos;
        return result;
    } else {
        if (start_pos == end_pos) {
            return NULL;
        }

        if (sum > target){
            return twoSumHelper(nodeArr, start_pos, pos, baseNode, target);
        } else {
            return twoSumHelper(nodeArr, pos + 1, end_pos, baseNode, target);
        }
    }
}

int* twoSum(int* nums, int numsSize, int target) {
    Node* nodeArr = malloc(sizeof(Node) * numsSize);
    int i;
    for (i = 0; i < numsSize; i++) {
        nodeArr[i] = (Node){
            .value = nums[i],
            .pos = i + 1,
        };
    }
    qsort(nodeArr, numsSize, sizeof(Node), cmp);
    int* result;
    for (i = 0; i < numsSize; i++) {
        result = twoSumHelper(nodeArr, i+1, numsSize - 1, &nodeArr[i], target);
        if (result) {
            free(nodeArr);

            // sort result
            if (result[0] > result[1]) {
                result[0] = result[0] + result[1];
                result[1] = result[0] - result[1];
                result[0] = result[0] - result[1];
            }
            return result;
        }
    }
}
////
int* twoSum(int* nums, int numsSize, int target) 
{
 int* result = malloc(2*sizeof(int));
 result[0] = result[1] = 0;
 for(int i = numsSize -1 ; i > -1; i--)   
 {
    if(nums[i] <= target || target < 0)
    {
        for(int j = 0 ; j< numsSize; j++)   
        {
            if(i != j)
            {
                int temp = nums[i] + nums[j];
                if(temp == target)
                {
                    result[0] = i > j ? j + 1 : i + 1;
                    result[1] = j > i ? j + 1 : i + 1;

                   return result;
                }
            }
        }
    }
 }
 return result;
}
///
struct node {

int val;
int index;
};

static int cmp(const void *a, const void *b) {

return ((struct node *)a)->val - ((struct node *)b)->val;
}

int* twoSum(int* nums, int numsSize, int target) {

int *ret;
struct node *head;
int i,j;
int sum;

ret = (int *)malloc(sizeof(int) * 2);
head = (struct node *)malloc(sizeof(struct node) * numsSize);
for(i = 0; i < numsSize; ++i){
    head[i].index = i + 1;
    head[i].val = nums[i];
}

qsort(head,numsSize,sizeof(struct node),cmp);

i = 0;
j = numsSize - 1;
while(i < j){
    sum = head[i].val + head[j].val;
    if(sum == target){
        ret[0] = head[i].index < head[j].index ? head[i].index : head[j].index;
        ret[1] = head[i].index >= head[j].index ? head[i].index : head[j].index;
        break;
    }else if(sum > target){
        --j;
    }else{
        ++i;
    }
}

return ret;
}


