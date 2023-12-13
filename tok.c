#include "monty.h"
/**
 *toknizz - line to tokens
 *@buf: file line
 *@ln: line number
 *@format:  storage format
 *Return: 0 or 1
 */
int toknizz(char *buf, int ln, int format)
{
	char *opc, *value;

	const char *delim = "\n ";

	if (buf == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
			freeall();
			exit(EXIT_FAILURE);
	}
	opc = strtok(buf, delim);
	if (opc == NULL)
		return (format);
	value = strtok(NULL, delim);
	if (strcmp(opc, "stack") == 0)
		return (0);
	if (strcmp(opc, "queue") == 0)
		return (1);
	finder(opc, value, ln, format);
	return (format);
}
/**
 * exec - calls func
 * @func: the func
 * @op: opcode
 * @val: value
 * @ln: line
 * @format: the format
 */
void exec(funct func, char *op, char *val, int ln, int format)
{
	stack_t *node;

	int i, flag;

	flag = 1;
	if (strcmp(op, "push") == 0)
	{
		if (val != NULL && val[0] == '-')
		{
			val = val + 1;
			flag = -1;
		}
		if (val == NULL)
		{
			fprintf(stderr, "L%d: usage: push integer\n", ln);
			freeall();
			exit(EXIT_FAILURE);
		}
		for (i = 0; val[i] != '\0'; i++)
		{
			if (isdigit(val[i]) == 0)
			{
				fprintf(stderr, "L%d: usage: push integer\n", ln);
			freeall();
			exit(EXIT_FAILURE);
			}
		}
		node = nod(atoi(val) * flag);
		if (format == 0)
			func(&node, ln);
		if (format == 1)
			ad_q(&node, ln);
	}
	else
		func(&head, ln);
}
