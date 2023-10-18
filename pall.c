#include "monty.h"

/**
 * pall - prints all the values on the stack,
 * starting from the top of the stack
 * @stack: pointer to the top of the stack
 */
void pall(stack_t *stack)
{
	while (stack != NULL)
	{
		printf("%d\n", stack->n);
		stack = stack->next;
	}
}
