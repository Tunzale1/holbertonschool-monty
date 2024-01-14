#include "monty.h"

/**
 * pall - prints all the values on the stack, starting from
 * the top of the stack
 * @stack: Stack of nodes
 * @line_number: Current line number
 */
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;  // Use a separate pointer to iterate through the stack

	(void)(line_number);

	while (current)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}

/**
 * push - pushes an element to the stack.
 * @stack: Stack of nodes
 * @line_number: Current line number
 */
void push(stack_t **stack, unsigned int line_number)
{
	stack_t *aux = NULL;
	int integer;

	if (input[1] == NULL)
	{
		dprintf(2, "L%i: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}

	integer = atoi(input[1]);
	if (integer == 0 && input[1][0] != '0')
	{
		dprintf(2, "L%i: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}

	aux = malloc(sizeof(stack_t));
	if (aux == NULL)
	{
		dprintf(2, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	aux->n = integer;
	aux->prev = NULL;
	aux->next = *stack;

	if (*stack != NULL)
	(*stack)->prev = aux;
	*stack = aux;
}
