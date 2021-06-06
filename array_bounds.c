#include <stdio.h>
#include <stdbool.h>
#include "common.h"

bool check_bounds(int *arr, int pos, int size)
{
	if ((arr + pos) > (arr + size))
		return false;
	else
		return true;
}

int main(int argc, char *argv[])
{
	if (argc < 3) {
		printf("Enter the size of array, position and value to be inserted\n");
		printf("example: ./a.out size pos val\n");
		return FAIL;
	}

	int size = atoi(argv[1]), pos = atoi(argv[2]), val = atoi(argv[3]);
	int arr[size];
	bool check;

	check = check_bounds(arr, pos, sizeof(arr)/sizeof(arr[0]));

	if (check) {
		printf("Position is within the array size\n");
		arr[pos] = val;
		return SUCCESS;
	} else {
		printf("Position is not within the array size\n");
		return FAIL;
	}
}
