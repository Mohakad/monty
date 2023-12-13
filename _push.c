#include "monty.h"
/**
 *add_st - ad stack
 *@new_node: new nd
 *@ln: line no
 */
void add_st(stack_t **new_node, __attribute__((unused))unsigned int ln)
{

	stack_t *tmp;

	if (new_node == NULL || *new_node == NULL)
		exit(EXIT_FAILURE);
	if (head == NULL)
	{
		head = *new_node;
		return;
	}
	tmp = head;
	head = *new_node;
	head->next = tmp;
	tmp->prev = head;
}
