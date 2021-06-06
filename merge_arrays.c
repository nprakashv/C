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

void merge(int *a1, int *a2, int n1, int n2, int *merge)
{
	int i = 0, a1_index = 0, a2_index = 0;


	while (a1_index < n1 && a2_index < n2) {
		if (a1[a1_index] < a2[a2_index]) {
			merge[i] = a1[a1_index];
			++a1_index;
			++i;
		} else {
			merge[i] = a2[a2_index];
			++a2_index;
			++i;
		}
	}

	while (a1_index < n1) {
		merge[i] = a1[a1_index];
		++a1_index;
		++i;
	}

	while (a2_index < n1) {
		merge[i] = a2[a2_index];
		++a2_index;
		++i;
	}
}

int main(int argc, char *argv[])
{
	int array1[5] = {4, 3, 2, 1, 0};
	int array2[5] = {9, 8, 7, 6, 5};
	int n1 = sizeof(array1)/sizeof(array1[0]);
	int n2 = sizeof(array2)/sizeof(array2[0]);
	int mergelen = n1 + n2;
	int mergearray[mergelen];
	int i;

	/* Sort 1st array */
	bubblesort(array1, sizeof(array1)/sizeof(array1[0]));

	/* Sort 2nd array */
	bubblesort(array2, sizeof(array2)/sizeof(array2[0]));

	/* Merge arrays array1 and array2 */
	merge(array1, array2, n1, n2, mergearray);

	printf("Merged array\n");
	for (i = 0; i < mergelen; i++)
		printf("%d\n", mergearray[i]);

	return SUCCESS;
}
