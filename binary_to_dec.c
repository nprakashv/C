#include <stdio.h>
#include <stdlib.h>

int bin_to_dec(int bin)
{
	int exp = 0;
	int dec = 0;

	while (bin) {
		dec = dec + ((bin % 10) * (1 << exp));
		bin = bin / 10;
		++exp;
	}

	return dec;
}

int main(int argc, char *argv[])
{
	if (argc < 2) {
		printf("Enter a valid binary number\n");
		printf("example: ./a.out 1010\n");
		return -1;
	}

	int dec = 0;

	dec = bin_to_dec(atoi(argv[1]));

	printf("Decimal equivalent:%d\n", dec);

	return 0;
}
