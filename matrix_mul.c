#include<stdio.h>
#include "common.h"

/* Function to print matrix elements */
void print_matrix(int rows, int col, int *arr)
{
	int i, j;

	for (i = 0; i < rows; i++) {
		for (j = 0; j < col; j++)
			printf("%d ", *(arr + j + (i * col)));
		printf("\n");
	}
	printf("\n");
}

/* Function to add matrix elements */
void add_elements(int *arr, int rows, int col)
{
	int i, j;

	for ( i = 0; i < rows; i++)
		for (j = 0; j < col; j++)
			*(arr + j + (i * col)) = j + (i * col);
}

/* Function to perform matrix multiplication and print result */
void matrix_mul(int *matrix1, int *matrix2, int row1, int col2, int col1)
{
	if (!matrix1 || !matrix2)
		return;

	int result[row1][col2];
	int i, j, k;

	for (i = 0; i < row1; i++) {
		for ( j = 0; j < col2; j++) {
			result[i][j] = 0;

			for (k = 0; k < col1; k++) {
				result[i][j] = result[i][j] + (*(matrix1 + (i * col1) + k) * *(matrix2 + j + (k * col2)));
			}
		}
	}

	printf("Resultant matrix\n");
	print_matrix(row1, col2, *result);

}

int main(int argc, char *argv[])
{
	if (argc < 3) {
		printf("Enter the number of rows and columns of each matrix\n");
		printf("Example: ./a.out row1 col1 row2 col2\n");
		return FAIL;
	}

	/* Get the row and column count for each matrix as per user input*/
	int row1 =  atoi(argv[1]), col1 = atoi(argv[2]);
	int row2 =  atoi(argv[3]), col2 = atoi(argv[4]);

	if (col1 != row2)  {
		printf("For matrix multiplication, col1 should be equal to row2\n");
		printf("Example: if matrix1 is m x n, matrix2 should be n x k\n");
		return FAIL;
	}

	int *arr1 = NULL, *arr2 = NULL;
	int i, j;

	/* Dynamically allocate memory for both matrix */
	arr1 = (int *)malloc(row1 * col1 * sizeof(int));
	arr2 = (int *)malloc(row2 * col2 * sizeof(int));

	if (!arr1 || !arr2) {
		printf("Memory allocation failed\n");
		return FAIL;
	}

	/* Push data(index for now) to both matrix */
	add_elements(arr1, row1, col1);
	add_elements(arr2, row2, col2);

	printf("Matrix1\n");
	print_matrix(row1, col1, arr1);

	printf("Matrix2\n");
	print_matrix(row2, col2, arr2);

	/* Perform matrix multiplication */
	matrix_mul(arr1, arr2, row1, col2, col1);

	free(arr1);
	free(arr2);

	return SUCCESS;
}
