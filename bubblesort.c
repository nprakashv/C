#include <stdio.h>
#include "common.h"

void bubblesort(int *a, int n)
{
	int i, j;

	for (i = 0; i < n; i++) {
		for (j = 0; j < (n - i - 1); j++) {
			if (a[j] > a[j + 1]) {
				int tmp;
				tmp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = tmp;
			}
		}
	}
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
