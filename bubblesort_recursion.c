#include <stdio.h>
#include "common.h"

void bubblesort(int *a, int n)
{
	if (n == 1)
		return;

	int i;

	for (i = 0; i < n - 1; i++) {
		if (a[i] > a[i + 1]) {
			int tmp;

			tmp = a[i];
			a[i] = a[i + 1];
			a[i + 1] = tmp;
		}
	}

	bubblesort(a, n - 1);
}

int main(int argc, char *argv[])
{
	if (argc < 2) {
		printf("Enter array elements, minimum one required\n");
		printf("example: ./a.out elem1 elem2 ...\n");
		return FAIL;
	}

	int size = argc - 1, i;
	int array[size];

	for (i = 0; i < size; i++)
		array[i] = atoi(argv[i + 1]);

	bubblesort(array, size);

	printf("Array after sorting\n");
	for (i = 0; i < size; i++)
		printf("%d\n", array[i]);

	return SUCCESS;
}
