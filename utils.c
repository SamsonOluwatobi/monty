#include "monty.h"
/**
 * is_number - checks if a string is a valid integer
 * @str: string to be checked
 *
 * Return: 1 if the string is a valid integer, 0 otherwise
 */
int is_number(char *str)
{
	if (!str)
		return (0);

	if (*str == '-')
		str++;

	if (!*str)
		return (0);

	while (*str)
	{
		if (*str < '0' || *str > '9')
			return (0);
		str++;
	}

	return (1);
}


/**
 * swap - swaps the top two elements of the stack
 * @stack: pointer to the stack
 * @line_number: line number of the command being executed
 *
 * Return: void
 */
void swap(stack_t **stack, unsigned int line_number)
{
	int temp;

	if (!*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	temp = (*stack)->n;
	(*stack)->n = (*stack)->next->n;
	(*stack)->next->n = temp;
}
