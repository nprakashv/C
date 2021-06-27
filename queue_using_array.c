#include <stdio.h>
#include "common.h"

#define BUF_SIZE	1024

/* Structure representing fifo */
struct fifo {
	char buffer[BUF_SIZE];	// Represents fifo of size BUF_SIZE
	int wp;			// Write pointer
	int rp;			// Read pointer
};

static struct fifo *fifo = NULL;

/* Function to check if fifo is full or not */
int fifo_full()
{
	if (fifo) {
		if (fifo->wp == (BUF_SIZE - 1))
			return 1;
		else
			return 0;
	}

	return -1;
}

/* Function to check if fifo is empty or not */
int fifo_empty()
{
	if (fifo) {
		if (fifo->wp == fifo->rp)
			return 1;
		else
			return 0;
	}

	return -1;
}

/* Function to push data to queue */
void enqueue(char data)
{
	fifo->buffer[fifo->wp] = data;
	++fifo->wp;
}

/* Function to get data from queue */
char dequeue()
{
	return fifo->buffer[fifo->rp++];
}

int main(int argc, char *argv[])
{
	if (argc < 2) {
		printf("Enter the data(character) to be pushed to the"
			" queue, minimum one required\n");
		printf("example: ./a.out data1\n");
		return FAIL;
	}

	/* allocate fifo and set rp, wp to zero */
	fifo = (struct fifo *)malloc(sizeof(struct fifo));
	if (!fifo) {
		printf("Memory allocation for fifo failed\n");
		return FAIL;
	}
	fifo->wp = 0;
	fifo->rp = 0;

	int num = argc - 1, i;
	char data[num], val;

	/* Read the user input */
	for (i = 0; i < num; i++)
		data[i] = *(argv[i + 1]);

	/* push the data to queue */
	i = 0;
	while (!fifo_full() && i < num) {
		enqueue(data[i]);
		++i;
	}

	/* read the data from queue */
	while (!fifo_empty()) {
		val = dequeue();
		printf("Data read from fifo %c\n", val);
	}

	free(fifo);
	return SUCCESS;
}
