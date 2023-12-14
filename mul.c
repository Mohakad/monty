#include "monty.h"
/**
 *mul_two- multiplies 2
 *@stack: stack head
 *@line_number: line number
*/
void mul_two(stack_t **stack, unsigned int line_number)
{
	stack_t *head;
	int mul;
	head = *stack;
	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
		freeall();
		exit(EXIT_FAILURE);
	}
	mul = head->next->n * head->n;
	head->next->n = mul;
	*stack = head->next;
	free(head);
}
