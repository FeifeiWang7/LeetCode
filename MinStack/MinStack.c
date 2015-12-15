typedef struct {
	int *content;
	int maxSize;
	int top;   
	int min;
} MinStack;

void minStackCreate(MinStack *stack, int maxSize) {
	stack->content = (int*)malloc(sizeof(int)*maxSize);
	stack->maxSize = maxSize;
	stack->top = -1;
}

void minStackPush(MinStack *stack, int element) {
	if(stack->top >= stack->maxSize-1) return;
	*(stack->content + (++stack->top)) = element;
}

void minStackPop(MinStack *stack) {
	if(stack->top < 0) return;
	stack->top--;
}

int minStackTop(MinStack *stack) {
    return *(stack->content + stack->top);
}

int minStackGetMin(MinStack *stack) {
	int i;
	int min = *(stack->content);
	for(i = 1; i <= stack->top; i++)
	{
		if (*(stack->content + i) < min)
			min = *(stack->content+i);
	}
	return min;
}

void minStackDestroy(MinStack *stack) {
	free(stack->content);
	stack->content = NULL;
	stack->maxSize = 0;
    	stack->top = -1;
}
