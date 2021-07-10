#include "common.h"

/* Function to implement strncat
 * @dst: string to be concatenated
 * @src: source string
 * @slen: length of src
 *
 * Returns pointer to destination string.
 */
static char *strncat_imp(char *dst, char *src, int slen)
{
	int dlen = strlen(dst);

	memcpy(dst + dlen, src, slen);
	*(dst + dlen + slen) = '\0';

	return dst;
}

int main(int argc, char *argv[])
{
	if (argc < 3) {
		printf("Enter two strings for concatenation\n");
		printf("Example: ./a.out string1 string2\n");
		return FAIL;
	}

	/* Concatenate argv[2] with argv[1] */
	strncat_imp(argv[1], argv[2], strlen(argv[2]));

	printf("String after concatenation: %s\n", argv[1]);

	return SUCCESS;
}
