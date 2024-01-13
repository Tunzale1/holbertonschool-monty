#include "monty.h"

void opcodef(char *buffer, stack_t **stack, unsigned int line_number)
{
	size_t i;
	instruction_t ops[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
                {"pop", pop},
		{"swap", swap},
                {"add", add},
		{"nop", nop},
		{NULL, NULL}
	};
	for (i = 0; ops[i].opcode != NULL; i++)
	{
		if (strcmp(ops[i].opcode, buffer) == 0)
		{
			ops[i].f(stack, line_number);
			return;
		}
	}
	dprintf(2, "L%i: unknown instruction %s\n", line_number, buffer);
	exit(EXIT_FAILURE);
}





/*Splits a string into substrings based on a given separator
 */
char **substring(char *string, char *separat)
{
	int i = 0, j = 0;
	char *temp, **array;

	array = (char **)calloc(100, sizeof(char *));

	if (!array)
	{
		free(array);
		dprintf(2, "Error: calloc failed\n");
		exit(EXIT_FAILURE);
	}

	while (string[i])
		i++;
	while ((temp = strtok(string, separat)) != NULL)
	{
		array[j] = temp;
		string = NULL;
		j++;
	}
	return (array);
}
