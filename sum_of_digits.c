#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	if (argc < 2) {
		printf("Enter the number for which sum of digits should be"
			" calculated\n");
		printf("usage: ./a.out number\n");
		return -1;
	}

	int num = atoi(argv[1]);
	int sum = 0, dig = 0;

	while (num) {
		dig = num % 10;
		sum = sum + dig;
		num = num / 10;
	}

	printf("Sum of digits: %d\n", sum);

	return 0;
}
