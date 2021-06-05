#include <stdio.h>
#include <stdlib.h>

int dec_to_bin(int dec, int base)
{
	if (!dec)
		return 0;

	return ((dec % 2) * base) + dec_to_bin(dec / 2, base * 10);
}

int main(int argc, char *argv[])
{
	if (argc < 2) {
		printf("Enter the decimal number\n");
		return -1;
	}

	int bin = 0, base = 1;

	bin = dec_to_bin(atoi(argv[1]), base);

	printf("Binary equivalent %d\n", bin);

	return 0;
}
