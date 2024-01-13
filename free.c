#include "monty.h"
/**
 * freeStack - using for free stack
 * @stack: stack
 */
void freeStack(stack_t *stack)
{
	stack_t *tempo;

	while (stack != NULL)
	{
		tempo = stack->next;
		free(stack);
		stack = tempo;
	}
}
