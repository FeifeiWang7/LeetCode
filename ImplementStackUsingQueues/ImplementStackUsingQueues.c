typedef struct {
	int *content;
   	int top;
	int maxSize;
} Stack;

/* Create a stack */
void stackCreate(Stack *stack, int maxSize) {
    	stack->content = (int*)malloc(sizeof(int)*maxSize);
	stack->maxSize = maxSize;
	stack->top = -1;
}

/* Push element x onto stack */
void stackPush(Stack *stack, int element) {
    stack->content[++stack->top] = element;
}

/* Removes the element on top of the stack */
void stackPop(Stack *stack) {
    stack->top--;
}

/* Get the top element */
int stackTop(Stack *stack) {
    return stack->content[stack->top--];
}

/* Return whether the stack is empty */
bool stackEmpty(Stack *stack) {
    return stack->top < 0;
}

/* Destroy the stack */
void stackDestroy(Stack *stack) {
    free(stack->content);
	stack->content = NULL;
	stack->maxSize = 0;
	stack->top = -1;
}
