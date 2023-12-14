#include "monty.h"
/**
 * _pchar - prints top char
 * @stack: stack head
 * @line_number: line number
*/
void _pchar(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	temp = *stack;
	if (!temp)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_number);
		freeall();
		exit(EXIT_FAILURE);
	}
	if (temp->n > 127 || temp->n < 0)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", line_number);
		freeall();
		exit(EXIT_FAILURE);
	}
	printf("%c\n", temp->n);
	freeall();
}
