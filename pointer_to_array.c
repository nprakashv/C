#include <stdio.h>
#include "common.h"

int main(int argc, char *argv[])
{
	if (argc < 2) {
		printf("Enter the num of array elements\n");
		printf("example: ./a.out num\n");
		return FAIL;
	}

	int array[atoi(argv[1])];
	int i = 0;

	/* Initialise the array */
	for (i = 1; i <= atoi(argv[1]); i++)
		array[i] = i;

	/* Take pointer to array */
	int (*ptr)[atoi(argv[1])] = &array;

	/* Print array elements using pointer */
	printf("Array elements\n");
	for (i = 1; i <= atoi(argv[1]); i++)
		printf("%d\n", *(*ptr + i));

	return SUCCESS;
}
