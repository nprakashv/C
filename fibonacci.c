#include <stdio.h>
#include "common.h"

int fibonacci(int n)
{
	if (n <= 1)
		return n;

	return fibonacci(n - 1) + fibonacci(n - 2);
}

int main(int argc, char *argv[])
{
	if (argc < 2) {
		printf("Enter the fibonacci series limit\n");
		printf("example: ./a.out n\n");
		return FAIL;
	}

	int fib = fibonacci(atoi(argv[1]));

	printf("Integer%d in fibonacci series: %d\n", atoi(argv[1]), fib);

	return SUCCESS;
}
