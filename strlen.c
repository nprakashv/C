#include "common.h"

/* Function to get length of the string
 * @str: pointer to the string
 *
 * Returns length of the string passed.
 */
int getlen(char *str)
{
	int i = 0;

	while (*(str + i) != '\0')
		++i;

	return i;
}

int main(int argc, char *argv[])
{
	if (argc < 2) {
		printf("Enter a valid string\n");
		printf("Example: ./a.out string\n");
		return FAIL;
	}

	int len = 0;

	len = getlen(argv[1]);

	printf("Length of %s : %d\n", argv[1], len);

	return SUCCESS;
}
