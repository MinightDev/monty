#include "monty.h"
/**
 * main - Entry point for the Monty bytecode interpreter
 * @argc: The number of command-line arguments
 * @argv: An array of command-line argument strings
 *
 * Return: EXIT_SUCCESS if successful, EXIT_FAILURE on failure
 */
instruction_t opcodes[] = {
    {"push", push},
    {"pall", pall},
    {"pint", pint},
    {"pop", pop},
    {"swap", swap},
    {"add", add},
    {"nop", nop},
    {NULL, NULL}
};
int main(int argc, char *argv[])
{
	FILE *file;
	stack_t *stack;
	unsigned int line_number = 0;
	char *opcode, *op_arg, *line;
	int i;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	file = fopen(argv[1], "r");
	if (!file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	stack = NULL;

	while (1)
	{
		line = malloc(MAX_LINE_LENGTH);
		if (!line)
		{
			perror("Error allocating memory for line");
			exit(EXIT_FAILURE);
		}

		if (fgets(line, MAX_LINE_LENGTH, file) == NULL)
		{
			free(line);
			break;
		}
		line_number++;
		opcode = strtok(line, " \t\n");
		op_arg = strtok(NULL, " \t\n");

		if (opcode != NULL)
		{
			i = 0;
			while (opcodes[i].opcode != NULL)
			{
				if (strcmp(opcode, opcodes[i].opcode) == 0)
				{
					opcodes[i].f(&stack, line_number, op_arg);
					break;
				}
				i++;
			}
			if (opcodes[i].opcode == NULL)
			{
				fprintf(stderr, "L%u: unknown instruction %s\n", line_number, opcode);
				free_stack(stack);
				free(line);
				fclose(file);
				exit(EXIT_FAILURE);
			}
		}

		free(line);
	}
	free_stack(stack);
	fclose(file);
	return (EXIT_SUCCESS);
}
