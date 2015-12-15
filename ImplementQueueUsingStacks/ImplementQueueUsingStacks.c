typedef struct {
	int *content;
	int top;
	int base;
	int maxSize;    
} Queue;

/* Create a queue */
void queueCreate(Queue *queue, int maxSize) {
	queue->content = (int *)malloc(sizeof(int)*maxSize);
	queue->maxSize = maxSize;
	queue->top = 0;
	queue->base = 0;
}

/* Push element x to the back of queue */
void queuePush(Queue *queue, int element) {
	queue->top = (queue->top + 1)%queue->maxSize;
	queue->content[(queue->top)] = element;
}

/* Removes the element from front of queue */
void queuePop(Queue *queue) {
	queue->base = (queue->base + 1)%queue->maxSize;
}

/* Get the front element */
int queuePeek(Queue *queue) {
	return queue->content[queue->top - 1];
}

/* Return whether the queue is empty */
bool queueEmpty(Queue *queue) {
	return queue->top == queue->base;
    
}

/* Destroy the queue */
void queueDestroy(Queue *queue) {
    	free(queue->content);
	queue->content = NULL;
	queue->top = 0;
	queue->base = 0;
	queue->maxSize = 0;
}
