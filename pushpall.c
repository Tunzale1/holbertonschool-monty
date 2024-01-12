#include "monty.h"

void pall(stack_t **stack, unsigned int line_number)
{
	(void)(line_number);

	while (*stack)
	{
		printf("%d\n", (*stack)->n);
		stack = &(*stack)->next;
	}
}





void push(stack_t **stack, unsigned int line_number)
{
	stack_t *tempo = NULL;
	int m;

	tempo = malloc(sizeof(stack_t));
	if (tempo == NULL)
	{
		free(tempo);
		dprintf(2, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	m = atoi(input[1]);
	if (m == 0)
	{
		dprintf(2, "L%i: usage: push integer\n", line_number);
		free(tempo);
		exit(EXIT_FAILURE);
	}

	tempo->n = m;
	tempo->prev = NULL;
	tempo->next = *stack;

	if (*stack != NULL)
		(*stack)->prev = tempo;
	*stack = tempo;
}
