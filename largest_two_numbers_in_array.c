#include <stdio.h>
#include "common.h"

struct largest {
	int l1;
	int l2;
};

struct largest *getlargest(int *p, int cnt)
{
	int largest1 = p[0], largest2 = p[1], i = 0;

	if (largest2 > largest1) {
		int tmp;
		tmp = largest1;
		largest1 = largest2;
		largest2 = tmp;
	}

	for (i = 2; i < cnt; i++) {
		if (p[i] > largest1) {
			largest2 = largest1;
			largest1 = p[i];
		} else if (p[i] > largest2)
			largest2 = p[i];
	}

	struct largest *ptr = (struct largest *)malloc(sizeof(struct largest));
	ptr->l1 = largest1;
	ptr->l2 = largest2;

	return ptr;
}

int main(int argc, char *argv[])
{
	if (argc < 3) {
		printf("Enter array elements, minimum two elements required\n");
		printf("example: ./a.out elem1 elem2...\n");
		return FAIL;
	}
	
	int cnt = argc - 1, i;
	int array[cnt];

	for (i = 0; i < cnt; i++)
	       array[i] = atoi(argv[i + 1]);

	struct largest *ptr = NULL;	

	ptr = getlargest(array, cnt);

	if (ptr)
		printf("Largest two elements are %d and %d\n", ptr->l1, ptr->l2);
	else
		return FAIL;

	free(ptr);

	return SUCCESS;
}
