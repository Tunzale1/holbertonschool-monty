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
