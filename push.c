#include "monty.h"
/**
* push - Adds a new node at the beginning of a stack_t list
* @stack: Pointer to the head of the stack_t list
* @res: Value to be added to the new node
*/
void push(stack_t **stack, int res)
{
		stack_t *new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	new_node->n = res;
	new_node->next = *stack;
	*stack = new_node;
}
