#include "monty.h"
/**
 * freeStack - using for free stack
 * @stack: stack
 */
void freeStack(stack_t *stack)
{
	stack_t *aux;

	while (stack != NULL)
	{
		aux = stack->next;
		free(stack);
		stack = aux;
	}
}
