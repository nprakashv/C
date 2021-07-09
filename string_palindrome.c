#include "common.h"

/* Function to check if string is palindrome or not.
 * @str: pointer to the string to be checked.
 *
 * Return true if string is palindrome, false if not.
 */
bool check_palindrome(char *str)
{

	int len = strlen(str), i = 0;

	while (i < (len / 2)) {
		if (str[i] != str[len - i - 1])
			return false;
		++i;
	}

	return true;
}

int main(int argc, char *argv[])
{
	if (argc < 2) {
		printf("Enter a string to check if its palindrome or not\n");
		printf("Example: ./a.out string\n");
		return FAIL;
	}

	bool check = false;

	check = check_palindrome(argv[1]);

	if (check)
		printf("String is palindrome\n");
	else
		printf("String is not palindrome\n");

	return SUCCESS;
}
