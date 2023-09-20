#include "monty.h"
/**
 * process_file - Process a Monty bytecode file.
 * @filename: The name of the Monty bytecode file to process.
 * @opcodes: An array of opcode structures containing valid operations.
 */
void process_file(const char *filename, instruction_t opcodes[])
{
	FILE *file;
	stack_t *stack = NULL;
	unsigned int line_number = 0;
	char *line = NULL;
	char *opcode, *op_arg;
	int i;

	file = fopen(filename, "r");
	if (!file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", filename);
		exit(EXIT_FAILURE);
	}
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
}
