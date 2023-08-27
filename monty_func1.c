#include "monty.h"

void monty_sub(stack_t **stack, unsigned int line_number);
void monty_add(stack_t **stack, unsigned int line_number);
void monty_mul(stack_t **stack, unsigned int line_number);
void monty_div(stack_t **stack, unsigned int line_number);
void monty_mod(stack_t **stack, unsigned int line_number);

/**
 * monty_add - adds top two values of stack_t linked list
 * @stack: pointer to top mode node of stack_t linked list
 * @line_number: current working line number of Monty bytecodes file
 * Description: result stored in second value node from top and top value  is removed
 */

void monty_add(stack_t **stack, unsigned int line_number)
{
	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
	{
		set_op_tok_error(short_stack_error(line_number, "add"));
		return;
	}

	(*stack)->next->next->n += (*stack)->next->n;
	monty_pop(stack, line_number);
}

/**
 * monty_sub - subtracts second value from top of stack_t linked list by top value
 * @stack: pointer to top mode node of stack_t linked list
 * @line_number: current working line number of Monty bytecodes file
 * Description: result stored in second value node and top value is removed
 */

void monty_sub(stack_t **stack, unsigned int line_number)

{
	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
	{
		set_op_tok_error(short_stack_error(line_number, "sub"));
		return;
	}

	(*stack)->next->next->n -= (*stack)->next->n;
	monty_pop(stack, line_number);
}

/**
 * monty_div - divide second value from top of stack_t linked list by top value
 * @stack: pointer to top mode node of stack_t linked list
 * @line_number: current working line number of Monty bytecodes file
 * Description: result stored in second value node from top value removed
 */

void monty_div(stack_t **stack, unsigned int line_number)
{
	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
	{
		set_op_tok_error(short_stack_error(line_number, "div"));
		return;
	}

	if ((*stack)->next->n == 0)
	{
		set_op_tok_error(div_error(line_number));
		return;
	}

	(*stack)->next->next->n /= (*stack)->next->n;
	monty_pop(stack, line_number);
}

/**
 * monty_mul - multiply second value from top of stack_t linked list by top value
 * @stack: pointer to top mode node of stack_t linked list
 * @line_number: current working line number of Monty bytecodes file
 * Description: result stored in second value node from top and top value is removed
 */

void monty_mul(stack_t **stack, unsigned int line_number)

{
	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
	{
		set_op_tok_error(short_stack_error(line_number, "mul"));
		return;
	}

	(*stack)->next->next->n *= (*stack)->next->n;
	monty_pop(stack, line_number);
}

/**
 * monty_mod - computes modulus of second value from top of stack_t linked
 * list  by the top value
 * @stack: pointer to top mode node of stack_t linked list
 * @line_number: current working line number of  Monty bytecodes file
 * Description: result stored in second value node from the top and 
 * top value is removed
 */

void monty_mod(stack_t **stack, unsigned int line_number)
{
	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
	{
		set_op_tok_error(short_stack_error(line_number, "mod"));
		return;
	}

	if ((*stack)->next->n == 0)
	{
		set_op_tok_error(div_error(line_number));
		return;
	}

	(*stack)->next->next->n %= (*stack)->next->n;
	monty_pop(stack, line_number);
}
