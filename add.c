#include "monty.h"
/**
 * nod - new node
 * @n: value
 * Return: nod
 */
stack_t *nod(int n)
{
	stack_t *node;

	node = malloc(sizeof(stack_t));
	if (node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
			freeall();
			exit(EXIT_FAILURE);
	}
	node->next = NULL;
	node->prev = NULL;
	node->n = n;
	return (node);
}
/**
 *ad_q - Addsnode
 *@ad_nd: new node
 *@ln: line number
 */
void ad_q(stack_t **ad_nd, __attribute__((unused))unsigned int ln)
{
	stack_t *tmp;


	if (ad_nd == NULL || *ad_nd == NULL)
		exit(EXIT_FAILURE);
	if (head == NULL)
	{
		head = *ad_nd;
		return;
	}
	tmp = head;
	while (tmp->next != NULL)
		tmp = tmp->next;

	tmp->next = *ad_nd;
	(*ad_nd)->prev = tmp;
}
