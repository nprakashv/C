#include <stdio.h>
#include "common.h"

bool check_elem(int *arr, int se, int index)
{
	int i;

	for (i = 0; i < index; i++) {
		if (arr[i] == se)
			return true;
	}
	return false;
}

int get_duplicates(int n, int *a, int *dup)
{
	int i, j;
	int cnt, index = 0;
	bool present;

	for (i = 0; i < n; i++)
	{
		cnt = 1;

		for (j = 0; j < n; j++) {
			if (i == j)
				continue;

			if (a[i] == a[j])
				cnt++;
		}

		if (cnt > 1) {
			/* Check if element already present */
			present = check_elem(dup, a[i], index);

			if (!present) {
				dup[index] = a[i];
				++index;
			}
		}
	}

	return index;
}

int main(int argc, char *argv[])
{
	if (argc < 2) {
		printf("Please enter the array elements\n");
		printf("./a.out elem1, elem2...elemn\n");
		return FAIL;
	}

	int size = argc - 1;
	int arr[size], dup_arr[size];
	int i = 0, dup_cnt = 0;

	/* Initialise the array as per user inputs */
	for ( i = 0; i < size; i++)
		arr[i] = atoi(argv[i + 1]);

	dup_cnt = get_duplicates(sizeof(arr)/sizeof(arr[0]), arr, dup_arr);

	printf("Duplicate elements in the array\n");

	for (i = 0; i < dup_cnt; i++)
		printf("%d\n", dup_arr[i]);

	return SUCCESS;
}
