#include "monty.h"

/**
* pstr - Prints the string starting at
* the top of the stack, followed by a new line.
* @stack: Double pointer to the head of the stack.
* @line_number: Line number of the opcode in the Monty file.
*/
void pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;

	(void)line_number;

	while (current != NULL && current->n != 0 && current->n
	>= 0 && current->n <= 127)
	{
		putchar(current->n);
		current = current->next;
	}

	putchar('\n');
}
/**
 * rotl - Rotates the stack to the top.
 * @stack: A pointer to the top of the stack.
 * @line_number: The current line number in the Monty file.
 *
 * Return: None.
 */
void rotl(stack_t **stack, unsigned int line_number)
{
	stack_t *last = *stack;

	(void)line_number;

	if (*stack == NULL || (*stack)->next == NULL)
		return;

	while (last->next != NULL)
		last = last->next;

	last->next = *stack;
	*stack = (*stack)->next;
	last->next->next = NULL;
}
/**
 * rotr - Rotates the stack to the bottom.
 * @stack: A pointer to the top of the stack.
 * @line_number: The current line number in the Monty file.
 *
 * Return: None.
 */
void rotr(stack_t **stack, unsigned int line_number)
{
	stack_t *last = *stack;
	stack_t *second_last = NULL;

	(void)line_number;

	if (*stack == NULL || (*stack)->next == NULL)
		return;

	while (last->next != NULL)
	{
		second_last = last;
		last = last->next;
	}

	second_last->next = NULL;
	last->next = *stack;
	*stack = last;
}
