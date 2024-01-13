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

/**
 * swap - Swaps the top two elements of the stack
 * @stack: Stack of nodes
 * @line_number: Line where the instruction is located
 */

void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *head = *stack;
	stack_t *aux = *stack;

	if (!*stack || !stack || !head->next)
	{
		dprintf(2, "L%i: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	head = head->next;
	head->prev = NULL;

	aux->next = head->next;
	head->next = aux;
	(head->next)->prev = head;

	*stack = head;
}

/**
 * add - Adds the top two elements of the stack
 * @stack: Stack of nodes
 * @line_number: Line where the instruction is located
 */

void add(stack_t **stack, unsigned int line_number)
{
	stack_t *aux = *stack;

	if (!*stack || !stack || !aux->next)
	{
		dprintf(2, "L%i: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	(aux->next)->n += aux->n;
	pop(&aux, line_number);

	*stack = aux;
}
