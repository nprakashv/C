#include<stdio.h>
#include "common.h"

int binarysearch(int *a, int n, int se)
{
	int s = 0, end = n - 1, mid;

	while (s <= end) {

		mid = (s + end) / 2;

		if (a[mid] == se)
			return mid;
		else if (a[mid] > se)
			end = mid - 1;
		else
			s = mid + 1;
	}

	return FAIL;
}

int main(int argc, char *argv[])
{
	if (argc < 2) {
		printf("Enter the search element\n");
		printf("example: ./a.out searchelem\n");
		return FAIL;
	}

	int array[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	int se = atoi(argv[1]);
	int pos = -1;

	pos = binarysearch(array, sizeof(array)/sizeof(array[0]), se);

	if (pos != FAIL) {
		printf("Element found at index: %d\n", pos);
		return SUCCESS;
	} else {
		printf("Element not found in the array\n");
		return FAIL;
	}
}
