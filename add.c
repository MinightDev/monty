#include "monty.h"
/**
 * add - Adds the top two elements of the stack.
 * @stack: A pointer to the top of the stack.
 * @line_number: The current line number in the Monty bytecode file.
 * @op_arg: A string representing the argument (unused in this function).
 */
void add(stack_t **stack, unsigned int line_number, char *op_arg)
{
	(void)op_arg;

	if (!stack || !*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	(*stack)->next->n += (*stack)->n;
	pop(stack, line_number, op_arg);
}
