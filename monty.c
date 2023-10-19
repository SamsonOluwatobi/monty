#include "monty.h"
#include <stdio.h>
#include <stdlib.h>
/**
 * main - entry point for the Monty bytecode interpreter
 * @argc: number of command-line arguments
 * @argv: array of command-line arguments
 *
 * Return: 0 on success, non-zero on failure
 */
int main(int argc, char *argv[])
{
	char *filename, *opcode, *value;
	char line[1024];
	unsigned int line_number = 0;
	stack_t *stack = NULL;
	FILE *fp;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	filename = argv[1];
	fp = fopen(filename, "r");

	if (!fp)
	{
		fprintf(stderr, "Error: Can't open file %s\n", filename);
		exit(EXIT_FAILURE);
	}

	while (fgets(line, sizeof(line), fp))
	{
		line_number++;
		opcode = strtok(line, " \t\n");
		value = strtok(NULL, " \t\n");

		if (opcode && opcode[0] != '#')
		{
			exe(opcode, &stack, value, line_number);
		}
	}

	fclose(fp);
	return (0);
}
