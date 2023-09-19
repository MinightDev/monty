#include "monty.h"
/**
 * pint - Prints the value at the top of the stack.
 * @stack: A pointer to the top of the stack.
 * @line_number: The current line number in the Monty bytecode file.
 * @op_arg: A string representing the argument (unused).
 */
void pint(stack_t **stack, unsigned int line_number, char *op_arg)
{
	(void)op_arg;

	if (!stack || !*stack)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}

	printf("%d\n", (*stack)->n);
}
