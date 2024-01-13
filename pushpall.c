#include "monty.h"
/**
 * pall - prints all the values on the stack, starting from
 * the top of the stack
 * @stack: Stack of nodes
 * @line_number: Current line number
 */
void pall(stack_t **stack, unsigned int line_number)
{
	(void)(line_number);

	while (*stack)
	{
		printf("%d\n", (*stack)->n);
		stack = &(*stack)->next;
	}
}

/**
 * push - pushes an element to the stack.
 * @stack: Stack of nodes
 * @line_number: Current line number
 */

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
