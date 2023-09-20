#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/types.h>
#define MAX_LINE_LENGTH 1024

typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number, char *op_arg);
} instruction_t;

/* Function prototypes */
void push(stack_t **stack, unsigned int line_number, char *op_arg);
void pall(stack_t **stack, unsigned int line_number, char *op_arg);
void pint(stack_t **stack, unsigned int line_number, char *op_arg);
void pop(stack_t **stack, unsigned int line_number, char *op_arg);
void swap(stack_t **stack, unsigned int line_number, char *op_arg);
void add(stack_t **stack, unsigned int line_number, char *op_arg);
void nop(stack_t **stack, unsigned int line_number, char *op_arg);
void process_file(const char *filename, instruction_t opcodes[]);
int main(int argc, char *argv[]);
void free_stack(stack_t *stack);

#endif
