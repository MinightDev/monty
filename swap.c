#include "monty.h"
/**
 * swap - Swaps the top two elements of the stack.
 * @stack: A pointer to the top of the stack.
 * @line_number: The current line number in the Monty bytecode file.
 * @op_arg: A string representing the argument (unused in this function).
 */
void swap(stack_t **stack, unsigned int line_number, char *op_arg)
{
	stack_t *temp;

	(void)op_arg;

	if (!stack || !*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	temp = (*stack)->next;

	(*stack)->next = temp->next;
	if (temp->next)
	{
		temp->next->prev = *stack;
	}

	temp->prev = NULL;
	temp->next = *stack;
	(*stack)->prev = temp;
	*stack = temp;
}
