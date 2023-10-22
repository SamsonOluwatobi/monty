#include "monty.h"
/**
* exe - execute opcode
* @opcode: opcode to execute
* @stack: pointer to the top of the stack
* @value: value to push onto stack
* @line_number: line number of opcode
*
* Return: 0 on success, -1 on failure
*/
void exe(char *opcode, stack_t **stack, char *value, unsigned int line_number)
{
	if (strcmp(opcode, "push") == 0 && value)
		push(stack, value, line_number);
	else if (strcmp(opcode, "pall") == 0)
		pall(*stack);
	else if (strcmp(opcode, "pop") == 0)
		pop(stack, line_number);
	else if (strcmp(opcode, "pint") == 0)
		pint(*stack, line_number);
	else if (strcmp(opcode, "swap") == 0)
		swap(stack, line_number);
	else if (strcmp(opcode, "add") == 0)
		add(stack, line_number);
	else if (strcmp(opcode, "nop") == 0)
		nop(stack, line_number);
	else if (strcmp(opcode, "sub") == 0)
		sub(stack, line_number);
	else if (strcmp(opcode, "div") == 0)
		_div(stack, line_number);
	else if (strcmp(opcode, "mul") == 0)
		mul(stack, line_number);
	else if (strcmp(opcode, "mod") == 0)
		mod(stack, line_number);
	else if (strcmp(opcode, "pchar") == 0)
		pchar(stack, line_number);
	else if (strcmp(opcode, "pstr") == 0)
		pstr(stack, line_number);
	else
	{
		fprintf(stderr, "L%u: unknown instruction %s\n", line_number, opcode);
		exit(EXIT_FAILURE);
	}
}
