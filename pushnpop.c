#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXIMUM_STACK_SIZE 100

typedef struct{
	char *items[MAXIMUM_STACK_SIZE];
	int top;
}Stack;

void initialize(Stack *stack){
	stack->top = -1;
}

int isFull(Stack *stack){
	return stack->top == MAXIMUM_STACK_SIZE - 1;
}

int isEmpty(Stack *stack){
	return stack->top == -1;
}

void push(Stack *stack, const char *item){
	if(isFull(stack))
	{
		printf("Stack overflow\n");
		return ;
	}
	stack->top++;
	stack->items[stack->top]=strdup(item);

}

char *pop(Stack *stack)
{
	if(isEmpty(stack))
	{
		printf("Stack underflow\n");
		return NULL;
	}
	return stack->items[stack->top--];
}

void pushd(Stack *stack, const char *directory){
	push(stack,directory);
}

char *popd(Stack *stack)
{
	return pop(stack);
}

int main(int argc, char *argv[]){
	Stack dirstack;
	initialize(&dirstack);

	pushd(&dirstack,argv[1]);
	pushd(&dirstack,argv[2]);

	printf("Current dir after pushd operation : %s\n", dirstack.items[dirstack.top]);

	char *popdir=popd(&dirstack);
	if(popdir != NULL){
		printf("Popped dir : %s\n",popdir);
		free(popdir);
	}

	printf("Current dir after popd operation : %s\n",dirstack.items[dirstack.top]);

	return 0;
}
