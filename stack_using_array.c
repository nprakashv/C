#include <stdio.h>
#include "common.h"

#define STACK_SIZE	4096

/* Structure representing stack to be implemented */
struct stack {
	char data[STACK_SIZE]; // STACK_SIZE of 4096 bytes
	int top; // Top of stack
};

static struct stack *sp = NULL;

/* Function to check if stack is full
 * returns 1 if full, 0 if space available, -1 if sp == NULL
 */
int stack_full()
{
	if (sp) {
		if (sp->top == (STACK_SIZE - 1))
			return 1;
		else
			return 0;
	}

	return -1;
}

/* Function to check if stack is empty
 * returns 1 if empty, 0 if some data present, -1 if sp == NULL
 */
int stack_empty()
{
	if (sp) {
		if (sp->top == -1)
			return 1;
		else
			return 0;
	}

	return -1;
}

/* Function to push data to stack */
int push(char data)
{
	if (stack_full())
		return -1;

	sp->data[++sp->top] = data;
}

/* Function to get data to stack */
char pop()
{
	if (stack_empty())
		return 0;

	return sp->data[sp->top--];
}

int main(int argc, char *argv[])
{
	if (argc < 2) {
		printf("Enter the data(char) to be pushed to the stack, minimum one required\n");
		printf("example: ./a.out a\n");
		return FAIL;
	}

	sp = (struct stack *)malloc(sizeof(struct stack));
	if (!sp) {
		printf("No memory available\n");
		return FAIL;
	}
	sp->top = -1; // Initially top of stack should be -1

	int i, ret;
	char data[argc - 1], val;

	for (i = 0; i < argc - 1; i++)
		data[i] = *(argv[ i + 1]);

	i = 0;

	/* Push data to stack */
	while(!stack_full() && i < (argc - 1)) {

		push(data[i]);
		++i;
	}

	/* Read data from stack */
	while (!stack_empty()) {

		val = pop();
		printf("Data read from stack %c\n", val);
	}

	free(sp);

	return SUCCESS;
}
