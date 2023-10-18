#include "monty.h"

int main(int argc, char *argv[])
{
    char *filename;
	stack_t *stack = NULL;
	char operation[256];
	int value;
    FILE *file;

	if (argc != 2)
    {
		fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
		return (EXIT_FAILURE);
	}

	filename = argv[1];

	file = fopen(filename, "r");
	if (file == NULL) {
		fprintf(stderr, "Error: Can't open file %s\n", filename);
		return (EXIT_FAILURE);
	}

	while (fscanf(file, "%255s", operation) != EOF)
    {
		if (strcmp(operation, "push") == 0)
        {
			fscanf(file, "%d", &value);
			push(&stack, value);
		} else if (strcmp(operation, "pall") == 0)
        {
			pall(stack);
		} else
        {
			fprintf(stderr, "Unknown operation: %s\n", operation);
			fclose(file);
			return (EXIT_FAILURE);
		}
	}

	fclose(file);

	while (stack != NULL)
    {
		stack_t *temp = stack;

		stack = stack->next;
		free(temp);
	}

	return (0);
}

