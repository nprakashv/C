#include "common.h"

/* Function to check if string is palindrome or not recursively.
 * @str: pointer to the string to be checked.
 * @si: starting index of string
 * @li: last index of the string
 * @len: length of the string
 *
 * Return true if string is palindrome, false if not.
 */
bool check_palindrome(char *str, int si, int li, int len)
{

	if ((si >= (len / 2)) || (li <=(len / 2)))
		return true;

	if (str[si] != str[li])
		return false;

	return check_palindrome(str, ++si, --li, len);
}

int main(int argc, char *argv[])
{
	if (argc < 2) {
		printf("Enter a string to check if its palindrome or not\n");
		printf("Example: ./a.out string\n");
		return FAIL;
	}

	bool check = false;
	int len = strlen(argv[1]), start = 0, end = len - 1;

	check = check_palindrome(argv[1], start, end, len);

	if (check)
		printf("String is palindrome\n");
	else
		printf("String is not palindrome\n");

	return SUCCESS;
}
