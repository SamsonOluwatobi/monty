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
 * add_node - adds a new node to the beginning of a stack
 * @stack: pointer to the stack
 * @n: value to be added to the stack
 *
 * Return: pointer to the new node, or NULL on failure
 */
stack_t *add_node(stack_t **stack, int n)
{
	stack_t *new_node;

	new_node = malloc(sizeof(stack_t));
	if (!new_node)
		return (NULL);

	new_node->n = n;
	new_node->prev = NULL;

	if (*stack)
		(*stack)->prev = new_node;

	new_node->next = *stack;
	*stack = new_node;

	return (new_node);
}

/**
 * delete_node - removes the top node from a stack
 * @stack: pointer to the stack
 */
void delete_node(stack_t **stack)
{
	stack_t *temp;

	if (!*stack)
		return;

	temp = *stack;
	*stack = (*stack)->next;

	if (*stack)
		(*stack)->prev = NULL;

	free(temp);
}

/**
 * stack_free - frees all nodes in a stack
 * @stack: pointer to the stack
 */
void stack_free(stack_t **stack)
{
	stack_t *current, *temp;

	if (!stack)
		return;

	current = *stack;

	while (current)
	{
		temp = current;
		current = current->next;
		free(temp);
	}

	*stack = NULL;
}

/**
 * is_comment - checks if a line is a comment
 * @line: line to be checked
 *
 * Return: 1 if the line is a comment, 0 otherwise
 */
int is_comment(char *line)
{
	if (!line)
		return (0);

	while (*line == ' ' || *line == '\t')
		line++;

	if (*line == '#')
		return (1);

	return (0);
}

/**
 * is_empty - checks if a line is empty
 * @line: line to be checked
 *
 * Return: 1 if the line is empty, 0 otherwise
 */
int is_empty(char *line)
{
	if (!line)
		return (1);

	while (*line == ' ' || *line == '\t')
		line++;

	if (*line == '\n' || *line == '\0')
		return (1);

	return (0);
}
