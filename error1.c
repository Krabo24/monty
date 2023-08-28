#include "monty.h"

int short_stack_error(unsigned int line_number, char *op);
int pop_error(unsigned int line_number);
int div_error(unsigned int line_number);
int div_error(unsigned int line_number);
int pchar_error(unsigned int line_number, char *message);

/**
 * pop_error - print the pop error messages for the empty stacks
 * @line_number: the line number in the script where error the occured
 * Return: (EXIT_FAILURE) always
 */

int pop_error(unsigned int line_number)

{
	fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
	return (EXIT_FAILURE);
}

/**
 * pint_error - print the pint error messages for the empty stacks
 * @line_number: the line number in Monty bytecodes file where
 * the error occured
 * Return: (EXIT_FAILURE) always
 */

int pint_error(unsigned int line_number)

{
	fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
	return (EXIT_FAILURE);
}

/**
 * short_stack_error - print the monty maths function for the error messages
 * error message for stacks and queues that are smaller than two nodes
 * @line_number: line number in Monty bytecodes file where the error occurred
 * @op: operation where the error occurred
 * Return: (EXIT_FAILURE) always
 */

int short_stack_error(unsigned int line_number, char *op)

{
	fprintf(stderr, "L%u: can't %s, stack too short\n", line_number, op);
	return (EXIT_FAILURE);
}

/**
 * div_error - print the division error messages for the division by 0
 * @line_number: line number in Monty bytecodes file where the error occurred
 * Return: (EXIT_FAILURE) always
 */

int div_error(unsigned int line_number)

{
	fprintf(stderr, "L%u: division by zero\n", line_number);
	return (EXIT_FAILURE);
}

/**
 * pchar_error - print the pchar error message for the empty stacks
 * and the non-character values
 * @line_number: the line number in Monty bytecodes file where error occurred
 * @message: corresponding error message to print
 * Return: (EXIT_FAILURE) always
 */

int pchar_error(unsigned int line_number, char *message)

{
	fprintf(stderr, "L%u: can't pchar, %s\n", line_number, message);
	return (EXIT_FAILURE);
}
