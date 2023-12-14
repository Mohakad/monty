#include "monty.h"
/**
 * div_two - devide top 2
 * @stack: the top
 * @line_number: line no
 */
void div_two(stack_t **stack, unsigned int line_number)
{
	int div;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", line_number);
		freeall();
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		freeall();
		exit(EXIT_FAILURE);
	}
	(*stack) = (*stack)->next;
	div = (*stack)->n / (*stack)->prev->n;
	(*stack)->n = div;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}
/**
 * add_two - add top 2
 * @stack: the top
 * @line_number: line no
 */
void add_two(stack_t **stack, unsigned int line_number)
{
	int add;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		freeall();
		exit(EXIT_FAILURE);
	}

	(*stack) = (*stack)->next;
	add = (*stack)->n + (*stack)->prev->n;
	(*stack)->n = add;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}
/**
 *sub - sub top 2
 *@stack: the top
 *@line_number: line no
 */
void sub(stack_t **stack, unsigned int line_number)
{
	int sub;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
		freeall();
		exit(EXIT_FAILURE);
	}
	(*stack) = (*stack)->next;
	sub = (*stack)->n - (*stack)->prev->n;
	(*stack)->n = sub;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}
