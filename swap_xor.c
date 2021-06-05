#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b)
{
	*a = *a ^ *b;
	*b = *a ^ *b;
	*a = *a ^ *b;
}

int main(int argc, char *argv[])
{
	if (argc < 3) {
		printf("Enter the values to be swapped\n");
		printf("Usage: ./a.out val1 val2\n");
		return -1;
	}

	int a = 0, b = 0;

	a = atoi(argv[1]);
	b = atoi(argv[2]);

	printf("Values before swapping a:%d & b:%d\n", a, b);
	swap(&a, &b);

	printf("Values after swapping a:%d & b:%d\n", a, b);

	return 0;
}
