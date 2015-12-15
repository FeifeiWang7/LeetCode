typedef struct {
    int *base;
    int *top;
    int size;
    int min;
    int min_num;
} MinStack;

void minStackCreate(MinStack *stack, int maxSize) {
    stack -> base = (int *)malloc(sizeof(int) * maxSize);
    stack -> top = stack -> base;
    stack -> size = 0;
    stack -> min = INT_MAX;
    stack -> min_num = 0;
}

void minStackPush(MinStack *stack, int element) {
    *(stack -> top) = element;
    stack -> top += 1;
    if(element < stack -> min){
        stack -> min = element;
        stack -> min_num = 1;
    }else if(element == stack -> min){
        stack -> min_num += 1;
    }
    stack -> size += 1;
}

void minStackPop(MinStack *stack) {
    stack -> top -= 1;
    int cur = *(stack -> top);
    stack -> size -= 1;
    if(cur > stack -> min)
        return;
    else{
        /* If we know more than one element that equals stack->min, 
         * we don't have to traverse the stack to find another stack->min 
         * while we already know its value! */
        if(stack -> min_num > 1){
            stack -> min_num -= 1;
        }else{
            int i = 0, min = INT_MAX, min_num = 0;
            for(; i < stack -> size; i++){
                if((stack -> base)[i] < min){
                    min = (stack -> base)[i];
                    min_num = 1;
                }else if((stack -> base)[i] == min){
                    min_num += 1;
                }
            }
            stack -> min = min;
            stack -> min_num = min_num;
        }
    }
}

int minStackTop(MinStack *stack) {
    stack -> top -= 1;
    int res = *(stack -> top);
    stack -> top += 1;
    return res;
}

int minStackGetMin(MinStack *stack) {
    return stack -> min;
}

void minStackDestroy(MinStack *stack) {
    free(stack -> base);
    stack -> base = NULL;
    stack -> top = NULL;
}
