#include<stdio.h>
#include "common.h"

#define TEST_DATA	0x12345678

union {
	int data;
	struct bitfilefds {
		int a : 8;
		int b : 8;
		int c : 8;
		int d : 8;
	} bits;
} word;

int main()
{
	word.data = TEST_DATA;

	if (word.bits.a == (TEST_DATA & 0xFF))
		printf("Little Endian\n");
	else
		printf("Big Endian\n");

	return SUCCESS;
}
