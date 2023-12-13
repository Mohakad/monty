#include "monty.h"
/**
 * pint - pint top
 * @stack: top data
 * @line_number: line number.
 */
void pint(stack_t **stack, unsigned int line_number)
{
	if (stack == NULL || *stack == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		freeall();
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}
