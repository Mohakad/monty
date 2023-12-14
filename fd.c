#include "monty.h"
/**
 *f_opn- file opner
 *@name: file name
 */
void f_opn(char *name)
{
	FILE *fd = fopen(name, "r");

	if (name == NULL || fd == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", name);
			freeall();
			exit(EXIT_FAILURE);
	}
	fl_read(fd);
	fclose(fd);
}
/**
 * fl_read - reads a file
 * @fd: descriptor
 */
void fl_read(FILE *fd)
{
	int line_number, format = 0;

	char *buffer = NULL;

	size_t len = 0;

	for (line_number = 1; getline(&buffer, &len, fd) != -1; line_number++)
		format = toknizz(buffer, line_number, format);
	free(buffer);
}
/**
 *finder- look for func
 *@opc: opcode
 *@value: argument
 *@format: struct or qu
 * @ln: line num
 */
void finder(char *opc, char *value, int ln, int format)
{
	int i, fl;

	instruction_t func_list[] = {
		{"push", add_st},
		{"pall", _pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swp},
		{"add", add_two},
		{NULL, NULL}
	};

	if (opc[0] == '#')
		return;

	for (fl = 1, i = 0; func_list[i].opcode != NULL; i++)
	{
		if (strcmp(opc, func_list[i].opcode) == 0)
		{
			exec(func_list[i].f, opc, value, ln, format);
			fl = 0;
		}
	}
	if (fl == 1)
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", ln, opc);
		freeall();
			exit(EXIT_FAILURE);
	}
}
