#include <stdio.h>
#include "common.h"

int num_odd(int n, int *a)
{
	int i, j;
	int cnt, oddcnt = 0;

	for (i = 0; i < n; i++)
	{
		cnt = 1;

		for (j = 0; j < n; j++) {
			if (i == j)
				continue;

			if (a[i] == a[j])
				cnt++;
		}

		if (cnt % 2 != 0)
			++oddcnt;
	}

	return oddcnt;
}

int main(int argc, char *argv[])
{
	if (argc < 2) {
		printf("Please enter the array elements\n");
		printf("./a.out elem1, elem2...elemn\n");
		return FAIL;
	}

	int size = argc - 1;
	int arr[size], i, ret = 0;

	/* Initialise the array as per user inputs */
	for ( i = 0; i < size; i++)
		arr[i] = atoi(argv[i + 1]);

	ret = num_odd(sizeof(arr)/sizeof(arr[0]), arr);

	printf("Number of array elements occuring odd times: %d\n", ret);

	return SUCCESS;
}
