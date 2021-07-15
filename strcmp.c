#include <assert.h>
#include "common.h"

/* Function to implement strcmp
 * @str1: First null terminated string for comparison
 * @str2: Second null terminated string for comparison
 *
 * Returns zero if strings are equal, negative if str1 < str2,
 * positive if str1 > str2.
 *
 * Note:
 * Function expects pointers to be valid, aborts if NULL.
 */
int strcmp_imp(char *str1, char *str2)
{
	assert((str1 != NULL) && (str2 != NULL));

	int i = 0;

	/* Traverse each string character by character. If either of the
	 * condition fails, it implies strings are of different length */
	while ((*(str1 + i) != '\0') && (*(str2 + i) != '\0')) {
		if (*(str1 + i) != *(str2 + i))
			return *(str1 + i) - *(str2 + i);
		++i;
	}

	while ((*(str1 + i) != '\0'))
		return *(str1 + i);

	while ((*(str2 + i) != '\0'))
		return -(*(str2 + i));

	/* If it reaches here, it means strings are equal */
	return 0;
}

int main(int argc, char *argv[])
{
	if (argc < 3) {
		printf("Enter two strings for comparison\n");
		printf("Example: ./a.out str1 str2\n");
		return FAIL;
	}

	int ret;

	ret = strcmp_imp(argv[1], argv[2]);

	if (!ret)
		printf("Strings are equal\n");

	return SUCCESS;
}
