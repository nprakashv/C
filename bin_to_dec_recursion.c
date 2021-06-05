#include <stdio.h>
#include <stdlib.h>

int bin_to_dec(int bin, int exponent)
{
	if (!bin)
		return 0;

	return ((bin % 10) * (1 << exponent)) + bin_to_dec(bin / 10, ++exponent);
}

int main(int argc, char *argv[])
{
	if (argc < 2) {
		printf("Enter a valid binary number\n");
		printf("example: ./a.out 1010\n");
		return -1;
	}

	int dec = 0, exp = 0;

	dec = bin_to_dec(atoi(argv[1]), exp);

	printf("Decimal equivalent:%d\n", dec);

	return 0;
}
