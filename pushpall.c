#include "monty.h"
/**
 * pall - prints all the values on the stack, starting from
 * the top of the stack
 * @stack: Stack of nodes
 * @line_number: Current line number
 */
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *node;
	(void)line_number;

	node = *stack;
	while (node)
	{
		printf("%d\n", node->n);
		node = node->next;
	}
}

/**
 * push - pushes an element to the stack.
 * @stack: Stack of nodes
 * @line_number: Current line number
 */

void push(stack_t **stack, unsigned int line_number)
{

	stack_t *node = malloc(sizeof(stack_t));

	if (!node)
	{
		fprintf(stderr, "Error: malloc failed\n");
		freeStack(*stack);
		exit(EXIT_FAILURE);
	}
	node->n = line_number;
	node->next = *stack;
	node->prev = NULL;

	if (*stack)
		(*stack)->prev = node;
	*stack = node;
}
