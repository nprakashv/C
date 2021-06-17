#include <stdio.h>
#include "common.h"

void duplicate_zeros(int *a, int size)
{
	int i, j;

	for (i = 0; i < size;)
	{
		if (a[i] == 0) {
			for (j = size - 1; j >= i + 2; j--)
				a[j] = a[j - 1];
			a[i + 1] = 0;
			i += 2;
		} else {
			++i;
		}
	}
}

int main(int argc, char *argv[])
{
	if (argc < 2) {
		printf("Please enter array elements, min. one required\n");
		printf("example: ./a.out elem1 elem2..\n");
		return FAIL;
	}

	int size = argc - 1;
	int array[size];
	int i;

	for (i = 0; i < size; i++)
		array[i] = atoi(argv[i + 1]);

	/* Function to duplicate each occurance of zero */
	duplicate_zeros(array, size);

	printf("Array after duplicating zeroes\n");
	for (i = 0; i < size; i++)
		printf("%d\n", array[i]);

	return SUCCESS;
}
