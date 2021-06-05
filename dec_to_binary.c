#include <stdio.h>
#include <stdlib.h>

int dec_to_bin(int dec)
{
	int bin = 0, base = 1, rem = 0;

	while (dec) {
		rem = dec  % 2;
		bin = bin + (base * rem);
		base = base * 10;
		dec = dec / 2;
	}

	return bin;
}

int main(int argc, char *argv[])
{
	if (argc < 2) {
		printf("Enter the decimal number\n");
		return -1;
	}

	int bin = 0;

	bin = dec_to_bin(atoi(argv[1]));

	printf("Binary equivalent %d\n", bin);

	return 0;
}
