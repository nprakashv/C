#include "common.h"

/* Function to implement strstr
 *
 * @main: main string which should be traversed
 * @sub: substring to be searched for
 *
 * Returns pointer to the firt occurance of sub if present, else NULL
 */
char *strstr_imp(char *main, char *sub)
{
	int i = 0, j = 0, check  = 0;

	while (*(main + i) != '\0') {

		if (*(main + i) == *sub) {
			for ( j = 0; j < strlen(sub); j++) {
				if (*(main + i + j) == *(sub + j)) {
					check  = 1;
				} else {
					check = 0;
					break;
				}
			}

			if (check == 1)
				return (main + i);
		}
		++i;
	}

	return NULL;
}

int main(int argc, char *argv[])
{
	if (argc < 3) {
		printf("Enter the main string and sub string\n");
		printf("Example: ./a.out 'main_string' 'sub_string'\n");
		return FAIL;
	}

	char *sub = NULL;

	sub = strstr_imp(argv[1], argv[2]);

	if (sub)
		printf("'%s' present in '%s'\n", argv[2], argv[1]);
	else
		printf("'%s' not present in '%s'\n", argv[2], argv[1]);

	return SUCCESS;
}
