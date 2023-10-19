#include "monty.h"
/**
 * push - pushes an element to the stack
 * @stack: pointer to the stack
 * @value: value to be pushed onto the stack
 * @line_number: line number of the instruction
 */
void push(stack_t **stack, char *value, unsigned int line_number)
{
	int n = atoi(value);
	stack_t *new_node = malloc(sizeof(stack_t));

	if (!is_number(value))
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	if (!new_node)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	new_node->n = n;
	new_node->prev = NULL;

	if (*stack)
		(*stack)->prev = new_node;

	new_node->next = *stack;
	*stack = new_node;
}
/**
 * pop - removes the top element of the stack
 * @stack: pointer to the stack
 * @line_number: line number of the instruction
 */
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if (!*stack)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}

	temp = *stack;
	*stack = (*stack)->next;

	if (*stack)
		(*stack)->prev = NULL;

	free(temp);
}
