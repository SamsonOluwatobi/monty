#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <errno.h>
#include <stddef.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>


/**
* struct stack_s - doubly linked list representation of a stack (or queue)
* @n: integer
* @prev: points to the previous element of the stack (or queue)
* @next: points to the next element of the stack (or queue)
*
* Description: doubly linked list node structure
* for stack, queues, LIFO, FIFO
*/
typedef struct stack_s
{
		int n;

		struct stack_s *prev;
		struct stack_s *next;
} stack_t;
/**
* struct instruction_s - opcode and its function
* @opcode: the opcode
* @f: function to handle the opcode
*
* Description: opcode and its function
* for stack, queues, LIFO, FIFO
*/
typedef struct instruction_s
{
		char *opcode;

		void (*f)(stack_t **stack, unsigned int line_number);

} instruction_t;

/**
 * struct interpreter_s - struct for Monty interpreter
 * @arg: argument passed to interpreter
 * @file: file pointer for script file
 * @content: buffer for script file content
 * @lifi: line number of current instruction being executed
 *
 * Description: This struct defines a Monty interpreter and its properties.
 */
typedef struct interpreter_s
{
	char *arg;
	FILE *file;
	char *content;
	int lifi;
} interpreter_t;

extern interpreter_t interpreter;

void push(stack_t **stack, char *value, unsigned int line_number);
void pop(stack_t **stack, unsigned int line_number);
void pall(stack_t *stack);
int is_number(char *str);
void pint(stack_t *stack, unsigned int line_number);
void swap(stack_t **stack, unsigned int line_number);
void exe(char *opcode, stack_t **stack, char *value, unsigned int line_number);
void add(stack_t **stack, unsigned int line_number);
void nop(stack_t **stack, unsigned int line_number);





#endif
