////dp
int longestValidParentheses(char* s)
{
        int len = strlen(s); int i, max = 0;
        int *res = (int *)malloc(sizeof(int)*len);
        memset(res, 0, len*sizeof(int));
        for(i = 0; i < len; i++)
        {
                if((s[i] == ')') && (i - res[i-1] - 1 >= 0) && (s[i - res[i-1] - 1] == '('))
                {
                        res[i] = res[i-1] + 2;
                        if((i - res[i-1] -2 >= 0) && (res[i-res[i-1]-2] > 0)) 
                        {
                                res[i] = res[i-res[i-1]-2] + res[i];
                                res[i - res[i-1] -1] = res[i];
                        }
                }
                max = max > res[i] ? max:res[i];
        }
        return max;
}
////stack
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
typedef int stackElementT; //define stack type here

typedef struct
{
	stackElementT *contents;
	int top;
	int maxSize;
}stackT;

void StackInit(stackT *stackP, int maxSize)
{
	stackElementT *newContents;
	newContents = (stackElementT *)malloc(sizeof(stackElementT)*maxSize);
	if(newContents == NULL)
	{
		fprintf(stderr, "Insufficient memory to initialize stack.\n");
		exit(1);
	}
	stackP->contents = newContents;
	stackP->maxSize = maxSize;
	stackP->top = -1;
}

void StackDestroy(stackT *stackP)
{
	free(stackP->contents);
	stackP->contents = NULL;
	stackP->maxSize = 0;
	stackP->top = -1;
}

int StackIsEmpty(stackT *stackP)
{
	return stackP->top < 0;
}

int StackIsFull(stackT *stackP)
{
	return stackP->top >= stackP->maxSize - 1;
}

void StackPush(stackT *stackP, stackElementT element)
{
	if (StackIsFull(stackP))
	{
		fprintf(stderr, "Can't push element on stack: stack is full.\n");
		exit(1);
	}
	stackP->contents[++stackP->top] = element;
}

stackElementT StackPop(stackT *stackP)
{
	if(StackIsEmpty(stackP))
	{
		fprintf(stderr, "Can't pop element from stack: stack is empty.\n");
		exit(1);	
	}
	return stackP->contents[stackP->top--];
}
int longestValidParentheses(char* s) 
{
	stackT mystack;
	StackInit(&mystack, 1000);
	int i, max= 0; int start = -1;
	for(i = 0; i < strlen(s); i++)
	{
		if(s[i] == '(') StackPush(&mystack, i);
		else
		{
			if(!StackIsEmpty(&mystack))
			{
				StackPop(&mystack);
				if(StackIsEmpty(&mystack))
					max = max > i- start ? max : i - start;
				else max = max > (i - mystack.contents[mystack.top]) ? max: (i - mystack.contents[mystack.top]);
			}
			else start = i;
		}
	}


	StackDestroy(&mystack);
	return max;
}
int main()
{
	printf("%d\n", longestValidParentheses("()(()"));
	return 0;
}
