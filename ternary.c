#include <stdio.h>
#include <stdlib.h>

#define FAIL	-1
#define SUCCESS	0

int main(int argc, char *argv[])
{
	if (argc < 4) {
		printf("Enter three numbers to check largest among them\n");
		printf("example: ./a.out num1 num2 num3\n");
		return FAIL;
	}
	int num1 = atoi(argv[1]), num2 = atoi(argv[2]), num3 = atoi(argv[3]);

	int largest = (num1 > num2) ? ((num1 > num3) ? num1 : num3) : ((num2 > num3) ? num2 : num3);

	printf("Largest:%d\n", largest);

	return SUCCESS;
}
