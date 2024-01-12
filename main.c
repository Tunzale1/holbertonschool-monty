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
		dprintf(2, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while (getline(&buffer, &size, fd) != -1)
	{
		line_number++;
		input = substring(buffer, "\n\t\r ");
		if (input)
		{
			opcodef(input[0], &stack, line_number);
		}
		free(input);
	}

	free(buffer);
	freeStack(stack);
	fclose(fd);
	return(0);
}
