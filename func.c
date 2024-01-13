#include "monty.h"

/**
 * pint - Prints the first node of the stack
 * @stack: Stack of nodes
 * @line_number: Line where the instruction is located
 */

void pint(stack_t **stack, unsigned int line_number)
{
	if (!stack || !*stack)
	{
		dprintf(2, "L%i: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}

	printf("%d\n", (*stack)->n);
}

/**
 * pop- Removes the top element of the stack
 * @stack: Stack of nodes
 * @line_number: Line where the instruction is located
 */

void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *aux = *stack;

	if (!*stack || !stack)
	{
		dprintf(2, "L%i: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}

	if ((*stack)->next != NULL)
	{
		*stack = aux->next;
		(*stack)->prev = NULL;
		free(aux);
	}
	else
	{
		free(*stack);
		*stack = NULL;
	}
}

