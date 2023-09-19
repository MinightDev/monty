#include "monty.h"
/**
 * pall - Prints all elements of the stack.
 * @stack: A pointer to the top of the stack.
 * @line_number: The current line number in the Monty bytecode file (unused).
 * @op_arg: A string representing the argument (unused).
 */
void pall(stack_t **stack, unsigned int line_number, char *op_arg)
{
	stack_t *current = *stack;
	(void)line_number;
	(void)op_arg;

	while (current)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}
