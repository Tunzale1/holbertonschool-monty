#include "monty.h"

int main(int argc, char **argv)
{
	size_t size = 0;
	stack_t *stack = NULL;
	char *buffer;
	unsigned int line_number = 0;
	FILE *fd;

	if (argc != 2)
	{
		dprintf(2, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	fd = fopen(argv[1], "r+");

	if (!fd)
	{
		dprintf(2, "Error: Can't open file\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	free(buffer);
	fclose(fd);
	return(0);
}
