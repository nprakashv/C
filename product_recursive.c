#include <stdio.h>
#include <stdlib.h>

int product(int n1, int n2)
{
	if (n2 == 0)
		return 0;

	return n1 + product(n1, --n2);
}

int main(int argc, char *argv[])
{
	if (argc < 3) {
		printf("Enter two numbers whose product is to be calculated\n");
		printf("example: ./a.out num1 num2\n");
		return -1;
	}

	int prod = 0;

	prod = product(atoi(argv[1]), atoi(argv[2]));

	printf("Product %d\n", prod);

	return 0;
}
