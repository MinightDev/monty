#include "monty.h"
/**
 * nop - Does nothing.
 * @stack: A pointer to the top of the stack (unused).
 * @line_number: The current line number in the Monty bytecode file (unused).
 * @op_arg: A string representing the argument (unused).
 */
void nop(stack_t **stack, unsigned int line_number, char *op_arg)
{
	(void)stack;
	(void)line_number;
	(void)op_arg;
}
