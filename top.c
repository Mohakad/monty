#include "monty.h"
/**
 * pop- removes the top element of the stack
 * @stack: dat
 * @line_number: line no
 */
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *tempo;

	if (stack == NULL || *stack == NULL)
	{	
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		freeall();
		exit(EXIT_FAILURE);
	}
	tempo = *stack;
	*stack = tempo->next;
	if (*stack != NULL)
		(*stack)->prev = NULL;
	free(tempo);
}
