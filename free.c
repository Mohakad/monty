#include "monty.h"
/**
 *freeall - free node
 */
void freeall(void)
{
	stack_t *tmp;

	if (head == NULL)
		return;
	while (head != NULL)
	{
		tmp = head;
		head = head->next;
		free(tmp);
	}
}
