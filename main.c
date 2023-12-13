#include "monty.h"
stack_t *head = NULL;
/**
 * main - main
 * @argc: argc
 * @argv: argv
 * Return: 0
 */
int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	f_opn(argv[1]);
	freeall();
	return (0);
}
