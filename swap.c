#include "monty.h"
/**
 *swp - swap 2 elementstack
 *@stack: top
 *@line_number: line no
 */
void swp(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if ((*stack)->next == NULL || *stack == NULL || stack == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		freeall();
		exit(EXIT_FAILURE);
	}
	temp = (*stack)->next;
	(*stack)->next = temp->next;
	if (temp->next != NULL)
		temp->next->prev = *stack;
	temp->next = *stack;
	(*stack)->prev = temp;
	temp->prev = NULL;
	*stack = temp;
}
