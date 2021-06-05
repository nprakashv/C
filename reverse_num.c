#include <stdio.h>
#include <stdlib.h>

int reverse(int num)
{
	int rev = 0, dig = 0;

	while (num) {
		dig = num % 10;
		rev = (rev * 10) + dig;
		num = num / 10;
	}

	return rev;

}
int main(int argc, char *argv[])
{
	if (argc < 2) {
		printf("Enter the number to be reversed\n");
		printf("example: ./a.out 453\n");
		return -1;
	}

	int rev = -1;

	rev = reverse(atoi(argv[1]));

	printf("Reverse of the number:%d\n", rev);

	return 0;
}
