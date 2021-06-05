#include <stdio.h>
#include "common.h"

int main()
{
	/* Two 1D array with three elements each */
	int array[2][3] = {1, 2, 3, 4, 5, 6};
	int i, j;

	/* Print 2D array elements
	 * array - pointer to first 1D array
	 * array + i - pointer to ith 1D array
	 * *(array + i) - pointer to 1st element of ith 1D array
	 * (*(array + i) + j) - pointer to jth element of ith 1D array
	 */
	for (i = 0; i < 2; i++)
		for (j = 0; j < 3; j++)
			printf("%d\n", *(*(array + i) + j));

	return SUCCESS;
}
