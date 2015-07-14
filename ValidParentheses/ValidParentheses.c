#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
typedef char stackElementT;

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

bool isValid(char *s)
{
	int len = strlen(s);
	stackT left, right;
	StackInit(&left, len);
	StackInit(&right,len);
	int i;

	for(i = 0; i < len; i ++) 
	{
		StackPush(&left, s[i]);
	}
	char a, b;

	while(!StackIsEmpty(&left))
	{
		a = StackPop(&left);
		switch(a)
		{
			case '(':
				if(StackIsEmpty(&right)) return false;
				b = StackPop(&right);
				if( b != ')') return false;
				else break;
			case '[':
				if(StackIsEmpty(&right)) return false;
				b = StackPop(&right);
				if( b != ']') return false;
				else break;
			case '{':
				if(StackIsEmpty(&right)) return false;
				b = StackPop(&right);
				if( b != '}') return false;
				else break;
			case ')': StackPush(&right, a); break;
			case ']': StackPush(&right, a); break;
			case '}': StackPush(&right, a); break;
			default: printf("unrecognized char.\n");
		}
	}
	if(StackIsEmpty(&right)) return true;
	return false;
}
int main()
{
	char s[] = "";
	printf("%d\n", isValid(s));
	return 0;
}
